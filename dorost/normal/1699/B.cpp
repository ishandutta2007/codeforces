/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		if (i % 4 == 0 || i % 4 == 3) {
			for (int j = 0; j < m; j++) {
				cout << (j % 4 == 0 || j % 4 == 3) << ' ';
			}
		} else {
			for (int j = 0; j < m; j++) {
				cout << !(j % 4 == 0 || j % 4 == 3) << ' ';
			}
		}
		cout << '\n';
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