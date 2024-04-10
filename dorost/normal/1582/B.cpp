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
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0)
			c0++;
		else if (x == 1)
			c1++;
	}
	cout << (c1 * 1LL << c0) << ' ';
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