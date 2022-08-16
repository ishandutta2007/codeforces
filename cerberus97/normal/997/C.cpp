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

const int N = 1e6 + 10;
const ll mod = 998244353;

ll fact[N], invF[N];

ll pwr(ll x, ll e);
ll choose(ll n, ll i);

int main() {
	fact[0] = invF[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		invF[i] = pwr(fact[i], mod - 2);
	}
	ll n; cin >> n;
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ll mul = (choose(n, i) * (((n - i) & 1) ? (mod - 1) : 1)) % mod;
		mul = (mul * pwr(pwr(3, i) + mod - 1, n)) % mod;
		ans = (ans + mul) % mod;
	}
	ans = (3 * ans) % mod;
	for (int i = 1; i <= n; ++i) {
		ll temp = (2 * choose(n, i) * pwr(3, n * (n - i) + 1)) % mod;
		temp = (temp * (pwr(3, i - 1) + mod - 1)) % mod;
		if (i & 1) {
			ans = (ans - temp + mod) % mod;
		} else {
			ans = (ans + temp) % mod;
		}
	}
	ans = pwr(3, n * n + 1) - ans + mod;
	cout << ans % mod;
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

ll choose(ll n, ll i) {
	ll ans = (fact[n] * invF[i]) % mod;
	return (ans * invF[n - i]) % mod;
}