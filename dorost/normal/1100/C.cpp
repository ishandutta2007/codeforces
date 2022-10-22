/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	ld p = 3.1415926535897932384626433;
	ld n, r;
	cin >> n >> r;
	ld x = sin(p / n);
	x = 1 / x;
	x--;
	x = r / x;
	cout << fixed << setprecision(100) << x;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}