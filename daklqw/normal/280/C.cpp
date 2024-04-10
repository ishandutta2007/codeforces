#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100010
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, t1, t2, n;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
double ans = 0;
void dfs(int u, int fa, int dep) {
	ans += 1. / dep;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			dfs(to[i], u, dep + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		addedge(t1, t2);
	}
	dfs(1, 0, 1);
	printf("%.15lf\n", ans);
	return 0;
}