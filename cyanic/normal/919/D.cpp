#include<bits/stdc++.h>
using namespace std;

const int maxn = 600005;
int dfn[maxn], low[maxn], bel[maxn], stk[maxn];
int f[maxn][26], in[maxn], q[maxn];
int n, m, x, y, clk, top, res, ans, u, l, r;
vector<int> e[maxn];
char s[maxn];

void tarjan(int u) {
	dfn[u] = low[u] = ++clk; stk[++top] = u;
	for (auto v : e[u])
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!bel[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] != dfn[u]) return;
	res++;
	while (stk[top] != u) 
		bel[stk[top--]] = res;
	bel[stk[top--]] = res;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i=1; i<=m; i++) {
		scanf("%d%d", &x, &y);
		if (x == y) { puts("-1"); return 0; }
		e[x].push_back(y); in[y]++;
	}
	for (int i=1; i<=n; i++)
		if (!dfn[i]) tarjan(i);
	if (res < n) { puts("-1"); return 0; }
	for (int i=1; i<=n; i++)
		if (!in[i]) q[r++] = i;
	while (l < r) {
		u = q[l++];
		for (int i=0; i<=25; i++) {
			if (s[u] == 'a' + i) f[u][i]++;
			ans = max(ans, f[u][i]);
		}
		for (auto v : e[u]) {
			for (int i=0; i<=25; i++)
				f[v][i] = max(f[v][i], f[u][i]);
			in[v]--; if (!in[v]) q[r++] = v;
		}
	}
	printf("%d\n", ans);
	return 0;
}