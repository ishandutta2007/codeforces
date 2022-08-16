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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, P = 7e5, A = 1e7 + 10, LOG = log2(N) + 2, mod = 1e9 + 7;

struct query {
	int p, e, idx;
};

vector<query> queries[N];
vector<int> g[N], str[P], factors[A];
int a[N], qu[N], qv[N], qx[N];
int prime[P], depth[N], parent[N][LOG], mx[P];
ll ans[N];
bitset<A> not_prime, seen;

void sieve();
void dfs1(int u, int p);
void dfs2(int u, int p);
void upd(int x, int ch);
int lca(int u, int v);
int pwr(ll x, int e);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		seen[a[i]] = 1;
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> qu[i] >> qv[i] >> qx[i];
		seen[qx[i]] = 1;
	}
	sieve();
	for (int i = 1; i <= q; ++i) {
		int l = lca(qu[i], qv[i]);
		ans[i] = __gcd(qx[i], a[l]);
		for (auto &j : factors[qx[i]]) {
			int ctr = 0;
			while (qx[i] % prime[j] == 0) {
				qx[i] /= prime[j];
				++ctr;
			}
			queries[qu[i]].pb({j, ctr, i});
			queries[qv[i]].pb({j, ctr, i});
			queries[l].pb({j, ctr, -i});
		}
	}
	dfs2(1, 0);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}

void sieve() {
	int p = 0;
	not_prime[1] = true;
	for (int i = 2; i < A; ++i) {
		if (!not_prime[i]) {
			prime[p] = i;
			ll temp = A;
			while (temp > 1) {
				temp /= i;
				++mx[p];
			}
			str[p].resize(mx[p] + 1);
			for (int j = 2 * i; j < A; j += i) {
				not_prime[j] = true;
				if (seen[j]) {
					factors[j].pb(p);
				}
			}
			if (seen[i]) {
				factors[i].pb(p);
			}
			++p;
		}
	}
}

void dfs1(int u, int p) {
	parent[u][0] = p;
	depth[u] = depth[p] + 1;
	for (int i = 1; i < LOG; ++i) {
		parent[u][i] = parent[parent[u][i - 1]][i - 1];
	}
	for (auto &v : g[u]) {
		if (v != p) {
			dfs1(v, u);
		}
	}
}

void dfs2(int u, int p) {
	upd(a[u], 1);
	for (auto &q : queries[u]) {
		ll e_sum = 0;
		for (int i = 0; i <= q.e; ++i) {
			e_sum += str[q.p][i] * i;
		}
		for (int i = q.e + 1; i <= mx[q.p]; ++i) {
			e_sum += str[q.p][i] * q.e;
		}
		ll temp = pwr(prime[q.p], e_sum);
		if (q.idx < 0) {
			q.idx = -q.idx;
			temp = (temp * temp) % mod;
			temp = pwr(temp, mod - 2);
		}
		ans[q.idx] *= temp;
		ans[q.idx] %= mod;
	}
	for (auto &v : g[u]) {
		if (v != p) {
			dfs2(v, u);
		}
	}
	upd(a[u], -1);
}

void upd(int x, int ch) {
	for (auto &j : factors[x]) {
		int ctr = 0;
		while (x % prime[j] == 0) {
			x /= prime[j];
			++ctr;
		}
		str[j][ctr] += ch;
	}
}

int lca(int u, int v) {
	if (depth[v] > depth[u]) {
		swap(u, v);
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (depth[u] - depth[v] >= (1 << j)) {
			u = parent[u][j];
		}
	}
	if (u == v) {
		return u;
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (parent[u][j] != parent[v][j]) {
			u = parent[u][j];
			v = parent[v][j];
		}
	}
	return parent[u][0];
}

int pwr(ll x, int e) {
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