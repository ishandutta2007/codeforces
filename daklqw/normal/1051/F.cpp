#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot, n, m;
inline void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = v;
}
int xs[30], ys[30], ds[30], Fa[MAXN], bak, t1, t2, t3, Q, li[MAXN], bak2;
int find(int x) { return Fa[x] == x ? x : Fa[x] = find(Fa[x]); }
int fa[17][MAXN], dep[MAXN]; LL dis[17][MAXN];
void dfs(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[0][u]) {
			fa[0][to[i]] = u;
			dep[to[i]] = dep[u] + 1;
			dis[0][to[i]] = val[i];
			dfs(to[i]);
		}
}
LL query(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y); LL res = 0;
	for (int t = dep[x] - dep[y]; t; t -= t & -t) { int tz = __builtin_ctz(t & -t); res += dis[tz][x]; x = fa[tz][x]; }
	for (int i = 16; ~i; --i) if (fa[i][x] != fa[i][y]) res += dis[i][x] + dis[i][y], x = fa[i][x], y = fa[i][y];
	return x == y ? res : res + dis[0][x] + dis[0][y];
}
LL map[50][50], dt1[50], dt2[50];
inline int fnd(int x) { return lower_bound(li + 1, li + 1 + bak2, x) - li; }
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) Fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &t1, &t2, &t3);
		if (find(t1) == find(t2)) ++bak, xs[bak] = t1, ys[bak] = t2, ds[bak] = t3;
		else addedge(t1, t2, t3), Fa[find(t1)] = find(t2);
	}
	for (int i = 1; i <= bak; ++i) li[++bak2] = xs[i], li[++bak2] = ys[i];
	sort(li + 1, li + 1 + bak2);
	bak2 = unique(li + 1, li + 1 + bak2) - li - 1;
	dfs(1);
	memset(map, 0x3f, sizeof map);
	for (int i = 1; i != 17; ++i)
		for (int j = 1; j <= n; ++j)
			fa[i][j] = fa[i - 1][fa[i - 1][j]], dis[i][j] = dis[i - 1][j] + dis[i - 1][fa[i - 1][j]];
	for (int i = 1; i <= bak; ++i) xs[i] = fnd(xs[i]), ys[i] = fnd(ys[i]), map[xs[i]][ys[i]] = map[ys[i]][xs[i]] = min(map[xs[i]][ys[i]], static_cast<LL> (ds[i]));
	for (int i = 1; i <= bak2; ++i)
		for (int j = 1; j <= bak2; ++j)
			map[i][j] = min(map[i][j], query(li[i], li[j]));
	for (int k = 1; k <= bak2; ++k)
		for (int i = 1; i <= bak2; ++i)
			for (int j = 1; j <= bak2; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	scanf("%d", &Q);
	while (Q --> 0) {
		scanf("%d%d", &t1, &t2);
		for (int i = 1; i <= bak2; ++i) dt1[i] = query(t1, li[i]);
		for (int i = 1; i <= bak2; ++i) dt2[i] = query(t2, li[i]);
		LL ans = 0x3f3f3f3f3f3f3f3fLL;
		for (int i = 1; i <= bak2; ++i)
			for (int j = 1; j <= bak2; ++j)
				ans = min(ans, dt1[i] + map[i][j] + dt2[j]);
		ans = min(ans, query(t1, t2));
		printf("%lld\n", ans);
	}
	return 0;
}