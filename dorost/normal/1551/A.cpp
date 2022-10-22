/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << n / 3 << ' ' << n / 3 << '\n';
	} else if (n % 3 == 1) {
		cout << n / 3 + 1 << ' ' << n / 3 << '\n';
	} else {
		cout << n / 3 << ' ' << n / 3 + 1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}