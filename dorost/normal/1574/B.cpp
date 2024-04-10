/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, c, m;
	cin >> a >> b >> c >> m;
	int mx = (a + b + c) - 3;
	int mn = max({a - (b + c) - 1, b - (a + c) - 1, c - (a + b) - 1});
	cout << (m >= mn && m <= mx ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}