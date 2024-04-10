#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rd() {
	ll a = rng() & 2147483647;
	ll b = rng() & 2147483647;
	return a << 31 | b;
}

int N, Q;
int A[303030];
ll X[303030];
vector<int> adj[303030];
int H[303030];
int up[303030];
int sz[303030];
int dfn[303030];
int id;

struct Node {
	ll x = 0;
	int l = 0, r = 0;
};

struct PST {
	Node T[20 * 303030];
	int rt[303030] = {0, };
	int id = 0;

	int build(int bef, int s, int e, int p) {
		if(p < s || e < p) return bef;
		int now = ++id;
		if(s == e) {
			T[now].x = T[bef].x ^ X[s];
			return now;
		}
		int m = s + e >> 1;
		T[now].l = build(T[bef].l, s, m, p);
		T[now].r = build(T[bef].r, m + 1, e, p);
		T[now].x = T[T[now].l].x ^ T[T[now].r].x;
		return now;
	}

	void init(int v) {
		rt[v] = build(rt[up[v]], 1, N, A[v]);
		for(int i : adj[v]) {
			if(i == up[v]) continue;
			init(i);
		}
	}

	int get(int x, int y, int lca, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return -1;
		if(p <= s && e <= q) {
			ll z = (s <= A[lca] && A[lca] <= e ? X[A[lca]] : 0);
			ll t = T[x].x ^ T[y].x ^ z;
			if(!t) return -1;
			while(s != e) {
				int m = s + e >> 1;
				z = (s <= A[lca] && A[lca] <= m ? X[A[lca]] : 0);
				if(T[T[x].l].x ^ T[T[y].l].x ^ z) {
					e = m;
					x = T[x].l; y = T[y].l;
				}
				else {
					s = m + 1;
					x = T[x].r; y = T[y].r;
				}
			}
			return s;
		}
		int m = s + e >> 1;
		int t = get(T[x].l, T[y].l, lca, s, m, p, q);
		if(t != -1) return t;
		return get(T[x].r, T[y].r, lca, m + 1, e, p, q);
	}

	int query(int u, int v, int lca, int l, int r) {
		return get(rt[u], rt[v], lca, 1, N, l, r);
	}
}pst;

void dfs(int v, int p) {
	sz[v] = 1;
	up[v] = p;
	for(int& i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
		if(p == adj[v][0] || sz[adj[v][0]] < sz[i]) swap(i, adj[v][0]);
	}
}

void hld(int v) {
	dfn[v] = ++id;
	for(int i : adj[v]) {
		if(H[i]) continue;
		if(i == adj[v][0]) H[i] = H[v];
		else H[i] = i;
		hld(i);
	}
}

int lca(int a, int b) {
	while(H[a] != H[b]) {
		if(dfn[a] < dfn[b]) swap(a, b);
		a = up[H[a]];
	}
	return dfn[a] < dfn[b] ? a : b;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) X[i] = rd();
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0); H[1] = 1; hld(1);
	pst.init(1);

	while(Q--) {
		int u, v, l, r; scanf("%d%d%d%d", &u, &v, &l, &r);
		printf("%d\n", pst.query(u, v, lca(u, v), l, r));
	}
	return 0;
}