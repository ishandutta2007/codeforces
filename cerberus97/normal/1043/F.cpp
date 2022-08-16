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

const int N = 3e5 + 10, mod = 1e9 + 7;

bool prime[N];
int mu[N];
ll ctr[N], fact[N], finv[N];

void pre();
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	pre();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		++ctr[a];
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 2 * i; j < N; j += i) {
			ctr[i] += ctr[j];
		}
	}
	fact[0] = finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	int lo = 1, hi = min(7, n);
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		ll ans = 0;
		for (int i = 1; i < N; ++i) {
			if (ctr[i] < mid) {
				continue;
			}
			ll temp = fact[ctr[i]] * finv[mid];
			temp %= mod;
			temp *= finv[ctr[i] - mid];
			temp %= mod;
			ans += mu[i] * temp;
			ans += mod;
			ans %= mod;
		}
		if (ans) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	if (hi == min(7, n)) {
		cout << -1;
	} else {
		cout << hi + 1 << endl;
	}
}

void pre() {
	for (int i = 1; i < N; ++i) {
		prime[i] = true;
		mu[i] = 1;
	}
	prime[1] = false;
	for (ll i = 2; i < N; ++i) {
		if (!prime[i]) {
			continue;
		}
		for (ll j = i; j < N; j += i) {
			prime[j] = false;
			mu[j] *= -1;
		}
		for (ll j = i * i; j < N; j += i * i) {
			mu[j] = 0;
		}
	}
}

ll pwr(ll x, ll e) {
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