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
	int mn = INT_MAX;
	int x = 1;
	for (int i = 0; i <= 9; i++) {
		if (n >= x) {
			mn = min(mn, n - x);
		}
		x *= 10;
	}
	cout << mn << '\n';
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