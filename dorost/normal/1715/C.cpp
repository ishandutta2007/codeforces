/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
ll a[N];

void solve() {
	ll n, m;
	cin >> n >> m;
	ll ans = (ll)n * (ll)(n + 1) / 2LL;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (i) {
			if (a[i] != a[i - 1]) {
				ans += (i) * (n - i);
			}
		}
	}
	while (m--) {
		ll i, x;
		cin >> i >> x;
		i--;
		if (i != n - 1 && a[i] != a[i + 1])
			ans -= (i + 1) * (n - i - 1);
		if (i != 0 && a[i] != a[i - 1])
			ans -= (i) * (n - i);
		a[i] = x;
		if (i != n - 1 && a[i] != a[i + 1])
			ans += (i + 1) * (n - i - 1);
		if (i != 0 && a[i] != a[i - 1])
			ans += (i) * (n - i);
		cout << ans << '\n';
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