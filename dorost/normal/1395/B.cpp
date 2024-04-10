/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	cout << x << ' ' << y << '\n';
	cout << "1 " << y << '\n';
	cout << "1 1\n";
	for (int j = 1; j <= n; j++) {
		if (j % 2) {
			if (j != 1)
				cout << j << " 1\n";
			for (int i = 2; i <= m; i++) {
				if ((i == y && j == 1) || (i == y && j == x))
					continue;
				cout << j << ' ' << i << '\n';
			}
		} else {
			cout << j << ' ' << m << '\n';
			for (int i = m - 1; i >= 1; i--) {
				if ((i == y && j == 1) || (i == y && j == x))
					continue;
				cout << j << ' ' << i << '\n';
			}
		}
	}
}

int32_t main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}