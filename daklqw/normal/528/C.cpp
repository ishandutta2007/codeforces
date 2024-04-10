#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN * 10], to[MAXN * 10], tot = 1;
int deg[MAXN];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
	++deg[b], ++deg[e];
}
int n, m;
bool vis[MAXN * 10];
int tl[MAXN * 10], tb;
void dfs(int u) {
	for (int & i = head[u]; i; i = nxt[i])
		if (!vis[i >> 1])
			vis[i >> 1] = true, dfs(to[i]);
	tl[++tb] = u;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, t1, t2; i <= m; ++i)
		std::cin >> t1 >> t2, addedge(t1, t2);
	static int li[MAXN], bak;
	for (int i = 1; i <= n; ++i) if (deg[i] & 1) li[++bak] = i;
	for (int i = 1; i <= bak; i += 2) addedge(li[i], li[i + 1]);
	if (tot >> 1 & 1) addedge(1, 1);
	std::cout << tot / 2 << '\n';
	dfs(1);
	for (int i = 1; i < tb; ++i) {
		int x = tl[i], y = tl[i + 1];
		if (i & 1) std::swap(x, y);
		std::cout << x << ' ' << y << '\n';
	}
	return 0;
}