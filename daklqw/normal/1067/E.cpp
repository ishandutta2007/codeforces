#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 500010;
const int Dollar1 = 998244353;
const int INV2 = (Dollar1 + 1) / 2;
typedef long long LL;
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline void mulr(int & x, const int y) { x = static_cast<LL> (x) * y % Dollar1; }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int f[MAXN];
void dfs(int u, int fa) {
 	int prod = 1;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa) {
		dfs(to[i], u);
		mulr(prod, mul(up(f[to[i]] + 1), INV2));
	}
	f[u] = up(Dollar1 + 1 - prod);
}
int n, t1, t2;
int main() {
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		addedge(t1, t2);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = up(ans + f[i]);
	for (int i = 1; i <= n; ++i) mulr(ans, 2);
	printf("%d\n", ans);
	return 0;
}