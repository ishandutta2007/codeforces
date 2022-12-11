#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
const int MAXNODE = MAXN << 2;
const int MAXEDGE = MAXNODE << 3;
int head[MAXNODE], nxt[MAXEDGE], to[MAXEDGE], val[MAXEDGE], cost[MAXEDGE], tot = 1;
inline void addedge(int b, int e, int v, int c) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v; cost[tot] = c;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = 0; cost[tot] = -c;
}
std::queue<int> q;
int dis[MAXNODE], S, T, pre[MAXNODE];
bool inq[MAXNODE];
bool spfa() {
	for (int i = S; i <= T; ++i) dis[i] = -INF; dis[S] = 0;
	q.push(S); inq[S] = true;
	while (!q.empty()) {
		int t = q.front(); q.pop(); inq[t] = false;
		for (int i = head[t]; i; i = nxt[i])
			if (val[i] && dis[to[i]] < dis[t] + cost[i]) {
				dis[to[i]] = dis[t] + cost[i];
				pre[to[i]] = i ^ 1;
				if (!inq[to[i]]) {
					inq[to[i]] = true;
					q.push(to[i]);
				}
			}
	}
	return dis[T] != -INF;
}
void MCMF() {
	int now = pre[T], minv = INF;
	while (now) {
		minv = std::min(minv, val[now ^ 1]);
		now = pre[to[now]];
	}
	now = pre[T];
	while (now) {
		val[now] += minv;
		val[now ^ 1] -= minv;
		now = pre[to[now]];
	}
}
int xs[MAXN], ys[MAXN], cs[MAXN], ts[MAXN], n, k, li[MAXN << 1], bak;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", xs + i, ys + i, cs + i);
		ys[i] += xs[i];
		li[++bak] = xs[i];
		li[++bak] = ys[i];
	}
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	int S = 0; T = bak + 1;
	for (int i = 1; i != bak; ++i) addedge(i, i + 1, INF, 0);
	addedge(S, 1, k, 0); addedge(bak, T, k, 0);
	for (int i = 1; i <= n; ++i) {
		ts[i] = tot + 1;
		xs[i] = std::lower_bound(li + 1, li + 1 + bak, xs[i]) - li;
		ys[i] = std::lower_bound(li + 1, li + 1 + bak, ys[i]) - li;
		addedge(xs[i], ys[i], 1, cs[i]);
	}
	while (spfa()) MCMF();
	for (int i = 1; i <= n; ++i) putchar(!val[ts[i]] + 48), putchar(32);
	putchar(10);
	return 0;
}