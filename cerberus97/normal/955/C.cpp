/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int C = 1e6 + 10;
const ld inf = 2e18;

set<ll> s;
vector<ll> v;

void init();
inline bool is_square(ll x);

int main() {
	fast_cin();
	init();
	int q; cin >> q;
	while (q--) {
		ll L, R;
		cin >> L >> R;
		ll ans = upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L);
		ll lo = 1, hi = 1e9;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (mid * mid >= L) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		ll a = hi + 1;
		lo = 2; hi = 1e9;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (mid * mid <= R) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		ll b = lo - 1;
		ans += b - a + 1;
		cout << ans << '\n';
	}
}

void init() {
	for (ll i = 2; i <= C; ++i) {
		if (s.find(i) != s.end()) {
			continue;
		} else if (is_square(i)) {
			continue;
		}
		ll temp = i * i * i;
		while (true) {
			s.insert(temp);
			if ((ld(temp) * i) * i <= inf) {
				temp *= i * i;
			} else {
				break;
			}
		}
	}
	v.resize(s.size());
	int ctr = 0;
	for (auto &i : s) {
		v[ctr++] = i;
	}
}

inline bool is_square(ll x) {
	ll sq = round(sqrt(x));
	if (sq * sq == x) {
		return true;
	}
	return false;
}