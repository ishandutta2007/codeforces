#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 60;
const int MAXP = MAXN * 210;
const int MAXE = MAXP * 110;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
int head[MAXP], nxt[MAXE], to[MAXE], val[MAXE], cost[MAXE], tot = 1;
void adde(int b, int e, int v, int c) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v; cost[tot] = c;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = 0; cost[tot] = -c;
}
int S, T, idx;
LL dis[MAXP]; bool inq[MAXP];
std::queue<int> q;
bool bellmanford() {
	memset(dis, 0x3f, idx + 1 << 3);
	inq[S] = true, q.push(S), dis[S] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop(); inq[t] = false;
		for (int i = head[t]; i; i = nxt[i])
			if (val[i] && dis[to[i]] > dis[t] + cost[i]) {
				dis[to[i]] = dis[t] + cost[i];
				if (!inq[to[i]]) {
					inq[to[i]] = true;
					q.push(to[i]);
				}
			}
	}
	return dis[T] != INFL;
}
int dinic(int u, int minv) {
	if (u == T || !minv) return minv;
	int res = 0, t;
	inq[u] = true;
	for (int & i = head[u]; i; i = nxt[i])
		if (val[i] && !inq[to[i]] && dis[to[i]] == dis[u] + cost[i] && 
			(t = dinic(to[i], std::min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			res += t;
			minv -= t;
			if (!minv) break;
		}
	inq[u] = false;
	if (!res) dis[u] = INFL;
	return res;
}
LL flow(int K) {
	LL res = 0;
	static int hq[MAXP];
	memcpy(hq, head, idx + 1 << 2);
	int dbg = 0;
	while (bellmanford()) {
		int fl = dinic(S, INF);
		dbg += fl;
		res += fl * dis[T];
		memcpy(head, hq, idx + 1 << 2);
	}
	assert(dbg == K);
	std::cerr << "DBG FLOW: " << dbg << std::endl;
	return res;
}
int n, m, K, C, D;
int map[MAXN][MAXN * 2];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K >> C >> D;
	S = 0, T = idx = 1;
	int lim = m + K + 3;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= lim; ++j) {
			map[i][j] = ++idx;
			if (j) adde(map[i][j - 1], map[i][j], INF, 0);
		}
	for (int i = 0; i <= lim; ++i)
		adde(map[1][i], T, INF, C * i);
	for (int i = 1, t; i <= K; ++i)
		std::cin >> t, adde(S, map[t][0], 1, 0);
	auto pw = [] (int x) { return x * x; };
	for (int i = 1, b, e; i <= m; ++i) {
		std::cin >> b >> e;
		for (int j = 0; j < lim; ++j)
			for (int k = 1; k <= K; ++k) {
				adde(map[b][j], map[e][j + 1], 1, D * (pw(k) - pw(k - 1)));
				adde(map[e][j], map[b][j + 1], 1, D * (pw(k) - pw(k - 1)));
			}
	}
	std::cout << flow(K) << std::endl;
	return 0;
}