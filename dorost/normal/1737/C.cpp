/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	int r1, c1, r2, c2, r3, c3;
	int x, y;
	cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> x >> y;
	bool h = true;
	int aa = r1 + r2 + r3 - 3;
	int bb = c1 + c2 + c3 - 3;
	int cc = 3 * n - r1 - r2 - r3;
	int dd = 3 * n - c1 - c2 - c3;
	if ((aa + bb == 2 && x != 1 && y != 1) || (aa + dd == 2 && x != 1 && y != n) || (cc + bb == 2 && x != n && y != 1) || (cc + dd == 2 && x != n && y != n))
		h = false;
	r1 &= 1;
	c1 &= 1;
	r2 &= 1;
	c2 &= 1;
	r3 &= 1;
	c3 &= 1;
	x &= 1;
	y &= 1;
	bool f = false;
	if (x == r1 && y == c1)
		f = true;
	if (x == r2 && y == c2)
		f = true;
	if (x == r3 && y == c3)
		f = true;
	cout << (f && h ? "YES" : "NO") << '\n';
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