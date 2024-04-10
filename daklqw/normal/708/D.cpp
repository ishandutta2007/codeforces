#include <bits/stdc++.h>

const int MAXN = 1010;
const int MAXM = MAXN * 110;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXM], cost[MAXM], tot = 1;
void addedge(int b, int e, int v, int c) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v; cost[tot] = c;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = 0; cost[tot] = -c;
}
int _S, _T, S, T, idx;
int dis[MAXN], inq[MAXN];
std::queue<int> q;
bool bellmanford() {
	memset(dis, 0x3f, idx + 1 << 2);
	dis[S] = 0; q.push(S); inq[S] = true;
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
	return dis[T] != INF;
}
int dinic(int u, int minv) {
	if (u == T || !minv) return minv;
	int t, res = 0;
	inq[u] = true;
	for (int & i = head[u]; i; i = nxt[i])
		if (val[i] && !inq[to[i]] && dis[to[i]] == dis[u] + cost[i] && (t = dinic(to[i], std::min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			minv -= t;
			res += t;
			if (!minv) break;
		}
	inq[u] = false;
	if (!res) dis[u] = -1;
	return res;
}
int MCMF() {
	static int es[MAXN];
	memcpy(es, head, idx + 1 << 2);
	int res = 0;
	while (bellmanford()) {
		res += dinic(S, INF) * dis[T];
		memcpy(head, es, idx + 1 << 2);
	}
	return res;
}

int n, m, ind[MAXN], oud[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	_S = 1, _T = n, S = n + 1, T = n + 2, idx = n + 2;
	int Ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, c, f;
		std::cin >> u >> v >> c >> f;
		ind[v] += f, oud[u] += f;
		if (f <= c) {
			addedge(u, v, c - f, 1);
			addedge(v, u, f, 1);
			addedge(u, v, INF, 2);
		} else {
			Ans += f - c;
			addedge(v, u, f - c, 0);
			addedge(v, u, c, 1);
			addedge(u, v, INF, 2);
		}
	}
	for (int i = 1; i <= n; ++i) addedge(S, i, ind[i], 0);
	for (int i = 1; i <= n; ++i) addedge(i, T, oud[i], 0);
	addedge(_T, _S, INF, 0);
	Ans += MCMF();
	std::cout << Ans << std::endl;
	return 0;
}