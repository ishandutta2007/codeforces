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
	int n = (abs(a - b)) * 2;
	if (n % 2 || n < c || n < a || n < b) {
		cout << -1 << ' ';
	} else {
		cout << (c > n / 2 ? c - n / 2 : c + n / 2) << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}