/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a & b & c & d)) {
		cout << 2 << '\n';
	} else if (!(a | b | c | d)) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
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