/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ps[N];

void solve() {
	int n;
	cin >> n;
	ps[0] = 0;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], ps[i] = ps[i - 1] + a[i];
		mx = max(mx, (ps[i] + i - 1) / i);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t < mx) {
			cout << -1 << '\n';
			continue;
		}
		cout << (ps[n] + t - 1) / t << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}