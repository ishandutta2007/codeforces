/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	ll x, n;
	cin >> x >> n;
	ll l = n / 4 * 4 + 1, r = n;
	for (ll i = l; i <= r; i++) {
		if (x % 2)
			x += i;
		else
			x -= i;
	}
	cout << x << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}