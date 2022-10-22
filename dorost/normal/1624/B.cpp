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
	int a1 = b - (c - b);
	int b1 = ((a + c) % 2 ? 0 : (a + c) / 2);
	int c1 = ((b - a) + b);
	if ((a1 > 0 && a1 % a == 0) || (b1 > 0 && b1 % b == 0) || (c1 > 0 && c1 % c == 0)) {
		cout << "YES ";
	} else {
		cout << "NO ";
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}