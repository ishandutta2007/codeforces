/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	int mn = INT_MAX, mx = 0, b = -1, a = -1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < mn) {
			mn = x;
			a = i;
		}
		if (x > mx) {
			mx = x;
			b = i;
		}
	}
	cout << a + 1 << ' ' << b + 1 << '\n';
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