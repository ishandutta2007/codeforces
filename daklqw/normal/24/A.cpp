#include <bits/stdc++.h>

const int MAXN = 210;
int sum, ts, n;
int head[MAXN], nxt[MAXN], to[MAXN], tot = 1, val[MAXN];
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int c1;
void dfs(int u, int fa = 0) {
	if (u == 1) {
		++c1;
		if (c1 == 2) return ;
	}
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			sum += val[i];
			if (i & 1) ts += val[i];
			dfs(to[i], u);
			return ;
		}
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t1, t2, t3; i <= n; ++i)
		std::cin >> t1 >> t2 >> t3, addedge(t1, t2, t3);
	dfs(1);
	std::cout << std::min(ts, sum - ts) << '\n';
	return 0;
}