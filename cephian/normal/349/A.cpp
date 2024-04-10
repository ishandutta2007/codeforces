#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int _25 = 0, _50 = 0, _100 = 0;

	for (int i = 0; i < n; ++i) {
		int pay;
		cin >> pay;
		if (pay == 25)
			++_25;
		else if (pay == 50)
			++_50;
		else
			++_100;

		int back = pay - 25;
		if (back != 0) {
			if (back >= 50 && _50 > 0) {
				back -= 50;
				--_50;
			}
			while (back >= 25 && _25 > 0) {
				back -= 25;
				--_25;
			}
			if (back != 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";

	return 0;
}