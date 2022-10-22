/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	ll n;
	cin >> n;
	if (n % 2 || n <= 3) {
		cout << -1 << '\n';
	} else {
		n /= 2;
		if (n % 3 == 1) {
			cout << (n - 4) / 3 + 2 << '\n';
		} else if (n % 3 == 2) {
			cout << (n - 2) / 3 + 1 << '\n';
		} else {
			cout << n / 3 << '\n';
		}
		if (n % 2) {
			cout << (n - 3) / 2 + 1 << '\n';
		} else {
			cout << n / 2 << '\n';
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}