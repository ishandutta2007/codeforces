/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, k, ac, bc;
	cin >> a >> b >> k;
	ac = a;
	bc = b;
	int x = 0, y;
	if (a == b) {
		y = 0;
	} if (a % b == 0 || b % a == 0) {
		y = 1;
	} else {
		y = 2;
	}
	for (int i = 2; i * i <= max(a, b); i++) {
		if (a == b && a == 1)
			break;
		while (a % i == 0)
			a /= i, x++;
		while (b % i == 0)
			b /= i, x++;
	}
	if (a != 1)
		x++;
	if (b != 1)
		x++;
	cout << (k >= y && k <= x && !(ac == bc && k == 1) ? "YES" : "NO") << ' ';
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