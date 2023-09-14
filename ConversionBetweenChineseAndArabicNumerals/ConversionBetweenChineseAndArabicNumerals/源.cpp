#include <iostream>
#include <string>
#include<map>
using namespace std;
string Trans(string str) {
	string result = "";
	//����������ת��Ϊ��������
	if (str[0] >= '0' && str[0] <= '9') {
		int num = stoi(str);
		if (num == 0) {
			return "��";
		}

		string chineseNumbers[] = { "��", "һ", "��", "��", "��", "��", "��", "��", "��", "��" };
		string unit[] = { "", "ʮ", "��", "ǧ" };
		string bigUnit[] = { "��", "��", "����" };
		string result = "";

		int unitIndex = 0;
		int bigUnitIndex = 0;
		bool needZero = false;

		bool needBigUnit = false;

		while (num > 0) {
			int digit = num % 10;

			if (digit == 0) {
				if (needZero) {
					result = chineseNumbers[0] + result;
					needZero = false;
				}
			}
			else {
				if (unitIndex == 4) {
					needBigUnit = true;
					unitIndex = 0;
				}

				if (needBigUnit) {
					result = bigUnit[bigUnitIndex] + result;
					needBigUnit = false;
					bigUnitIndex++;
				}

				result = chineseNumbers[digit] + unit[unitIndex] + result;
				needZero = true;
			}

			num /= 10;
			unitIndex++;
		}

		return result;
	}

	//��������ת��Ϊ����������
	else if (str[0] == 'һ' || str[0] == '��' || str[0] || '��' && str[0] == '��' || str[0] == '��' || str[0] == '��' || str[0] == '��' || str[0] == '��' || str[0] == '��' || str[0] == 'ʮ' || str[0] == '��')
	{
		map<char, int> chineseDigitMap = {
		{'��', 0}, {'һ', 1}, {'��', 2}, {'��', 3}, {'��', 4},
		{'��', 5}, {'��', 6}, {'��', 7}, {'��', 8}, {'��', 9}
		};


		int res = 0;
		int currentNumber = 0;

		for (char c : str) {
			if (c == '��') {
				result += currentNumber * 100000000;
				currentNumber = 0;

			}
			else if (c == '��') {
				res += currentNumber * 10000;
				currentNumber = 0;

			}
			else {
				currentNumber = currentNumber * 10 + chineseDigitMap[c];
			}

		}



		return to_string(res);

	}
	else return"please input correctly!";
}


int main() {
	string InputStr;

	cout << "������һ��Ǯ";
	cin >> InputStr;
	cout << Trans(InputStr);


}