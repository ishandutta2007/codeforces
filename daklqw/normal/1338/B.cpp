#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
int deg[MAXN], hav[MAXN];
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
	++deg[b], ++deg[e];
}
int n;
bool dfs(int u, int dep = 0, int fa = 0) {
	bool res = false;
	if (deg[u] == 1 && (dep & 1)) res = true;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			res |= dfs(to[i], dep + 1, u);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	int rt = 0;
	for (int i = 1; i <= n; ++i) if (deg[i] == 1) {
		rt = i;
		++hav[to[head[i]]];
	}
	int ansl, ansr;
	ansl = dfs(rt) ? 3 : 1;
	ansr = n - 1;
	for (int i = 1; i <= n; ++i) ansr -= std::max(hav[i] - 1, 0);
	std::cout << ansl << ' ' << ansr << std::endl;
	return 0;
}