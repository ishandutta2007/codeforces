/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

bool ok(int x) {
	int l = 1, r = 10000;
	while (l < r) {
		int mid = (l + r) / 2;
		if (mid * mid * mid >= x) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return (l * l * l == x);
}

void solve() {
	int x;
	cin >> x;
	for (int i = 1; i <= 10000; i++) {
		int y = x - i * i * i;
		if (y <= 0)
			continue;
		if (ok(y)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}