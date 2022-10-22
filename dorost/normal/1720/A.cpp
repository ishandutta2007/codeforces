/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * d == b * c) {
		cout << 0 << '\n';
	} else if (a == 0 || c == 0 || ((a * d) % (b * c) == 0) || ((b * c) % (a * d) == 0)) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
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