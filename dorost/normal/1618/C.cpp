/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 105;
int a[N];

void solve() {
	int n;
	cin >> n;
	int gcd1 = 0, gcd2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) {
			gcd1 = __gcd(gcd1, a[i]);
		} else {
			gcd2 = __gcd(gcd2, a[i]);
		}
	}
	bool f = true, h = true;
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			if (a[i] % gcd1 == 0) 
				f = false;
		} else {
			if (a[i] % gcd2 == 0)
				h = false;
		}
	}
	if (f) {
		cout << gcd1 << ' ';
	} else if (h) {
		cout << gcd2 << ' ';
	} else {
		cout << 0 << ' ';
	}
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