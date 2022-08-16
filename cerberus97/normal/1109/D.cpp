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

const int N = 1e6 + 10, mod = 1e9 + 7;

ll fact[N], finv[N];

ll choose(ll n, ll k);
ll inverse(ll x);
ll pwr(ll x, ll e);
void mul(ll &a, ll b);

int main() {
	fast_cin();
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	fact[0] = finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = inverse(fact[i]);
	}
	ll ans = 0;
	for (ll k = 2; k <= n; ++k) {
		ll temp = 1;
		mul(temp, choose(n - 2, k - 2));
		mul(temp, choose(m - 1, k - 2));
		mul(temp, k);
		mul(temp, fact[k - 2]);
		mul(temp, pwr(m, n - k));
		mul(temp, pwr(n, n - k - 1));
		// cout << k << ' ' << temp << endl;
		ans += temp;
	}
	ans %= mod;
	cout << ans << endl;
}

ll choose(ll n, ll k) {
	if (n < k) {
		return 0;
	}
	ll ans = 1;
	mul(ans, fact[n]);
	mul(ans, finv[k]);
	mul(ans, finv[n - k]);
	return ans;
}

ll inverse(ll x) {
	return pwr(x, mod - 2);
}

ll pwr(ll x, ll e) {
	if (e < 0) {
		e = -e;
		x = inverse(x);
	}
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e /= 2;
		x = (x * x) % mod;
	}
	return res;
}

void mul(ll &a, ll b) {
	a = (a * b) % mod;
}