/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	for (int x = 0; x <= n / 7; x++) {
		int m = n - x * 7;
		for (int y = 0; y <= m / 5; y++) {
			int o = m - y * 5;
			if (o % 3 == 0) {
				cout << o / 3 << ' ' << y << ' ' << x << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}