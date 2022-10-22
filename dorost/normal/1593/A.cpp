/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(0, max(b, c) + 1 - a) << ' ';
	cout << max(0, max(a, c) + 1 - b) << ' ';
	cout << max(0, max(b, a) + 1 - c) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}