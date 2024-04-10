#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define loop(k,a) for (int k=(a); k; k=e[k].link)
using namespace std;
 
inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return op * x;
}
 
const int maxn = 400009;
struct edge { int v, link; } e[maxn*2];
int head[maxn], dfn[maxn], low[maxn], fa[maxn][20], bel[maxn];
int vis[maxn], stk[maxn], root[maxn], dep[maxn], A[maxn], B[maxn];
int n, m, Q, u, v, w, cnt, top, clk, res;
vector<int> g[maxn];
 
void addEdge(int u, int v) {
	e[++cnt].v = v; e[cnt].link = head[u]; head[u] = cnt;
}
 
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++clk; stk[++top] = u;
	loop (k, head[u])
		if (e[k].v != fa) 
			if (!dfn[e[k].v]) {
				tarjan(e[k].v, u);
				low[u] = min(low[u], low[e[k].v]);
			}
			else low[u] = min(low[u], dfn[e[k].v]);
		else fa = 0;
	if (dfn[u] != low[u]) return;
	vis[++res] = cnt;
	while (stk[top] != u) bel[stk[top--]] = res;
	bel[stk[top--]] = res;
}
 
void dfs(int u) {
	rep (i, 0, g[u].size()-1)
		if (g[u][i] != fa[u][0]) {
			dep[g[u][i]] = dep[u] + 1;
			fa[g[u][i]][0] = u;
			dfs(g[u][i]);
		}
}
 
void init() {
	rep (j, 1, 18)
		rep (i, 1, res)
			fa[i][j] = fa[fa[i][j-1]][j-1];
}
 
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int j=18; j>=0; j--)
		if (dep[fa[a][j]] >= dep[b]) a = fa[a][j];
	if (a == b) return a;
	for (int j=18; j>=0; j--)
		if (fa[a][j] != fa[b][j]) {
			a = fa[a][j]; b = fa[b][j];
		}
	return fa[a][0];
}
 
bool solve(int u, int fa) {
	rep (i, 0, g[u].size()-1)
		if (g[u][i] != fa) {
			if (!solve(g[u][i], u)) return false;
			A[u] += A[g[u][i]];
			B[u] += B[g[u][i]];
		}
	return !A[u] || !B[u];
}
 
int main() {
	n = read(); m = read(); Q = read();
	rep (i, 1, m) {
		u = read(); v = read();
		addEdge(u, v); addEdge(v, u);
	}
	cnt = 0;
	rep (i, 1, n) 
		if (!dfn[i]) {
			cnt++; tarjan(i, 0);
		}
	rep (i, 1, n) 
		loop (k, head[i])
			if (bel[i] != bel[e[k].v]) g[bel[i]].push_back(bel[e[k].v]);
	rep (i, 1, res)
		if (!root[vis[i]]) {
			root[vis[i]] = i;
			dep[i] = 1; dfs(i);
		}
	init();
	while (Q--) {
		u = bel[read()]; v = bel[read()];
		w = lca(u, v); 
		A[u]++; A[w]--; B[v]++; B[w]--;
	}
	rep (i, 1, cnt)
		if (!solve(root[i], 0)) {
			puts("No"); return 0;
		}
	puts("Yes");
	return 0; 
}