#include <bits/stdc++.h>

const int MAXN = 1010;
const int mod = 2520;
void reduce(int & x) { x += x >> 31 & mod; }
int A[MAXN], out[MAXN][10], M[MAXN], n;
bool vis[MAXN][mod], ins[MAXN][mod];
int dp[MAXN][mod], deb;
bool hav[MAXN]; int li[MAXN], bak;
int to[MAXN][mod];
int calc(int u, int v) {
	reduce(v += A[u] - mod);
	if (vis[u][v]) return dp[u][v];
	to[u][v] = out[u][v % M[u]];
	ins[u][v] = vis[u][v] = true;
	if (ins[to[u][v]][(v + A[to[u][v]]) % mod]) {
		static int x, y, i;
		x = u, y = v;
		do {
			if (!hav[x]) li[++bak] = x, hav[x] = true;
			x = out[x][y % M[x]], reduce(y += A[x] - mod);
		} while (x != u || y != v);
		dp[u][v] = bak;
		for (i = 1; i <= bak; ++i) hav[li[i]] = false;
		bak = 0;
	} else dp[u][v] = calc(to[u][v], v);
	ins[u][v] = false;
	return dp[u][v];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], reduce(A[i] %= mod);
	for (int i = 1; i <= n; ++i) {
		std::cin >> M[i];
		for (int j = 0; j < M[i]; ++j)
			std::cin >> out[i][j];
	}
	int Q; std::cin >> Q;
	while (Q --> 0) {
		int u, v;
		std::cin >> u >> v; reduce(v %= mod);
		std::cout << calc(u, v) << '\n';
	}
	return 0;
}