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
	bool f = false;
	int x = sqrt(n / 2), y = sqrt(n / 4);
	if (n % 2 == 0) {
		if (x * x == n / 2) {
			f = true;
		}
	}
	if (n % 4 == 0) {
		if (y * y == n / 4) {
			f = true;
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}