/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x, y;
	cin >> x >> y;
	if (x > y) {
		cout << x + y << '\n';
	} else if (x == y) {
		cout << x << '\n';
	} else {
		x = (y / x) * x;
		int ans = (x + y) / 2;
		cout << ans << '\n';
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