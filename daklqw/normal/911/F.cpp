#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 200010
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, dis[MAXN], fa[MAXN];
bool vis[MAXN], is[MAXN];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
void bfs(int S) {
	memset(vis, 0, sizeof vis);
	queue<int> q; vis[S] = true; q.push(S); dis[S] = 0; fa[S] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i])
			if (!vis[to[i]]) {
				dis[to[i]] = dis[t] + 1;
				vis[to[i]] = true;
				fa[to[i]] = t;
				q.push(to[i]);
			}
	}
}
int n, t1, t2, anslx[MAXN], ansly[MAXN], bak, rt = 1, down = 1;
#define LL long long
LL ans;
inline int absx(int x) { return x < 0 ? -x : x; }
inline int D(int x, int y) { return absx(dis[x] - dis[y]); }
void dfs(int u, int add, int up) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u] && !is[to[i]]) {
			if (is[u]) {
				if (D(rt, u) > D(u, down)) dfs(to[i], rt, u);
				else dfs(to[i], down, u);
			} else dfs(to[i], add, up);
		}
	if (is[u]) {
		for (int i = head[u]; i; i = nxt[i])
			if (to[i] != fa[u] && is[to[i]])
				dfs(to[i], add, up);
	}
	++bak;
	anslx[bak] = u; ansly[bak] = add;
	ans += D(u, up) + D(up, add);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) scanf("%d%d", &t1, &t2), addedge(t1, t2);
	bfs(1);
	for (int i = 2; i <= n; ++i) if (dis[i] > dis[rt]) rt = i;
	bfs(rt);
	for (int i = 1; i <= n; ++i) if (dis[i] > dis[down]) down = i;
	int now = down;
	while (now) is[now] = true, now = fa[now];
	dfs(rt, rt, rt);
	printf("%lld\n", ans);
	for (int i = 1; i < bak; ++i)
		printf("%d %d %d\n", anslx[i], ansly[i], anslx[i]);
	return 0;
}