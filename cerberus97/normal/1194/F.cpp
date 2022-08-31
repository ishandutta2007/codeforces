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

const int N = 2e5 + 10, mod = 1e9 + 7;

ll t[N], fact[N], finv[N], p2[N];
ll cur = 2, cur_n = 1, cur_k = 1;

void modify(int n, int k);
ll choose(int n, int k);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	ll n, T;
	cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	fact[0] = finv[0] = p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	ll ans = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += t[i];
		if (sum > T) {
			break;
		} else {
			ll extra = min(T - sum, ll(i));
			modify(i, extra);
			ans += cur * pwr(p2[i], mod - 2);
			ans %= mod;
		}
	}
	cout << ans << endl;
}

void modify(int n, int k) {
	while (cur_n < n) {
		cur = 2 * cur - choose(cur_n, cur_k);
		cur += mod;
		cur %= mod;
		++cur_n;
	}
	while (cur_k < k) {
		cur += choose(cur_n, cur_k + 1);
		cur %= mod;
		++cur_k;
	}
	while (cur_k > k) {
		cur -= choose(cur_n, cur_k);
		cur += mod;
		cur %= mod;
		--cur_k;
	}
}

ll choose(int n, int k) {
	ll ans = (fact[n] * finv[k]) % mod;
	ans = (ans * finv[n - k]) % mod;
	return ans;
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