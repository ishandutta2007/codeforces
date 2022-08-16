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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 1e18;

void solve1(ll n, ll r, ll k);
void solve2(ll n, ll r, ll k) ;
ll maximize(ll a, ll c, ll d1, ll d2);

int main() {
	fast_cin();
	ll n, l, r, k;
	cin >> n >> l >> r >> k;
	r -= l - 1;
	if (r < 1) {
		r += n;
	}
	if (ld(n) * n <= k / n) {
		solve1(n, r, k);
	} else {
		solve2(n, r, k);
	}
}

void solve1(ll n, ll r, ll k) {
	ll best = -1;
	for (ll s1 = 0; s1 <= r; ++s1) {
		for (ll s2 = 0; s2 <= n - r; ++s2) {
			ll num = k - r - s1;
			ll den = s1 + s2 + n;
			if (num % den == 0) {
				ll a = num / den;
				if (a >= 0 and a * n <= k) {
					best = max(best, s1 + s2);
				}
			}
			if (s1 == 0) {
				continue;
			}
			++num;
			if (num % den == 0) {
				ll a = num / den;
				if (a >= 0 and a * n <= k) {
					best = max(best, s1 + s2);
				}
			}
		}
	}
	cout << best << endl;
}

void solve2(ll n, ll r, ll k) {
	ll a_mx = k / n, best = -1;
	for (ll a = 0; a <= a_mx; ++a) {
		best = max(best, maximize(a, k - r - a * n, n - r, r));
		best = max(best, 1 + maximize(a, k - r - a * n - a, n - r, r - 1));
	}
	cout << best << endl;
}

// Maximize x + y when ax + (a + 1)y = c, subject to 0 <= x <= d1 and 0 <= y <= d2
ll maximize(ll a, ll c, ll d1, ll d2) {
	if (a == 0) {
		return ((0 <= c and c <= d2) ? d1 + c : -inf);
	}
	d1 = min(d1, c / a);
	ll x = ((-c % (a + 1)) + (a + 1)) % (a + 1);
	ll i = (d1 - x) / (a + 1);
	x += i * (a + 1);
	if (0 <= x and x <= d1) {
		ll y = (c - a * x) / (a + 1);
		if (0 <= y and y <= d2) {
			return x + y;
		}
	}
	return -inf;
}