/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "0 0\n";
		return;
	}
	int x = abs(a - b);
	cout << abs(a - b) << ' ' << min((x - a % x) % x, a % x) << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}