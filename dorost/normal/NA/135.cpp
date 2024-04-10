/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int xa, ya, xb, yb, xf, yf;
	cin >> xa >> ya >> xb >> yb >> xf >> yf;
	if (make_pair(xa, ya) == make_pair(xb, yb)) {
		cout << 0 << ' ';
		return;
	}
	int ans = abs(xa - xb) + abs(ya - yb);
	if ((xf == xa && xf == xb && yf >= min(ya, yb) && yf <= max(ya, yb)) || (yf == ya && yf == yb && xf >= min(xa, xb) && xf <= max(xa, xb))) {
		ans += 2;
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}