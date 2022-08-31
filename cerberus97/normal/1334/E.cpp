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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 100 + 10, mod = 998244353;

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

ll fact[N], finv[N];

ll f(ll x, vector<ll>& primes);

int main() {
	fast_cin();
	fact[0] = finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	ll d; int q;
	cin >> d >> q;
	vector<ll> primes;
	ll sq = sqrt(d);
	for (ll i = 2; i <= sq; ++i) {
		if (d % i == 0) {
			primes.pb(i);
			while (d % i == 0) {
				d /= i;
			}
		}
	}
	if (d > 1) {
		primes.pb(d);
	}
	while (q--) {
		ll u, v;
		cin >> u >> v;
		ll ans = 1, g = __gcd(u, v);
		ans = (ans * f(u / g, primes)) % mod;
		ans = (ans * f(v / g, primes)) % mod;
		cout << ans << '\n';
	}
}

ll f(ll x, vector<ll>& primes) {
	int sz = primes.size(), sum = 0;
	vector<int> q(sz, 0);
	for (int i = 0; i < sz; ++i) {
		while (x % primes[i] == 0) {
			++q[i];
			x /= primes[i];
		}
		sum += q[i];
	}
	ll ans = fact[sum];
	for (auto& i : q) {
		ans = (ans * finv[i]) % mod;
	}
	return ans;
}