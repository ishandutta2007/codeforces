/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	if (n % 7 == 0) {
		cout << n << ' ';
	} else {
		int x = n - (n % 10);
		x += 7 - (x % 7);
		cout << x << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}