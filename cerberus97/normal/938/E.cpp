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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10, mod = 1e9 + 7;
const ll inf = 1e12;

ll a[N], dp[N], fact[N], finv[N];
bool seen[N];

void pre();
ll f(ll n, ll k);
ll pwr(ll x, ll e);

int main() {
	pre();
	// cout << f(3, 1) << endl;
	// return 0;
	ll n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	a[n + 1] = inf;
	int p = 1;
	ll ans = 0;
	for (int i = 1; i <= n;) {
		while (a[p] <= a[i]) {
			++p;
		}
		ll y = i - 1, x = n - p + 1, z = n - 1 - y - x;
		if (x) {
			ll k = n - y - 1;
			// cout << k << ' ' << f(n, k) << endl;
			ll temp = (f(n, k) * fact[y]) % mod;
			temp = (temp * (z + 1)) % mod;
			temp = (temp * a[i]) % mod;
			ans += temp;
		}
		i = p;
	}
	printf("%lld", ans % mod);
}

void pre() {
	fact[0] = 1;
	finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
}

ll f(ll n, ll k) {
	ll ans = (fact[n] * pwr(k + 1, mod - 2)) % mod;
	ans = (ans * finv[n - k - 1]) % mod;
	return ans;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e >>= 1;
	}
	return res;
}