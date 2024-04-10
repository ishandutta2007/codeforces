/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b;
	cin >> a >> b;
	cout << (abs(a - b) <= 1 && (a != 0 || b != 0) ? "YES" : "NO");
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}