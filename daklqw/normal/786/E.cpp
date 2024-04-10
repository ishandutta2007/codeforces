#include <bits/stdc++.h>

const int MAXN = 20010;
const int MAXP = MAXN * 17 + MAXN / 2;
const int MAXE = MAXP * 8;
const int INF = 0x3f3f3f3f;
const int UP = 15;
int head[MAXP], nxt[MAXE], to[MAXE], val[MAXE], tot = 1;
void adde(int b, int e, int v) {
	if (!b || !e) return ;
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = 0;
}
int dis[MAXP];
std::queue<int> q;
int S, T, idx;
bool bfs() {
	memset(dis, 0, idx + 1 << 2);
	q.push(S); dis[S] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i])
			if (val[i] && !dis[to[i]])
				dis[to[i]] = dis[t] + 1, q.push(to[i]);
	}
	return dis[T] > 0;
}
int dinic(int u, int minv) {
	if (u == T || !minv) return minv;
	int t, res = 0;
	for (int & i = head[u]; i; i = nxt[i])
		if (val[i] && dis[to[i]] == dis[u] + 1 && (t = dinic(to[i], std::min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			res += t;
			minv -= t;
			if (!minv) break;
		}
	if (!res) dis[u] = -1;
	return res;
}
int flow() {
	static int qh[MAXP];
	memcpy(qh, head, idx + 1 << 2);
	int res = 0;
	while (bfs()) {
		res += dinic(S, INF);
		memcpy(head, qh, idx + 1 << 2);
	}
	return res;
}
int n, m;
int fa[UP][MAXN], ed[UP][MAXN], dep[MAXN];
int bel[MAXN];
std::vector<std::pair<int, int> > out[MAXN];
void dfs(int u) {
	for (auto e : out[u]) {
		int i = e.first;
		if (i != fa[0][u]) {
			bel[i] = e.second;
			fa[0][i] = u, dep[i] = dep[u] + 1, dfs(i);
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	S = 1, T = idx = n + m + 1;
	for (int i = 2; i <= n; ++i)
		adde(ed[0][i] = i, T, 1);
	for (int i = 1, b, e; i < n; ++i) {
		std::cin >> b >> e;
		out[e].emplace_back(b, i);
		out[b].emplace_back(e, i);
	}
	dfs(1);
	for (int i = 1; i != UP; ++i)
		for (int j = 1; j <= n; ++j) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
			++idx;
			adde(idx, ed[i - 1][j], INF);
			adde(idx, ed[i - 1][fa[i - 1][j]], INF);
			ed[i][j] = idx;
		}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		std::cin >> x >> y;
		int now = i + n;
		adde(S, now, 1);
		if (dep[x] < dep[y]) std::swap(x, y);
		for (int t = dep[x] - dep[y]; t; t &= t - 1) {
			int l = __builtin_ctz(t);
			adde(now, ed[l][x], INF);
			x = fa[l][x];
		}
		for (int j = UP - 1; ~j; --j)
			if (fa[j][x] != fa[j][y]) {
				adde(now, ed[j][x], INF);
				adde(now, ed[j][y], INF);
				x = fa[j][x], y = fa[j][y];
			}
		if (x != y) {
		    adde(now, ed[0][x], INF), adde(now, ed[0][y], INF);
		    assert(x != 1);
		    assert(y != 1);
		} else assert(x != 0);
	}
	int toc = 0;
	std::cout << (toc = flow()) << std::endl;
	std::vector<int> ansl;
	for (int u = 1; u <= m; ++u)
		if (dis[u + n] == 0) ansl.push_back(u), --toc;
	std::cout << ansl.size();
	for (auto t : ansl) std::cout << ' ' << t;
	std::cout << '\n';
	ansl.clear();
	for (int u = 2; u <= n; ++u)
		if (dis[u] > 0) ansl.push_back(u), --toc;
	std::cout << ansl.size();
	for (auto t : ansl) std::cout << ' ' << bel[t];
	std::cout << '\n';
	return 0;
}