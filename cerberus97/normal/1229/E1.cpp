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

const int N = 10, M = 100, mod = 1e9 + 7;

ll p[N][N];
bool g[N][N];
int id[M], rev[M];
int lid;

vector<ll> get_prob(vector<int> lhs, bool flip, int n);
void sos_dp(vector<ll> &v, int n);
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
	if (n % 2 == 1) {
		p[n][n] = 1;
		++n;
	}
	int tot = (1 << n);
	for (int mask = 0; mask < tot; ++mask) {
		if (__builtin_popcount(mask) == n / 2) {
			id[mask] = lid;
			rev[lid] = mask;
			++lid;
		}
	}
	vector<int> h1(n / 2), h2(n / 2);
	iota(h1.begin(), h1.end(), 0);
	iota(h2.begin(), h2.end(), n / 2);
	vector<ll> p1 = get_prob(h1, false, n);
	vector<ll> p2 = get_prob(h2, true, n);
	sos_dp(p2, lid);
	ll ans = 0;
	tot = (1 << lid);
	for (int m1 = 0; m1 < tot; ++m1) {
		int complement = (tot - 1 - m1);
		ans += p2[complement] * p1[m1];
		ans %= mod;
	}
	ans = (mod + 1 - ans) % mod;
	cout << ans << endl;
}

vector<ll> get_prob(vector<int> lhs, bool flip, int n) {
	vector<pii> edges;
	vector<ll> prob;
	for (auto &i : lhs) {
		for (int j = 0; j < n; ++j) {
			edges.pb({i, j});
			prob.pb(p[i][j]);
		}
	}
	vector<ll> ans(1 << lid, 0);
	int sz = edges.size(), tot = (1 << sz);
	for (int mask = 0; mask < tot; ++mask) {
		memset(g, 0, sizeof(g));
		ll cur_prob = 1;
		for (int i = 0; i < sz; ++i) {
			if (mask & (1 << i)) {
				g[edges[i].first][edges[i].second] = true;
				cur_prob *= prob[i];
				cur_prob %= mod;
			} else {
				cur_prob *= (mod + 1 - prob[i]);
				cur_prob %= mod;
			}
		}
		int cur_mask = 0;
		for (int id = 0; id < lid; ++id) {
			int triple_mask = rev[id];
			if (flip) {
				triple_mask = (1 << n) - 1 - triple_mask;
			}
			vector<int> triple;
			for (int j = 0; j < n; ++j) {
				if (triple_mask & (1 << j)) {
					triple.pb(j);
				}
			}
			bool ok = false;
			do {
				ok = true;
				for (int t = 0; t < n / 2; ++t) {
					if (!g[lhs[t]][triple[t]]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					break;
				}
			} while (next_permutation(triple.begin(), triple.end()));
			if (ok) {
				cur_mask |= (1 << id);
			}
		}
		ans[cur_mask] += cur_prob;
		ans[cur_mask] %= mod;
	}
	return ans;
}

void sos_dp(vector<ll> &v, int n) {
	int tot = (1 << n);
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < tot; ++mask) {
			if (mask & (1 << i)) {
				v[mask] += v[mask ^ (1 << i)];
				v[mask] %= mod;
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