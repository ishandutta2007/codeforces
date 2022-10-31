#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	int woke = 60 * (10 * (a[0] - '0') + a[1] - '0') + (a[3] - '0') * 10 + a[4] - '0';
	int slept = 60 * (10 * (b[0] - '0') + b[1] - '0') + (b[3] - '0') * 10 + b[4] - '0';
	int bed = woke - slept;
	while (bed < 0)
		bed += 24 * 60;
	if (bed / 60 == 0)
		cout << "00";
	else if (bed / 60 < 10) {
		cout << "0" << bed / 60;
	} else
		cout << bed / 60;
	cout << ":";

	if (bed % 60 == 0)
		cout << "00";
	else if (bed % 60 < 10) {
		cout << "0" << bed % 60;
	} else
		cout << bed % 60;
	cout << "\n";
}