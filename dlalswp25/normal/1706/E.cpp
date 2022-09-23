#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M, Q;
vector<pii> adj[101010];
int A[101010];
int sz[101010];
int H[101010];
int dfn[101010];
int up[101010];
int vid;

struct DSU {
	int p[101010];

	void init(int n) {
		for(int i = 1; i <= n; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	bool unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return false;
		p[a] = b;
		return true;
	}
}uf;

struct SegTree {
	int T[4 * 101010];
	int base;

	void init(int n) {
		for(base = 1; base < n; base <<= 1);
		for(int i = 1; i < base + base; i++) T[i] = 0;
	}

	void upd(int p, int x) {
		p += base; p--;
		T[p] = x;
		while(p > 1) {
			p >>= 1;
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}

	int query(int p, int q) {
		if(q < p) return 0;
		p += base; q += base;
		p--; q--;
		int ret = 0;
		while(p <= q) {
			if(p & 1) ret = max(ret, T[p++]);
			if(~q & 1) ret = max(ret, T[q--]);
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}seg;

void dfs(int v, int p) {
	sz[v] = 1;
	up[v] = p;
	for(pii& i : adj[v]) {
		if(i.first == p) continue;
		dfs(i.first, v);
		sz[v] += sz[i.first];
		if(adj[v][0].first == p || sz[adj[v][0].first] < sz[i.first]) swap(adj[v][0], i);
	}
}

void hld(int v, int p, int c) {
	dfn[v] = ++vid;
	if(p) seg.upd(vid, c);
	for(pii& i : adj[v]) {
		if(i.first == p) continue;
		if(i == adj[v][0]) H[i.first] = H[v];
		else H[i.first] = i.first;
		hld(i.first, v, i.second);
	}
}

int query(int u, int v) {
	int ret = 0;
	while(H[u] != H[v]) {
		if(dfn[u] > dfn[v]) swap(u, v);
		ret = max(ret, seg.query(dfn[H[v]], dfn[v]));
		v = up[H[v]];
	}
	if(dfn[u] > dfn[v]) swap(u, v);
	return max(ret, seg.query(dfn[u] + 1, dfn[v]));
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &Q);
		for(int i = 1; i <= N; i++) adj[i].clear();

		uf.init(N);
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			if(uf.unite(a, b)) {
				adj[a].emplace_back(b, i);
				adj[b].emplace_back(a, i);
			}
		}

		dfs(1, 0);
		for(int i = 1; i <= N; i++) H[i] = 0;
		H[1] = 1; vid = 0;
		seg.init(N);
		hld(1, 0, 0);

		for(int i = 1; i < N; i++) {
			A[i] = query(i, i + 1);
		}
		seg.init(N);
		for(int i = 1; i <= N; i++) seg.upd(i, A[i]);

		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			printf("%d ", seg.query(l, r - 1));
		}
		puts("");
	}
	return 0;
}