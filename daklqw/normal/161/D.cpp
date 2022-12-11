#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int MAXN = 50010;
LL ans;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, t1, t2;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
int sz[MAXN], li[MAXN], n, K, rtv, sznow, rt, bak, ls[MAXN]; bool vis[MAXN], use[MAXN];
void getroot(int u, int fa) {
	sz[u] = 1;
	int maxn = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]]) {
			getroot(to[i], u);
			sz[u] += sz[to[i]];
			maxn = std::max(maxn, sz[to[i]]);
		}
	maxn = std::max(maxn, sznow - sz[u]);
	if (maxn < rtv) rtv = maxn, rt = u;
}
void dfs(int u, int fa, int d) {
	if (d > K) return ;
	++li[d]; ls[++bak] = d;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]])
			dfs(to[i], u, d + 1);
}
LL calc(int u, int d) {
	bak = 0;
	dfs(u, 0, d);
	LL res = 0;
	for (int i = 1; i <= bak; ++i) if (!use[ls[i]]) {
		use[ls[i]] = true;
		if (ls[i] > K - ls[i]) res += static_cast<LL> (li[ls[i]]) * li[K - ls[i]];
		else if ((ls[i] << 1) == K) res += static_cast<LL> (li[ls[i]]) * (li[ls[i]] - 1) / 2;
	}
	for (int i = 1; i <= bak; ++i) use[ls[i]] = li[ls[i]] = 0;
	return res;
}
void solve(int u) {
	vis[u] = true;
	ans += calc(u, 0);
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]]) {
			ans -= calc(to[i], 1);
			sznow = sz[to[i]];
			rtv = 0x3f3f3f3f;
			getroot(to[i], 0);
			solve(rt);
		}
}
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i != n; ++i) scanf("%d%d", &t1, &t2), addedge(t1, t2);
	sznow = n; rtv = 0x3f3f3f3f; getroot(1, 0); solve(rt);
	printf("%lld\n", ans);
	return 0;
}