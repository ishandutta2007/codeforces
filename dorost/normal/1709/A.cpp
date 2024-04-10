/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x, a[4] = {}, f[4] = {};
	cin >> x >> a[1] >> a[2] >> a[3];
	int cnt = 0;
	while (x != 0) {
		f[x] = true;
		int ox = x;
		x = a[x];
		a[ox] = 0;
	}
	cout << (f[1] && f[2] && f[3] ? "YES" : "NO") << '\n';
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