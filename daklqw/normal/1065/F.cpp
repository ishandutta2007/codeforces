#include <bits/stdc++.h>

const int MAXN = 1000010;
struct graph {
	int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
	void adde(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
	}
} g1, g2, g3;
int * head, * nxt, * to;
void setg(graph * x) {
	head = x->head, nxt = x->nxt, to = x->to;
}
int n, K;
int st[MAXN], top;
bool isl[MAXN];
void dfs(int u, int f = 0) {
	st[++top] = u;
	bool & hav = isl[u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f) {
			hav = false;
			dfs(to[i], u);
			g2.adde(u, to[i]);
		}
	if (hav) g2.adde(u, st[std::max(top - K, 1)]);
	--top;
}
bool ins[MAXN]; int dfn[MAXN], low[MAXN], t0t;
int val[MAXN], bel[MAXN], idx;
void tarjan(int u) {
	dfn[u] = low[u] = ++t0t;
	ins[st[++top] = u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]])
			low[u] = std::min(low[u], dfn[to[i]]);
	if (low[u] == dfn[u]) {
		int v; ++idx;
		do ins[v = st[top--]] = false, val[bel[v] = idx] += isl[v];
		while (v != u);
	}
}

int ind[MAXN], dp[MAXN];
std::queue<int> q;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 2, t; i <= n; ++i)
		std::cin >> t, g1.adde(t, i);
	setg(&g1); dfs(1);
	setg(&g2); tarjan(1);
	for (int u = 1; u <= n; ++u)
		for (int i = head[u]; i; i = nxt[i])
			if (bel[u] != bel[to[i]])
				++ind[bel[to[i]]], g3.adde(bel[u], bel[to[i]]);
	setg(&g3);
	q.push(bel[1]);
	int ans = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop(); dp[t] += val[t];
		for (int i = head[t]; i; i = nxt[i]) {
			if (!--ind[to[i]]) q.push(to[i]);
			dp[to[i]] = std::max(dp[to[i]], dp[t]);
		}
		ans = std::max(ans, dp[t]);
	}
	std::cout << ans << std::endl;
	return 0;
}