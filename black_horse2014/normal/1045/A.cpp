//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 100000;
const int M = 1000000;

namespace Dinic {
	typedef int F;
	const F INF = 1e9+1e8;

	int fst[N], nxt[M], to[M];
	F cap[M];
	int dis[N], q[N], ptr[N];
	int V, E;

	void init() {
		memset(fst, -1, sizeof fst);
		V = E = 0;
	}
	inline int add_node() { V++; return V-1; }
	inline void add_edge(int u, int v, F c) {
		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
	}
	inline bool bfs(int S, int T, int n) {
		memset(dis, -1, sizeof(int) * n);
		int h = 0, t = 0;
		dis[S] = 0, q[t++] = S;
		while (h < t) {
			int u = q[h++];
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {
				dis[to[e]] = dis[u] + 1, q[t++] = to[e];
				if (to[e] == T) return 1;
			}
		}
		return (dis[T] != -1);
	}
	F dfs(int u, int T, F f) {
		if (u == T) return f;
		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {
			F ret = dfs(to[e], T, min(f, cap[e]));
			if (ret > 0) {
				cap[e] -= ret, cap[e ^ 1] += ret;
				return ret;
			}
		}
		return 0;
	}
	F max_flow(int S, int T, int n = V) {
		F ret = 0;
		while (bfs(S, T, n)) {
			memcpy(ptr, fst, sizeof(int) * n);
			for (F cur; (cur = dfs(S, T, INF)) > 0; ret += cur);
		}
		return ret;
	}
}

using Dinic::E;
using Dinic::cap;
using Dinic::to;

int add_node() {
	return Dinic::add_node();
}

void add(int u, int v, int c) {
	Dinic::add_edge(u, v, c);
}

int sid[N], wid[N], chk[N], a[N][3], w[N], st[N], en[N], node[N], vis[N], okay[N], V;
vector<int> v[N], adj[N], radj[N];

void build(int u, int l, int r) {
	if (l == r) {
		st[l] = add_node();
		en[l] = add_node();
		add(st[l], en[l], 1);
		node[u] = st[l];
		return;
	}
	int mid = l + r >> 1;
	node[u] = add_node();
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	add(node[u], node[u + u], 100000);
	add(node[u], node[u + u + 1], 100000);
}

void insert(int u, int l, int r, int ll, int rr, int cur) {
	if (ll <= l && r <= rr) {
		add(cur, node[u], 1);
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) insert(u + u, l, mid, ll, rr, cur);
	if (mid < rr) insert(u + u + 1, mid + 1, r, ll, rr, cur);
}

int op[N], l[N], r[N];
int used[N], sel[N];

int find(int u) {
	vis[u] = V;
	if (okay[u] && !sel[u]) {
		sel[u] = 1;
		return u;
	}
	for (int v : adj[u]) {
		if (vis[v] == V) continue;
		int ret = find(v);
		if (ret >= 0) return ret;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> op[i];
		if (op[i] == 0) {
			int c; cin >> c; v[i].resize(c);
			for (int j = 0; j < c; j++) cin >> v[i][j];
		} else if (op[i] == 1) {
			cin >> l[i] >> r[i];
		} else {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			chk[a[i][0]] = chk[a[i][1]] = chk[a[i][2]] = i;
		}
	}
	Dinic::init();
	int S = add_node();
	int T = add_node();
	build(1, 1, m);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		w[i] = add_node();
		if (op[i] == 0) {
			add(S, w[i], 1);
			for (int t : v[i]) add(w[i], st[t], 1);
		} else if (op[i] == 1) {
			add(S, w[i], 1);
			insert(1, 1, m, l[i], r[i], w[i]);
		} else {
			add(w[i], T, 1);
			tot += 2;
			for (int j = 0; j < 3; j++) add(en[a[i][j]], w[i], 1);
		}
	}
	for (int i = 1; i <= m; i++) if (!chk[i]) add(en[i], T, 1);
	tot += Dinic::max_flow(S, T);
	for (int i = 0; i < E; i += 2) {
		int u = to[i^1], v = to[i], w = cap[i^1];
		if (!w) continue;
		if (u == S) {
			used[v] = 1;
		} else if (v == T) {
			okay[u] = 1;
		} else {
			adj[u].push_back(v);
			radj[v].push_back(u);
		}
	}
	for (int i = 1; i <= m; i++) sid[en[i]] = i;
	for (int i = 1; i <= n; i++) wid[w[i]] = i;
	vector<pair<int, int> > ans;
	for (int i = 1; i <= n; i++) if (op[i] == 0 && used[w[i]]) {
		V++;
		int j = find(w[i]);
		if (sid[j] > 0 && sid[j] <= m) {
			ans.emplace_back(i, sid[j]);
			continue;
		}
		int k = sid[radj[j][0]];
		chk[k] = 0;
		ans.emplace_back(i, k);
	}
	vector<int> ret;
	for (int i = 1; i <= n; i++) if (op[i] == 1 && used[w[i]]) ret.push_back(i);
	memset(sel, 0, sizeof sel);
	for (auto t : ans) sel[t.second] = 1;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= m; i++) if (!sel[i] && adj[st[i]].size() > 0 && adj[st[i]][0] == en[i]) {
		int k = -1;
		for (int j : ret) {
			if (l[j] <= i && i <= r[j] && !vis[j]) {
				if (k == -1 || r[k] > r[j]) {
					k = j;
				}
			}
		}
		assert(k >= 0);
		vis[k] = 1;
		ans.emplace_back(k, i);
		sel[i] = 1;
		chk[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (op[i] != 2) continue;
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			int u = a[i][j];
			if (!chk[u]) continue;
			cnt++;
			ans.emplace_back(i, a[i][j]);
			if (cnt == 2) break;
		}
	}
	cout << tot << endl;
	for (auto t : ans) cout << t.first << ' ' << t.second << endl;
	return 0;
}