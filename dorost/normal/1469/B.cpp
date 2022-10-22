/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n;
	int s = 0, mx1 = 0, mx2 = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
		mx1 = max(mx1, s);
	}
	s = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		s += x;
		mx2 = max(mx2, s);
	}
	cout << mx1 + mx2 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}