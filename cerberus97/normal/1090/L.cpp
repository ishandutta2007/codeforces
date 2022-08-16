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

ll solve(ll t, ll n, ll a, ll b, ll k);
void help(ll a, ll c, ll t, ll &v, ll &l, ll &r);

int main() {
	fast_cin();
	ll t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	cout << solve(t, n, a, b, k);
}

ll solve(ll t, ll n, ll a, ll b, ll k) {
	if (k > n) {
		return 0;
	}
	ll c1 = (n + 1) / 2, c2 = n - c1;
	ll lo = 1, hi = t;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll v1, l1, r1;
		help(a, c1, mid, v1, l1, r1);
		ll v2, l2, r2;
		help(b, c2, mid, v2, l2, r2);
		if (v1 + v2 >= k) {
			lo = mid + 1;
		} else if (v1 + v2 + 1 < k) {
			hi = mid - 1;
		} else if (r1 + r2 >= mid) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return lo - 1;
}

void help(ll a, ll c, ll t, ll &v, ll &l, ll &r) {
	if (t <= a) {
		v = c;
		l = t;
		r = 0;
	} else {
		v = (a * c) / t;
		r = (a * c) % t;
		l = t - r;
	}
}