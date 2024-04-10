#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define pb push_back
using namespace std;

const int maxn = 209;
int f[maxn][maxn], b[maxn], c[maxn], d[maxn], g[maxn][maxn];
vector<int> e[maxn];
int n, K, u, v;

void dfs(int u, int fa) {
	rep (i, 0, e[u].size()-1) if (e[u][i] != fa) dfs(e[u][i], u);
	rep (i, 1, n) {
		rep (j, 0, e[u].size()-1) if (e[u][j] != fa)
		f[u][i] += min(f[e[u][j]][i], f[e[u][j]][b[e[u][j]]] + K);
		// printf("%d %d %d\n", u, i, f[u][i]);
 	}
	b[u] = 1;
	rep (i, 2, n) if (f[u][i] < f[u][b[u]]) b[u] = i;
}

void dfs2(int u, int fa, int d) {
	c[u] = d;
	rep (i, 0, e[u].size()-1) if (e[u][i] != fa) 
		dfs2(e[u][i], u, (f[e[u][i]][d] < f[e[u][i]][b[e[u][i]]] + K ? d : b[e[u][i]]));
}

int main() {
	scanf("%d%d", &n, &K);
	rep (i, 1, n-1) scanf("%d", &d[i]);
	rep (i, 1, n) rep (j, 1, n) g[i][j] = (i != j) << 20;
	rep (i, 1, n-1) {
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
		e[u].pb(v); e[v].pb(u);
	}
	rep (k, 1, n) rep (i, 1, n) rep (j, 1, n)
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	rep (i, 1, n) rep (j, 1, n) f[i][j] = d[g[i][j]];
	dfs(1, 0); dfs2(1, 0, b[1]);
	printf("%d\n", f[1][b[1]] + K);
	rep (i, 1, n) printf("%d ", c[i]);
	return 0;
}