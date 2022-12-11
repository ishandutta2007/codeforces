#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 100010;
const int MAXP = MAXN * 51;
int xs[MAXN], ys[MAXN];
int head[MAXP], nxt[MAXP], to[MAXP], tot;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	// std::cout << "ADDEDGE " << b << " " << e << std::endl;
}
int n, m, D, t1, t2;
inline int getn(int x, int y) {
	return x + (y % D) * n;
}
char buf[MAXN][52];
int st[MAXP], ins[MAXP], dfn[MAXP], low[MAXP], idx, top;
int li[MAXN], bak; bool hav[MAXN];
void append(int x) {
	--x;
	const int id = x % n + 1, s = x / n;
	// printf("APPEND %d , %d %d %d\n", x + 1, id, s, buf[id][s] & 1);
	if (!hav[id] && (buf[id][s] & 1)) {
		// puts("APP");
		hav[id] = true;
		li[++bak] = id;
	}
}
void clear() {
	for (int i = 1; i <= bak; ++i) hav[li[i]] = false;
	bak = 0;
}
int bel[MAXP], deg[MAXP], sz[MAXP];
std::queue<int> q;
void tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	ins[st[++top] = u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]]) low[u] = std::min(low[u], dfn[to[i]]);
	if (low[u] == dfn[u]) {
		int v;
		// puts("-=--");
		do ins[v = st[top--]] = false, append(v), bel[v] = u; while (u != v) ;
		sz[u] = bak;
		clear();
	}
}
int dp[MAXP];

int main() {
	scanf("%d%d%d", &n, &m, &D);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", xs + i, ys + i);
		for (int j = 0; j != D; ++j)
			addedge(getn(xs[i], j), getn(ys[i], j + 1));
	}
	for (int i = 1; i <= n; ++i) scanf("%s", buf[i]);
	const int S = getn(1, 0);
	tarjan(S);
//	for (int i = 0; i <= n * m; ++i) printf("%d ", bel[i]); putchar(10);
//	for (int i = 0; i <= n * m; ++i) printf("%d ", sz[i]); putchar(10);
	memset(head, 0, sizeof head); tot = 0;
	//puts("A");
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j != D; ++j) {
			const int x = getn(xs[i], j), y = getn(ys[i], j + 1);
			if (!bel[x] || !bel[y]) continue;
			if (bel[x] != bel[y]) {
				addedge(bel[x], bel[y]);
				++deg[bel[y]];
			}
		}
	}
	q.push(getn(1, 0));
	int ans = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		ans = std::max(ans, dp[t] += sz[t]);
		for (int i = head[t]; i; i = nxt[i]) {
			dp[to[i]] = std::max(dp[to[i]], dp[t]);
			if (!--deg[to[i]]) q.push(to[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}