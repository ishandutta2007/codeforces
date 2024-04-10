/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, xb, yb, xd, yd;
	cin >> n >> m >> xb >> yb >> xd >> yd; 
	if (xb == xd || yb == yd) {
		cout << 0 << '\n';
		return;
	}
	int ra = 1, rb = 1;
	for (int i = 0; i < (n + m) * 5; i++) {
		if (xb + ra == n + 1 || xb + ra == 0)
			ra = -ra;
		if (yb + rb == m + 1 || yb + rb == 0)
			rb = -rb;
		xb += ra;
		yb += rb;
		if (xb == xd || yb == yd) {
			cout << i + 1 << '\n';
			return;
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}