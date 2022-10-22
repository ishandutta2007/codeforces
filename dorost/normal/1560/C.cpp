/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int k;
	cin >> k;
	int x = 0, y = 1;
	for (int i = 1; i < 31655; i++) {
		if (i * i < k) {
			x = i * i;
			y = i + 1;
		}
	}
	k -= x;
	if (k <= y) {
		cout << k << ' ' << y << '\n';
	} else {
		cout << y << ' ' << (y) - (k - y) << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}