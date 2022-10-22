/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int l, r;
	cin >> l >> r;
	if (l == r) {
		cout << 0 << ' ';
		return;
	}
	if (l * 2 - 1 > r) {
		cout << r % l << ' ';
	} else {
		cout << (r - 1) / 2 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}