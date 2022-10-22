/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, k, b, s;
	cin >> n >> k >> b >> s;
	if (s < b * k || s > (b * k + (k - 1) * n)) {
		cout << -1 << '\n';
		return;
	}
	int wef = s - b * k;
	int a0 = b * k;
	for (int i = 0; i < n; i++) {
		int x = min(wef, k - 1);
		if (i == 0) {
			cout << a0 + x;
		} else 
			cout << x;
		cout << ' ';
		wef -= x;
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