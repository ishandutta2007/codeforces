/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, x1, x2, y1, y2, w, h;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> w >> h;
	int s1 = x2 - x1, s2 = y2 - y1;
	int mn = INT_MAX;
	bool f = ((s1 + w) <= n), h1 = ((s2 + h) <= m);
	if (f) {
		mn = min(mn, max(0, w - x1));
		x2 = n - x2;
		mn = min(mn, max(0, w - x2));
	}
	if (h1) {
		mn = min(mn, max(0, h - y1));
		y2 = m - y2;
		mn = min(mn, max(0, h - y2));
	}
	cout << (mn == INT_MAX ? -1 : mn) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}