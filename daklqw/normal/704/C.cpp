#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 1000000007;
typedef long long LL;
typedef std::pair<int, int> pi;
inline int absx(int x) { return x < 0 ? -x : x; }
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int x, int y) { return (LL) x * y % mod; }
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot = 1;
int deg[MAXN], vis[MAXN];
int ls[MAXN << 1], rs[MAXN << 1];
std::vector<int> self[MAXN];
void addedge(int b, int e, int l, int r) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; ls[tot] = l; rs[tot] = r;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; ls[tot] = r; rs[tot] = l;
	++deg[b]; ++deg[e];
}
int path[MAXN], edge[MAXN], bak, idx;
void dfs(int u, int fa = 0) {
	if (vis[u]) return ;
	vis[u] = true;
	path[++bak] = u;
	for (int i = head[u]; i; i = nxt[i])
		if ((i >> 1) != (fa >> 1))
			edge[++idx] = i, dfs(to[i], i);
}
pi operator + (pi a, pi b) {
	reduce(a.first += b.first - mod);
	reduce(a.second += b.second - mod);
	return a;
}
pi operator * (pi a, pi b) {
	return pi(((LL) a.first * b.first + (LL) a.second * b.second) % mod,
			  ((LL) a.second * b.first + (LL) a.first * b.second) % mod);
}
int f[MAXN][2][2];
inline int get(int x, int y) {
	int res = 0;
	for (auto t : self[x])
		if (t < 0) res ^= 1 - y; else res ^= y;
	return res;
}
pi dp(int scan, int tcan) {
	memset(f, 0, (bak + 2) * (sizeof f[0]));
	f[1][0][0 ^ get(path[1], 0)] += scan & 1;
	f[1][1][0 ^ get(path[1], 1)] += scan >> 1;
	for (int i = 1; i < bak; ++i) {
		int L = ls[edge[i]], R = rs[edge[i]];
		for (int j = 0; j != 2; ++j)
		for (int k = 0; k != 2; ++k)
		for (int l = 0; l != 2; ++l) {
			int can = ((L < 0) == (j == 0)) || ((R < 0) == (l == 0));
			can ^= get(path[i + 1], l);
			reduce(f[i + 1][l][k ^ can] += f[i][j][k] - mod);
		}
	}
	int lhs = 0, rhs = 0;
	for (int i = 0; i != 2; ++i) if (tcan >> i & 1) {
		reduce(lhs += f[bak][i][0] - mod);
		reduce(rhs += f[bak][i][1] - mod);
	}
	return pi(lhs, rhs);
}
pi calc(int u, bool cir = false) {
	bak = idx = 0;
	dfs(u); pi res(0, 0);
	if (cir) {
		path[++bak] = path[1];
		res = dp(1, 1) + dp(2, 2);
	} else res = dp(3, 3);
	return res;
}
int n, m;
int main() {
	std::cin >> m >> n;
	for (int i = 1, t, t1; i <= m; ++i) {
		std::cin >> t;
		if (t == 1) {
			std::cin >> t1;
			self[absx(t1)].push_back(t1);
		} else {
			std::cin >> t >> t1;
			addedge(absx(t), absx(t1), t, t1);
		}
	}
	pi ans(1, 0);
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && deg[i] <= 1)
			ans = ans * calc(i);
	for (int i = 1; i <= n; ++i) if (!vis[i])
		ans = ans * calc(i, true);
	std::cout << ans.second << '\n';
	return 0;
}