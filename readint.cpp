#include "readint.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int read_int(const string &prompt, int low, int high)
{
	try
	{
		if (cin.fail())
			throw invalid_argument("");
		bool good;
		int number;
		cout << prompt;
		cin >> number;
		while (true) {
			try {
				if (number < high && number > low)
					return number;
				else
					throw range_error("number is out of range");
			}
			catch (range_error) {
				if (low > high)
				throw invalid_argument("range is invalid");
				else {
					cout << "number is not in range, please enter new number\n";
					cin.clear();
					cin.ignore(INT16_MAX, '\n');
					cin >> number;
			}
			}

		}
	}
	catch (ios_base::failure) {

		throw invalid_argument("");
	}
}