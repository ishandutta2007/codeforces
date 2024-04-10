#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 100009;
int dfn[maxn], low[maxn], bel[maxn], stk[maxn];
int size[maxn], vis[maxn], f[maxn], flag[2009][2009];
int n, m, a, b, clk, res, top, cnt, ans, best;
vector<int> e[maxn], g[maxn];

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++clk;
	stk[++top] = u;
	rep (i, 0, e[u].size()-1)
		if (e[u][i] != fa) {
			if (!dfn[e[u][i]]) {
				tarjan(e[u][i], u);
				low[u] = min(low[u], low[e[u][i]]);
			}
			else low[u] = min(low[u], dfn[e[u][i]]);
		}
		else fa = 0;
	if (dfn[u] != low[u]) return;
	size[cnt]++; res++;
	while (stk[top] != u)
		bel[stk[top--]] = res;
	bel[stk[top--]] = res;
}

void dfs(int u) {
	vis[u] = 1;
	if (g[u].size() == 1) { ans--; return; }
	int mx1 = 0, mx2 = 0;
	rep (i, 0, g[u].size()-1)
		if (!vis[g[u][i]]) {
			dfs(g[u][i]);
			if (f[g[u][i]] > mx1) { mx2 = mx1; mx1 = f[g[u][i]]; }
			else if (f[g[u][i]] > mx2) mx2 = f[g[u][i]];
		}
	best = max(best, mx1 + mx2 + 1);
	f[u] = mx1 + 1;
}

int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, m) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b); e[b].push_back(a);
	}
	rep (i, 1, n)
		if (!dfn[i]) {
			cnt++; tarjan(i, 0);
			if (size[cnt] >= 3) ans += size[cnt];
		}
	ans += n - res + cnt - 1;
	rep (i, 1, n) rep (j, 0, e[i].size()-1)
		if (!flag[bel[i]][bel[e[i][j]]] && bel[i] != bel[e[i][j]]) {
			g[bel[i]].push_back(bel[e[i][j]]);
			g[bel[e[i][j]]].push_back(bel[i]);
			flag[bel[i]][bel[e[i][j]]] = 1;
			flag[bel[e[i][j]]][bel[i]] = 1;
		}
	rep (i, 1, res)
		if (!vis[i] && g[i].size() >= 2) {
			best = 0; dfs(i); ans -= best; 
		}
	printf("%d\n", ans);
	return 0;
}