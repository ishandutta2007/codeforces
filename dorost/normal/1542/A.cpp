/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int y;
		cin >> y;
		if (y % 2)
			x++;
	}
	cout << (x == n ? "yes" : "no") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}