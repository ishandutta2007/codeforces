/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b;
	cin >> a >> b;
	int n = abs(a - b);
	if (n % 2) {
		cout << -1 << ' ';
		return;
	}
	if (a == b && a == 0) {
		cout << 0 << ' ';
		return;
	}
	if (a == b) {
		cout << 1 << ' ';
		return;
	}
	cout << 2 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}