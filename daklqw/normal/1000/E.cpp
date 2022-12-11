#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 300010
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, xs[MAXN], ys[MAXN];
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
int st[MAXN], top, dfn[MAXN], low[MAXN], bel[MAXN], idx, t0t, n, m, t1, t2, dis[MAXN]; 
bool ins[MAXN];
void tarjan(int u, int fa) {
	ins[st[++top] = u] = true;
	dfn[u] = low[u] = ++t0t;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			if (!dfn[to[i]]) {
				tarjan(to[i], u);
				low[u] = min(low[u], low[to[i]]);
			} else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
		}
	if (low[u] == dfn[u]) {
		int v; ++idx;
		do ins[v = st[top--]] = false, bel[v] = idx; while (u != v);
	}
}
queue<int> q;
int bfs(int S) {
	memset(dis, -1, sizeof dis);
	dis[S] = 0; q.push(S);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i])
			if (!~dis[to[i]]) {
				dis[to[i]] = dis[t] + 1;
				q.push(to[i]);
			}
	}
	int res = 1;
	for (int i = 2; i <= idx; ++i) if (dis[i] > dis[res]) res = i;
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) { 
		scanf("%d%d", &xs[i], &ys[i]);
		addedge(xs[i], ys[i]);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, 0);
	memset(head, 0, sizeof head); tot = 0;
	for (int i = 1; i <= m; ++i) addedge(bel[xs[i]], bel[ys[i]]);
	printf("%d\n", dis[bfs(bfs(1))]);
	return 0;
}