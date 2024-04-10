/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n;
	cin >> n;
	int sum = 0, mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		mx = max(mx, x);
	}
	ld x = (ld)mx + (ld)(sum - mx) / (ld)(n - 1);
	cout << fixed << setprecision(12) << ' ' << x;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}