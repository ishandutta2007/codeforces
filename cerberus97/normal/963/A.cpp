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

const int N = 1e5 + 10, mod = 1e9 + 9;

ll s[N];

ll pwr(ll x, ll e);

int main() {
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	for (int i = 0; i < k; ++i) {
		char c; cin >> c;
		if (c == '+') {
			s[i] = 1;
		} else {
			s[i] = mod - 1;
		}
	}
	ll c = (n + 1) / k;
	ll val = 0;
	for (int i = 0; i < k; ++i) {
		val += (s[i] * ((pwr(a, n - i) * pwr(b, i)) % mod));
		val %= mod;
	}
	ll r = (pwr(b, k) * pwr(pwr(a, k), mod - 2)) % mod;
	ll ans;
	if (r == 1) {
		ans = (val * c) % mod;
	} else {
		ans = (val * (pwr(r, c) + mod - 1)) % mod;
		ans *= pwr(r + mod - 1, mod - 2);
		ans %= mod;
	}
	cout << ans;
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