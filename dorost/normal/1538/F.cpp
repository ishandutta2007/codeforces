/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int f(int x, int y) {
	return ((x + 1) / (y + 1));
}

void solve() {
	int l, r;
	cin >> l >> r;
	int x = 0;
	int ans = r - l;
	for (int i = 1; i < 10; i++) {
		x *= 10;
		x += 9;
		ans += (f(r - 1, x) - f(l - 1, x));
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}