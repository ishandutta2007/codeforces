#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string num;
	cin >> num;
	for (int i = 0; i < num.size(); ++i) {
		if (9 - (num[i] - '0') < (num[i] - '0')) {
			if (i != 0 || num[i] != '9') {
				num[i] = 9 - (num[i] - '0') + '0';
			}
		}
	}
	cout << num << "\n";

	return 0;
}