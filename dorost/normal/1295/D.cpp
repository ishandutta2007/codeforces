/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	ll a, m;
	cin >> a >> m;
	ll x = __gcd(a, m);
	x = m / x;
	ll ans = 0, x2 = x;
	vector <pair <ll, ll>> v;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		ll y = 1;
		while (x % i == 0)
			y *= i, x /= i;
		if (y != 1)
			v.push_back({i, y});
	}
	if (x != 1) {
		v.push_back({x, x});
	}
	x = x2;
	int l = (1 << v.size());
	for (int i = 0; i < l; i++) {
		int w = 0;
		ll u = x;
		int y = i;
		for (int j = 0; j < v.size(); j++) {
			if (y % 2)
				w++, u /= v[j].F;
			y /= 2;
		}
		if (w % 2 == 0)
			ans += u;
		else
			ans -= u;
	}
	cout << ans << '\n';
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