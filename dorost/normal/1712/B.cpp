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
	for (int i = 1; i <= n; i++) {
		if (n & 1) {
			if (i == 1)
				cout << 1 << ' ';
			else
				cout << (i ^ 1) << ' ';
		} else {
			cout << (((i - 1) ^ 1) + 1) << ' ';
		}
	}
	cout << '\n';
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