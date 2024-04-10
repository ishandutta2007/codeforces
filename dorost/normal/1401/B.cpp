/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x0, x1, x2, y0, y1, y2;
	cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
	int ans = min(x2, y1);
	x2 -= ans;
	y1 -= ans;
	if (x1 < y0) {
		y0 -= x1;
		x1 = 0;
	}else {
		x1 -= y0;
		y0 = 0;
	}
	if (x1 < y1) {
		y1 -= x1;
		x1 = 0;
	}else {
		x1 -= y1;
		y1 = 0;
	}
	ans -= x1;
	cout << ans * 2 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}