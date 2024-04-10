/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int ans(int x, int i) {
	x++;
	int m = 1 << (i + 1);
	return (x / m) * m / 2 + min(x % m, m / 2);
}

void solve() {
	int l, r;
	cin >> l >> r;
	int mn = INT_MAX;
	for (int i = 0; i < 20; i++) {
		mn = min(mn, ans(r, i) - ans(l - 1, i));
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}