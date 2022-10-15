#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, d12, d23, d31; cin >> n >> d12 >> d23 >> d31;
		if ((d12 + d23 + d31) % 2) {
			cout << "NO\n";
			continue;
		}
		int x = (d12 + d31 - d23) / 2;
		int y = (d23 + d12 - d31) / 2;
		int z = (d31 + d23 - d12) / 2;
		if (x < 0 || y < 0 || z < 0 || (x == 0) + (y == 0) + (z == 0) >= 2 || x + y + z + 1 > n) {
			cout << "NO\n";
			continue;
		}
		int r = x == 0 ? 1 : y == 0 ? 2 : z == 0 ? 3 : 4, i = r != 4 ? 4 : 5;
		cout << "YES\n";
		if (x) {
			int i_ = r;
			while (--x)
				cout << i_ << ' ' << i << '\n', i_ = i++;
			cout << i_ << " 1\n";
		}
		if (y) {
			int i_ = r;
			while (--y)
				cout << i_ << ' ' << i << '\n', i_ = i++;
			cout << i_ << " 2\n";
		}
		if (z) {
			int i_ = r;
			while (--z)
				cout << i_ << ' ' << i << '\n', i_ = i++;
			cout << i_ << " 3\n";
		}
		while (i <= n)
			cout << r << ' ' << i++ << '\n';
	}
	return 0;
}