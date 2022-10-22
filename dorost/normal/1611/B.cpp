/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a * 3 <= b) {
		cout << a << ' ';
	} else if (b * 3 <= a) {
		cout << b << ' ';
	} else {
		cout << (a + b) / 4 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}