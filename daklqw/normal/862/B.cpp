#include <stdio.h>
struct edge {int to, nxt; } e[201000];
int head[101000], tot, vis[101000];
int cnt[2], x, y, n;
void addedge(int a, int b) {e[++tot] = (edge) {b, head[a]}; head[a] = tot; }
void dfs(int x, int dep) {
	cnt[dep]++;
	for (int i = head[x]; i; i = e[i].nxt) 
		if (!vis[e[i].to]) {
			vis[e[i].to] = 1;
			dfs(e[i].to, dep ^ 1);
		}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d%d", &x, &y), addedge(x, y), addedge(y, x);
	vis[1] = 1; dfs(1, 0);
	printf("%I64d\n", 1LL * cnt[0] * cnt[1] - n + 1);
	return 0;
}