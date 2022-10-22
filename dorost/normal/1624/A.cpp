/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, mx = 0, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
	}
	cout << mx - mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}