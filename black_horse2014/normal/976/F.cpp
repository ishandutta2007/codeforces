#include <bits/stdc++.h>
using namespace std;

namespace Dinic {
	const int N = 4400;
	const int M = 13000;
	const int INF = 1e9;	
	int fst[N], to[M], nxt[M];
	int cap[M];
	int dis[N], ptr[N], q[N];
	int V, E;
	void init() {
		memset(fst, -1, sizeof fst);
		V = E = 0; 
	}
	
	inline void add_edge(int u, int v, int c) {
		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
	}
	
	inline bool bfs(int S, int T, int n) {
		memset(dis, -1, sizeof(int) * n);
		int h = 0, t = 0;
		q[t++] = S, dis[S] = 0;
		while (h != t) {
			int u = q[h++];
			if (h == N) h = 0;
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {
				dis[to[e]] = dis[u] + 1;
				q[t++] = to[e];
				if (t == N) t = 0;
				if (to[e] == T) return 1;
			}
		}
		return (dis[T] != -1);
	}
	
	inline int dfs(int u, int T, int f) {
		if (u == T) return f;
		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {
			int ret = dfs(to[e], T, min(f, cap[e]));
			if (ret > 0) {
				cap[e] -= ret, cap[e ^ 1] += ret;
				return ret;
			}
		}
		return 0;
	}
	
	inline int max_flow(int S, int T, int n) {
		int ret = 0;
		while (bfs(S, T, n)) {
			memcpy(ptr, fst, sizeof(int) * n);
			for (int cur; (cur = dfs(S, T, INF)) > 0; ret += cur);
		}
		return ret;
	}
};

const int N = 2200;

int x[N], y[N], deg[2* N], id[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x[i] >> y[i];
		y[i] += n;
		deg[x[i]]++;
		deg[y[i]]++;
	}
	int mi = k;
	for (int i = 1; i <= n + m; i++) mi = min(mi, deg[i]);
	for (int xx = 0; xx <= mi; xx++) {
		Dinic::init();
		int S = 0, T = n + m + 1;
		for (int i = 1; i <= n; i++) Dinic::add_edge(S, i, deg[i] - xx);
		for (int i = 1; i <= k; i++) {
			id[i] = Dinic::E + 1;
			Dinic::add_edge(x[i], y[i], 1);
		}
		for (int i = 1; i <= m; i++) Dinic::add_edge(i + n, T, deg[i + n] - xx);
		int tot = k - Dinic::max_flow(S, T, T + 1);
		cout << tot;
		for (int i = 1; i <= k; i++) if (!Dinic::cap[id[i]]) cout << " " << i;
		cout << endl;
	}
	return 0;
}