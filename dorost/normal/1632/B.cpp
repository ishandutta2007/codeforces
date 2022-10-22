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
	int x = 1;
	while (x < n) 
		x *= 2;
	x /= 2;
	for (int i = 1; i < x; i++)
		cout << i << ' ';
	cout << 0 << ' ' << x << ' ';
	for (int i = x + 1; i < n; i++) 
		cout << i << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}