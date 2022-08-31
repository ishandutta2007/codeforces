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

const int N = 500 + 10, mod = 998244353;

map<ll, int> mp;
map<ll, int> primes;
map<ll, int> idx;

bool done[N];

ll check_pwr(ll a);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		ll a; cin >> a;
		mp[a]++;
	}
	int nxt_idx = 0;
	for (auto &m : mp) {
		idx[m.first] = nxt_idx++;
	}
	for (auto &m : mp) {
		ll a = m.first, ctr = m.second;
		if (done[idx[a]]) {
			continue;
		}
		ll p = check_pwr(a);
		if (!p) {
			for (auto &q : primes) {
				if (a % q.first == 0) {
					p = q.first;
					break;
				}
			}
		}
		if (!p) {
			for (auto &o : mp) {
				if (o.first == a) {
					continue;
				}
				ll g = __gcd(a, o.first);
				if (g > 1) {
					p = g;
					break;
				}
			}
		}
		if (p) {
			done[idx[a]] = true;
			while (a % p == 0) {
				a /= p;
				primes[p] += ctr;
			}
			if (a > 1) {
				primes[a] += ctr;
			}
		}
	}
	ll ans = 1;
	for (auto &p : primes) {
		ans = (ans * ((p.second + 1) % mod)) % mod;
	}
	for (auto &m : mp) {
		if (!done[idx[m.first]]) {
			ans = (ans * (m.second + 1)) % mod;
			ans = (ans * (m.second + 1)) % mod;
		}
	}
	cout << ans << endl;
}

ll check_pwr(ll a) {
	ll rt = sqrt(sqrt(a));
	for (ll i = rt - 5; i <= rt + 5; ++i) {
		if (i > 0 and i * i * i * i == a) {
			return i;
		}
	}

	rt = cbrt(a);
	for (ll i = rt - 5; i <= rt + 5; ++i) {
		if (i > 0 and i * i * i == a) {
			return i;
		}
	}
	
	rt = sqrt(a);
	for (ll i = rt - 5; i <= rt + 5; ++i) {
		if (i > 0 and i * i == a) {
			return i;
		}
	}

	return 0;
}