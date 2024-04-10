#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 19;
const int M = 19;

struct Lca {
	vector<int> g[N];
	int dep[N], up[N][M];
	void add(int a, int b) {
		g[a].pb(b); g[b].pb(a);
	}
	void dfs(int v = 1, int p = 0) {
		dep[v] = dep[p] + 1;
		up[v][0] = p;
		rep(i, 1, M - 1)
			up[v][i] = up[up[v][i - 1]][i - 1];
		for (auto u : g[v])
			if (u != p)	
				dfs(u, v);
	}
	int lca(int a, int b) {
		if (dep[a] < dep[b]) swap(a, b);
		per(i, 0, M - 1)
			if (dep[up[a][i]] >= dep[b])
				a = up[a][i];
		if (a == b) return a;
		per(i, 0, M - 1)
			if (up[a][i] != up[b][i])
				a = up[a][i], b = up[b][i];
		return up[a][0];
	}
} T;	

#define ull unsigned long long

const int W = 1 << 25;

int L[W], R[W], id[W], cnt;
ull x[W];

int build(int l = 0, int r = N - 1) {
	int v = cnt++;
	if (l == r) return v;
	int m = (l + r) / 2;
	L[v] = build(l, m);
	R[v] = build(m + 1, r);
	return v;
}

int add(int u, int p, ull val, int l = 0, int r = N - 1) {
	int v = cnt++;
	L[v] = L[u]; R[v] = R[u]; x[v] = (x[u] ^ val);
	if (l == r) return v;
	int m = (l + r) / 2;
	if (p <= m) L[v] = add(L[u], p, val, l, m);
	else R[v] = add(R[u], p, val, m + 1, r);
	return v;
}	

int query(int u1, int u2, int u3, int u4, int a, int b, int l = 0, int r = N - 1) {
	if ((x[u1] ^ x[u2] ^ x[u3] ^ x[u4]) == 0) return -1;
	if (l == r) return l;
	int m = (l + r) / 2;
	int ans = -1;
	if (a <= m) ans = query(L[u1], L[u2], L[u3], L[u4], a, b, l, m);
	if (ans == -1 && b > m) ans = query(R[u1], R[u2], R[u3], R[u4], a, b, m + 1, r);
	return ans;
}

int n, q, a[N];
ull ran[N];
vector<int> g[N];

void dfs(int v = 1, int p = 0) {
	id[v] = add(id[p], a[v], ran[a[v]]);
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
}

int main() {
	srand(time(0));
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) rep(j, 0, 60) ran[i] = 2 * ran[i] + rand() % 2;
	rep(i, 2, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		T.add(a, b);
	}
	T.dfs();
	id[0] = build();
	dfs();
	while (q--) {
		int a, b, l, r;
		scanf("%d%d%d%d", &a, &b, &l, &r);
		int c = T.lca(a, b);
		int d = T.up[c][0];
		printf("%d\n", query(id[a], id[b], id[c], id[d], l, r));
	}
	return 0;
}