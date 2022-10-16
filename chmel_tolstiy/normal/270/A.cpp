#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t --> 0) {
		int a;
		cin >> a;
		bool ok = true;
		for (int n = 3; ok && n < 100000;++n) {
			if ((n - 2) * 180 == n * a) {
				cout << "YES" << endl;
				ok = false;
			}
		}
		if (ok)
			cout << "NO" << endl;
	}
	return 0;
}