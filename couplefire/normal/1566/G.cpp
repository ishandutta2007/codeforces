#include <bits/stdc++.h>

typedef long long ll;

const int N = 100010, W = N * 2;

namespace Disc {
	int sz;
	int v[W];
	void pb(int x) { v[++sz] = x; }
	void init() { std::sort(v + 1, v + sz + 1); }
	int query(int x) { return std::lower_bound(v + 1, v + sz + 1, x) - v; }
}

struct Node {
	int ls, rs, cnt;
} P[N * 140];
int top;

void change(int o, int k, int x) {
	k = Disc::query(k);
	int l = 1, r = W;
	while (l != r) {
		P[o].cnt += x;
		int mid = (l + r) >> 1;
		if (k <= mid) {
			if (!P[o].ls) P[o].ls = ++top;
			r = mid; o = P[o].ls;
		} else {
			if (!P[o].rs) P[o].rs = ++top;
			l = mid + 1; o = P[o].rs;
		}
	}
	P[o].cnt += x;
}
int locate(int o, int p, int q) {
	int l = 1, r = W;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (P[P[o].ls].cnt != P[P[p].ls].cnt + P[P[q].ls].cnt) {
			o = P[o].ls; p = P[p].ls; q = P[q].ls;
			r = mid;
		} else {
			o = P[o].rs; p = P[p].rs; q = P[q].rs;
			l = mid + 1;
		}
	}
	return Disc::v[l];
}

int rt[N];

std::set<std::tuple<int, int, int>> edges;
std::map<std::pair<int, int>, int> map;
std::multiset<ll> sums;
std::multiset<int> adj[N];

void adjust(int u, int sgn) {
	if (adj[u].size() >= 3) {
		ll val = 0; auto it = adj[u].begin();
		for (int rep = 0; rep != 3; ++rep) val += *it++;
		if (sgn == 1) sums.insert(val);
		else { sums.erase(sums.find(val)); }
	}
}

void insert(int u, int v, int w) {
	edges.insert(std::make_tuple(w, u, v));
	map.insert(std::make_pair(std::make_pair(u, v), w));
	adjust(u, -1); adjust(v, -1);
	adj[u].insert(w); adj[v].insert(w);
	adjust(u, 1); adjust(v, 1);
	change(rt[u], w, 1); change(rt[v], w, 1); change(rt[0], w, 1);
}
void erase(int u, int v) {
	auto it = map.find(std::make_pair(u, v));
	int w = it->second; map.erase(it);
	edges.erase(std::make_tuple(w, u, v));
	adjust(u, -1); adjust(v, -1);
	adj[u].erase(adj[u].find(w)); adj[v].erase(adj[v].find(w));
	adjust(u, 1); adjust(v, 1);
	change(rt[u], w, -1); change(rt[v], w, -1); change(rt[0], w, -1);
}
ll query() {
	ll ans = std::numeric_limits<ll>::max();
	if (!sums.empty()) ans = *sums.begin();
	int rep = 0;
	for (auto it = edges.begin(); rep != 4; ++it, ++rep) {
		int w, u, v; std::tie(w, u, v) = *it;
		change(rt[0], w, 1);
		if (P[rt[u]].cnt + P[rt[v]].cnt != P[rt[0]].cnt)
			ans = std::min(ans, (ll)w + locate(rt[0], rt[u], rt[v]));
		change(rt[0], w, -1);
	}
	return ans;
}

int mu[N], mv[N], mw[N];
int qu[N], qv[N], qw[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int n, m; std::cin >> n >> m;
	for (int i = 0; i <= n; ++i) rt[i] = ++top;
	for (int i = 1; i <= m; ++i) {
		int u, v, w; std::cin >> mu[i] >> mv[i] >> mw[i];
		if (mu[i] > mv[i]) std::swap(mu[i], mv[i]);
		Disc::pb(mw[i]);
	}
	int q; std::cin >> q;
	for (int i = 1; i <= q; ++i) {
		std::cin >> qw[i] >> qu[i] >> qv[i];
		if (qu[i] > qv[i]) std::swap(qu[i], qv[i]);
		if (qw[i]) { std::cin >> qw[i]; Disc::pb(qw[i]); }
	}
	Disc::init();
	for (int i = 1; i <= m; ++i) insert(mu[i], mv[i], mw[i]);
	std::cout << query() << '\n';
	for (int i = 1; i <= q; ++i) {
		if (qw[i]) insert(qu[i], qv[i], qw[i]);
		else erase(qu[i], qv[i]);
		std::cout << query() << '\n';
	}

	return 0;
}