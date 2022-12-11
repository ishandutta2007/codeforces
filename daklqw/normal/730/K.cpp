#include <bits/stdc++.h>

const int MAXN = 400010;
const int MAXM = 2000010;
int head[MAXN], nxt[MAXM], to[MAXM], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, m, S, T;
int dep[MAXN];
int fa[MAXN], fae[MAXN], out[MAXN];
int tag[MAXM], xs[MAXM], ys[MAXM];
std::vector<int> cir[MAXN];
void dfs(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			if (!dep[to[i]]) {
				dep[to[i]] = dep[u] + 1;
				fa[to[i]] = u; fae[to[i]] = i;
				out[u] = to[i];
				dfs(to[i]);
			} else if (dep[to[i]] < dep[u])
				cir[out[to[i]]].push_back(i ^ 1);
		}
}
typedef std::pair<int, int> pi;
std::queue<pi> q;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; std::cin >> Q;
	int TC = 1;
	while (Q --> 0) {
		std::cin >> n >> m >> S >> T; ++TC;
		tot = 1; memset(tag, -1, m + 1 << 2);
		for (int i = 1; i <= m; ++i) {
			std::cin >> xs[i] >> ys[i]; ++TC;
			addedge(xs[i], ys[i]);
		}
		dep[S] = 1; dfs(S); q.emplace(T, 0);
		for (int i = 1; i <= m; ++i)
			if (dep[xs[i]] > dep[ys[i]]) std::swap(xs[i], ys[i]);
		while (!q.empty()) {
			int u, c; std::tie(u, c) = q.front(); q.pop();
			while (fa[u] && tag[fae[u] >> 1] == -1) {
				tag[fae[u] >> 1] = c;
				for (auto t : cir[u]) {
					tag[t >> 1] = c;
					q.emplace(to[t], c ^ 1);
				}
				u = fa[u];
			}
		}
		if (*std::min_element(tag + 1, tag + 1 + m) == -1)
			std::cout << "No\n";
		else {
			std::cout << "Yes\n";
			for (int i = 1; i <= m; ++i) {
				if (tag[i]) std::swap(xs[i], ys[i]);
				std::cout << xs[i] << ' ' << ys[i] << '\n';
			}
		}
		memset(dep, 0, n + 1 << 2);
		memset(fa, 0, n + 1 << 2);
		memset(out, 0, n + 1 << 2);
		memset(fae, 0, n + 1 << 2);
		memset(head, 0, n + 1 << 2);
		for (int i = 1; i <= n; ++i) cir[i].clear();
	}
	return 0;
}