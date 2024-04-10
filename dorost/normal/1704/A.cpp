/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	bool f = true;
	for (int i = 0; i < m - 1; i++) {
		f &= (s[n - i - 1] == t[m - i - 1]);
	}
	int mn = 1, mx = 0;
	for (int i = 0; i <= n - m; i++) {
		mn = min(mn, s[i] - '0');
		mx = max(mx, s[i] - '0');
	}
	f &= (((t[0] - '0') == mn) || ((t[0] - '0') == mx));
	cout << (f ? "YES" : "NO") << '\n';
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