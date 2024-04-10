/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x, y;
	cin >> x >> y;
	if (x == y)
		cout << x + y << '\n';
	else
		cout << max(x, y) * 2 - 1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}