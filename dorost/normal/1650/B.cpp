/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int l, r, a;
	cin >> l >> r >> a;
	l = max(l, r - a + 1);
	int l1 = r / a * a, r1 = r, x1 = r / a;
	int l2 = l, r2 = l1 - 1, x2 = r / a - 1;
	int mx = 0;
	if (l1 <= r1) {
		int u = l1 % a, v = r1 % a;
		if (u > v) {
			mx = max(mx, x1 + a - 1);
		} else {
			mx = max(mx, x1 + v);
		}
	}
	if (l2 <= r2) {
		int u = l2 % a, v = r2 % a;
		if (u > v) {
			mx = max(mx, x2 + a - 1);
		} else {
			mx = max(mx, x2 + v);
		}
	}
	cout << mx << '\n';
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