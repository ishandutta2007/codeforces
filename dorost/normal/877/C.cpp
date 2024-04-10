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
	cout << n + n / 2 << '\n';
	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 1; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}