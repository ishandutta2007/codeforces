/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int ans = l1 + l2;
	for (int i = 0; i < 100; i++) {
		if (l1 <= i && i <= r1 && i >= l2 && i <= r2) {
			ans = min(ans, i);
		}
	}
	cout << ans << '\n';
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