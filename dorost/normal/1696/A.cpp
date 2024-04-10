/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, z;
	cin >> n >> z;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
		mx = max(mx, x | z);
	}
	cout << mx << '\n';
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