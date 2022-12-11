#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int MAXN = 200010;
int n, head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN], tot, fa[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int xs[MAXN], ys[MAXN], dis[MAXN];
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
std::queue<int> q;
int bfs(int S) {
	for (int i = 1; i <= n; ++i) dis[i] = 0;
	q.push(S); dis[S] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i])
			if (!dis[to[i]]) {
				dis[to[i]] = dis[t] + 1;
				q.push(to[i]);
			}
	}
	int res = 1; for (int i = 2; i <= n; ++i) if (dis[i] > dis[res]) res = i;
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &val[i]), fa[i] = i;
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &xs[i], &ys[i]);
		if (val[xs[i]] == val[ys[i]]) fa[find(xs[i])] = find(ys[i]);
	}
	for (int i = 1; i != n; ++i) addedge(find(xs[i]), find(ys[i]));
	printf("%d\n", dis[bfs(bfs(find(1)))] >> 1);
	return 0;
}