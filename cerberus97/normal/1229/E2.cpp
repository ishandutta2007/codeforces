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
#include <bitset>
#include <unordered_map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 10, M = 128, mod = 1e9 + 7;
// const state_t one = 1;

typedef bitset<M> state_t;

state_t reach[M][M];
unordered_map<state_t, ll> dp, nxt;
ll p[N][N], pre_prob[N][M];

void pre_calc(int n);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> p[i][j];
			p[i][j] *= pwr(100, mod - 2);
			p[i][j] %= mod;
		}
	}
	pre_calc(n);
	int tot = (1 << n);
	dp[1] = 1;
	for (int i = 0; i < n; ++i) {
		for (auto &temp : dp) {
			state_t cur = temp.first;
			for (int nmask = 0; nmask < tot; ++nmask) {
				state_t s = 0;
				ll prob = (temp.second * pre_prob[i][nmask]) % mod;
				for (int mask = 0; mask < tot; ++mask) {
					if (cur[mask]) {
						s |= reach[nmask][mask];
					}
				}
				nxt[s] += prob;
				nxt[s] %= mod;
			}
		}
		dp = nxt;
		// cout << i << ' ' << dp.size() << endl;
		// for (auto &temp : dp) {
		// 	cout << temp.first << ' ' << temp.second << endl;
		// }
		// cout << endl;
		nxt.clear();
	}
	ll ans = 0;
	for (auto &temp : dp) {
		if (temp.first != 0) {
			ans += temp.second;
			ans %= mod;
		}
	}
	cout << ans << endl;
}

void pre_calc(int n) {
	int tot = (1 << n);
	for (int mask = 0; mask < tot; ++mask) {
		for (int nmask = 0; nmask < tot; ++nmask) {
			for (int i = 0; i < n; ++i) {
				if ((nmask & (1 << i)) and !(mask & (1 << i))) {
					// if (mask == 0 and nmask == 1) {
					// 	cout << i << ' ' << (one << (mask | (1 << i))) << endl;
					// }
					reach[nmask][mask].set(mask | (1 << i));
				}
			}
			// cout << mask << ' ' << nmask << ' ' << reach[nmask][mask] << endl;
		}
	}
	// cout << endl;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < tot; ++mask) {
			pre_prob[i][mask] = 1;
			for (int j = 0; j < n; ++j) {
				if (mask & (1 << j)) {
					pre_prob[i][mask] *= p[i][j];
				} else {
					pre_prob[i][mask] *= (mod + 1 - p[i][j]);
				}
				pre_prob[i][mask] %= mod;
			}
		}
	}
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