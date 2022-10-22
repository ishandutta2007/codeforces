/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int x = 1;
	while (x <= n) {
		if ((n - x) % b == 0) {
			cout << "Yes\n";
			return;
		} else {
			if (a == 1)
				break;
			x *= a;
		}
	}
	cout << "No\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}