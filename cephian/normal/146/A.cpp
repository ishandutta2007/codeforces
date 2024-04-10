#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (str[i] != '4' && str[i] != '7') {
			ok = false;
			break;
		}
	}
	if (ok) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n / 2; ++i) {
			sum1 += str[i];
			sum2 += str[i + n / 2];
		}
		if (sum1 != sum2)
			ok = false;
	}
	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}