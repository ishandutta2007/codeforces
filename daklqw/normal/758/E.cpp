#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
LL ws[MAXN], ps[MAXN], uz[MAXN], lim[MAXN];
void adde(int b, int e, LL w, LL p) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
	ws[tot >> 1] = w, ps[tot >> 1] = p;
}
void bye() { std::cout << -1 << std::endl; exit(0); }
LL dfs(int u, int fa = 0) {
	LL sz = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			LL t = dfs(to[i], u), id = i >> 1;
			uz[id] += t;
			if (uz[id] > ps[id]) bye();
			LL dec = std::min(ws[id] - 1, ps[id] - uz[id]);
			ws[id] -= dec, ps[id] -= dec, lim[id] = dec;
			sz += t + ws[id];
		}
	return sz;
}
LL dfs2(int u, LL rest = 0x3f3f3f3f3f3f3f3fLL, int fa = 0) {
	LL res = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			const int id = i >> 1;
			LL up = std::min(rest, lim[id]);
			res += up, rest -= up;
			ws[id] += up, ps[id] += up;
			LL nl = std::min(rest, ps[id] - uz[id]);
			LL t = dfs2(to[i], nl, u);
			res += t; rest -= t;
		}
	return res;
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e, w, p; i < n; ++i)
		std::cin >> b >> e >> w >> p, adde(b, e, w, p);
	dfs(1); dfs2(1);
	std::cout << n << std::endl;
	for (int i = 1; i < n; ++i)
		std::cout << to[i * 2 + 1] << ' ' << to[i * 2] << ' ' << ws[i] << ' ' << ps[i] << '\n';
	return 0;
}