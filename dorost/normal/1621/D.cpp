/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	int mn = INT_MAX;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			int x;
			cin >> x;
			if (i >= n && j >= n) {
				ans += x;
			}
			if (i == n - 1 || i == 0) {
				if (j == n || j == 2 * n - 1) {
					mn = min(mn, x);
				}
			}
			if (i == n || i == 2 * n - 1) {
				if (j == 0 || j == n - 1) {
					mn = min(mn, x);
				}
			}
		}
	}
	cout << ans + (ll)mn << ' '; 
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