/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ceil_div(a, b) ((a) + (b) - 1) / (b)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll g(ll x, ll p, ll q);
ll cmp(ll x, ll y, ll p, ll q);

int main() {
	fast_cin();
	int tc; cin >> tc;
	while (tc--) {
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		ll t = sqrt(b - a + 1);
		vector<pll> vals;
		set<ll> seen;
		for (ll x = a; x < a + t; ++x) {
			if (!seen.count(g(x, p, q))) {
				seen.insert(g(x, p, q));
				vals.pb({g(x, p, q), x});
			}
		}
		sort(vals.begin(), vals.end());
		ll ans = a;
		for (ll i = 0; a + i * t <= b; ++i) {
			if (a + (i + 1) * t - 1 <= b) {
				ll target = (3 * q - g(i * t, p, q)) % (2 * q);
				ans = cmp(ans, vals.begin()->second + i * t, p, q);
				ans = cmp(ans, vals.rbegin()->second + i * t, p, q);
				auto it = lower_bound(vals.begin(), vals.end(), make_pair(target, 0ll));
				if (it != vals.end()) {
					ans = cmp(ans, it->second + i * t, p, q);
				}
				if (it != vals.begin()) {
					--it;
					ans = cmp(ans, it->second + i * t, p, q);
				}
			} else {
				for (ll x = a + i * t; x <= b; ++x) {
					ans = cmp(ans, x, p, q);
				}
			}
		}
		cout << ans << '\n';
	}
}

ll g(ll x, ll p, ll q) {
	return (2 * p * x) % (2 * q);
}

ll cmp(ll x, ll y, ll p, ll q) {
	if (x >= y) {
		swap(x, y);
	}
	if (abs(g(x, p, q) - q) <= abs(g(y, p, q) - q)) {
		return x;
	} else {
		return y;
	}
}