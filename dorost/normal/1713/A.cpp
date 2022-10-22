/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int mnx = 0, mxx = 0, mny = 0, mxy = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mnx = min(mnx, x);
		mxx = max(mxx, x);
		mny = min(mny, y);
		mxy = max(mxy, y);
	}
	cout << (mxx + mxy - mny - mnx) * 2 << '\n';
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