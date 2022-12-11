#include <bits/stdc++.h>

const int MAXN = 800010;
const int L = 200000;
int head[MAXN], nxt[MAXN], to[MAXN], vis[MAXN], tot = 1;
int col[MAXN], n, t1, t2, deg[MAXN];
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
void dfs(int u) {
	for (int & i = head[u]; i; i = nxt[i])
		if (!vis[i >> 1]) {
			vis[i >> 1] = true;
			col[i >> 1] = u <= L;
			dfs(to[i]);
		}
}
int tl[MAXN], bak;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> t1 >> t2;
		t2 += L;
		++deg[t1], ++deg[t2];
		addedge(t1, t2);
	}
	for (int i = 1; i <= L * 2; ++i)
		if (deg[i] & 1) tl[++bak] = i;
	for (int i = 1; i <= bak; i += 2)
		addedge(tl[i], tl[i + 1]);
	for (int i = 1; i <= L * 2; ++i) dfs(i);
	for (int i = 1; i <= n; ++i)
		std::cout << (col[i] ? 'b' : 'r');
	std::cout << std::endl;
	return 0;
}