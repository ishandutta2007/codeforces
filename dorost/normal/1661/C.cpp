/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N];

ll ans(ll a, ll b) {
	if (a > b)
		return 2 * a - 1;
	if (a == b)
		return 2 * a;
	ll x = (b - a) / 3;
	ll mn = LLONG_MAX;
	for (ll y = x - 10; y <= x + 10; y++) {
		if (a + 2 * y > b - y) {
			mn = min(mn, 2 * (a + 2 * y) - 1);
		} else {
			mn = min(mn, 2 * (b - y));
		}
	}
	return mn;
}

void solve() {
	int n, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	ll f = 0, z = 0;
	for (int i = 0; i < n; i++) {
		a[i] = mx - a[i];
		if (a[i] % 2)
			f++;
		z += a[i] / 2;
	}
	cout << min(ans(f, z), ans(n - f, z + f)) << '\n';
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