#include <bits/stdc++.h>

const int MAXN = 1010;
typedef long long LL;
struct _ {
	int to, nxt;
} gr[MAXN << 2];
int head[MAXN], tot;
void adde(int b, int e) {
	gr[++tot] = (_) {e, head[b]}, head[b] = tot;
	gr[++tot] = (_) {b, head[e]}, head[e] = tot;
}
int dfs(int u, int fa = 0) {
	int res = 1;
	for (int i = head[u]; i; i = gr[i].nxt)
		if (gr[i].to != fa)
			res += dfs(gr[i].to, u);
	return res;
}
int n;
int A[MAXN], cur, delta;
void dfs2(int u, int fa = 0) {
	A[u] = cur += delta;
	// std::cerr << "DBG " << u << ' ' << A[u] << std::endl;
	int out = std::min(A[u] - A[fa], 1000000);
	std::cout << u << ' ' << fa << ' ' << out << '\n';
	for (int i = head[u]; i; i = gr[i].nxt)
		if (gr[i].to != fa)
			dfs2(gr[i].to, u);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	if (n == 1) return 0;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	int tar = n * n * 2 / 9;
	std::vector<int> li, la, lb;
	for (int u = 1; u <= n; ++u) {
		li.clear();
		for (int i = head[u]; i; i = gr[i].nxt)
			li.push_back(dfs(gr[i].to, u));
		if (*std::max_element(li.begin(), li.end()) * 2 > n) continue;
		int SA = 0, SB = 0;
		for (int i = head[u], j = 0; i; i = gr[i].nxt, ++j)
			if (SA < SB) SA += li[j], la.push_back(gr[i].to);
			else SB += li[j], lb.push_back(gr[i].to);
		std::cerr << "OK " << u << std::endl;
		delta = 1; cur = 0;
		for (auto t : la) dfs2(t, u);
		delta = std::min(cur + delta, 1000000);
		cur = 0;
		for (auto t : lb) dfs2(t, u);
		return 0;
	}
	std::cout << "DDDAK" << std::endl;
	return 0;
}