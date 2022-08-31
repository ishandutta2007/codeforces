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

const int N = 2e5 + 10, mod = 998244353;

ll p[N], f[N], pref[N];
ll ans = 0;

void add_group(int l, int r, int x);
ll mul(ll a, ll b);
ll mdiv(ll a, ll b);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	f[0] = 1;
	pref[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		p[i] = mdiv(p[i], 100);
		f[i] = mul(p[i], f[i - 1]);
		pref[i] = (pref[i - 1] + f[i]) % mod;
	}
	set<int> checkpoints = {1, n + 1};
	add_group(1, n, 1);
	while (q--) {
		int u; cin >> u;
		if (checkpoints.count(u)) {
			checkpoints.erase(u);
			auto it = checkpoints.upper_bound(u);
			int nxt = *it;
			int prv = *prev(it);
			add_group(prv, u - 1, -1);
			add_group(u, nxt - 1, -1);
			add_group(prv, nxt - 1, 1);
		} else {
			auto it = checkpoints.upper_bound(u);
			int nxt = *it;
			int prv = *prev(it);
			add_group(prv, u - 1, 1);
			add_group(u, nxt - 1, 1);
			add_group(prv, nxt - 1, -1);
			checkpoints.insert(u);
		}
		cout << ans << '\n';
	}
}

void add_group(int l, int r, int x) {
	ll val = (pref[r - 1] - (l == 1 ? 0 : pref[l - 2]) + mod) % mod;
	val += (mod - mul(r - l + 1, f[r]));
	val = mdiv(val, f[r]);
	val = (val + (r - l + 1)) % mod;
	val = mul(val, x + mod);
	ans = (ans + val) % mod;
}

ll mul(ll a, ll b) {
	return (a * b) % mod;
}

ll mdiv(ll a, ll b) {
	return mul(a, pwr(b, mod - 2));
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}