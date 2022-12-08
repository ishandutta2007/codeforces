#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.6e5 + 10;
int n, top;
struct Edge {
	int to, nxt;
	inline Edge() {}
	inline Edge(int to, int nxt) : to(to), nxt(nxt) {}
} E[maxn];
int fir[maxn], f[maxn];
int sz[maxn], son[maxn], tot[maxn];
long long Ans;
inline void add(int x, int y) {
	E[++top] = Edge(y, fir[x]); fir[x] = top;
}
void dfs(int x, int fa) {
	sz[x] = 1; f[x] = fa;
	for (int i = fir[x]; i; i = E[i].nxt) {
		int v = E[i].to;
		if (v == fa) continue;
		dfs(v, x); sz[x] += sz[v];
	}
}
inline long long calc_chain(int x) {
	return 1ll * x * (x - 1) / 2;
}
inline long long calc(int x) {
	long long now = 1ll * sz[x] * sz[x];
	for (int i = fir[x]; i; i = E[i].nxt) {
		int v = E[i].to;
		if (v == f[x]) continue;
		now -= 1ll * sz[v] * sz[v];
	}
	now = (now - 1) / 2;
	return now * now + 2 * now * sz[x] * (n - sz[x]);
}
int main() {
//	freopen(".in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs(1, 0); 
	Ans = (1ll * sz[1] * (sz[1] - 1) / 2) * (1ll * sz[1] * (sz[1] - 1) / 2);
	for (int i = 1; i <= n; ++i) {
		Ans -= calc(i);
	}
	printf("%lld\n", Ans);
	return 0;
}