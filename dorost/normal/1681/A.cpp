/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n;
	int mx = 0;
	bool f = true, h = true;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > mx) {
			mx = x;
			f = false;
			h = false;
		}
		if (x == mx)
			f = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x > mx) {
			mx = x;
			f = false;
			h = false;
		}
		if (x == mx)
			h = true;
	}
	cout << (f ? "Alice" : "Bob") << '\n';
	cout << (!h ? "Alice" : "Bob") << '\n';
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