/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return (x > 1);
}

void solve() {
	int x, d;
	cin >> x >> d;
	int y = x, c = 0;
	while (y % d == 0)
		y /= d, c++;
	if (c < 2) {
		cout << "NO\n";
		return;
	}
	if (is_prime(d)) {
		if (is_prime(y) || y == 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	} else {
		if (c >= 4) {
			cout << "YES\n";
		} else {
			if (c == 2) {
				if (is_prime(y) || y == 1) {
					cout << "NO\n";
				} else {
					cout << "YES\n";
				}
			} else {
				if (is_prime(y) || y == 1) {
					int l = x / d;
					l /= d;
					bool f = false;
					for (int i = 1; i * i <= l; i++) {
						if (l % i)
							continue;
						int a = i;
						int b = l / i;
						if (a % d == 0 || b % d == 0)
							continue;
						f = true;
					}
					cout << (f ? "YES" : "NO") << '\n';
				} else {
					cout << "YES\n";
				}
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}