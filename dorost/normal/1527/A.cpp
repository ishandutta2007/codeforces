/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	while (n) {
		n /= 2;
		ans++;
	}
	int x = 1;
	for (int i = 0; i < ans - 1; i++) {
		x *= 2;
	}
	cout << x - 1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}