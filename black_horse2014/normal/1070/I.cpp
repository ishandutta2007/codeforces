#include <bits/stdc++.h>
using namespace std;

namespace Dinic {
	const int N = 1500;
	const int M = 11000;
	
	int fst[N], to[M], nxt[M];
	int cap[M];
	int dis[N], ptr[N], q[N];
	int E;
	
	inline void init() {
		memset(fst, -1, sizeof fst);
		E = 0;
	}
	
	inline void add_edge(int u, int v, int c) {
		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
	}
	
	inline bool bfs(int S, int T, int n) {
		memset(dis, -1, sizeof dis);
		int h = 0, t = 0;
		q[t++] = S, dis[S] = 0;
		while (h != t) {
			int u = q[h++];
			if (u == T) return true;
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0) {
				int v = to[e];
				if (~dis[v]) continue;
				dis[v] = dis[u] + 1;
				q[t++] = v;
			}
		}
		return (dis[T] != -1);
	}
	
	inline int dfs(int u, int T, int f) {
		if (u == T) return f;
		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == dis[u] + 1) {
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
			for (int cur; (cur = dfs(S, T, 1e9)) > 0; ret += cur);
		}
		return ret;
	}
}

const int N = 700;

int deg[N], a[N], b[N], c[N], ida[N], idb[N];
vector<int> vec[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	memset(deg, 0, sizeof(int) * (n + 1));
	Dinic::init();
	int S = 0, T = n + m + 1;
	for (int i = 1; i <= m; i++) Dinic::add_edge(S, i, 1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		Dinic::add_edge(i, a[i] + m, 1);
		ida[i] = Dinic::E - 1;
		Dinic::add_edge(i, b[i] + m, 1);
		idb[i] = Dinic::E - 1;
		deg[a[i]]++, deg[b[i]]++;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] > 2 * k) {
			for (int i = 1; i <= m; i++) cout << 0 << " \n"[i == m];
			return;
		}
		int f = max(0, 2 * (deg[i] - k));
		Dinic::add_edge(i + m, T, f);
		tot += f;
	}
	if (Dinic::max_flow(S, T, T + 1) != tot) {
		for (int i = 1; i <= m; i++) cout << 0 << " \n"[i == m];
		return;
	}
	for (int i = 1; i <= n; i++) vec[i].clear();
	for (int i = 1; i <= m; i++) c[i] = 0;
	for (int i = 1; i <= m; i++) {
		if (Dinic::cap[ida[i]]) vec[a[i]].push_back(i);
		if (Dinic::cap[idb[i]]) vec[b[i]].push_back(i);
	}
	int TT = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec[i].size(); j += 2) {
			TT++;
			c[vec[i][j]] = c[vec[i][j + 1]] = TT;
		}
	}
	for (int i = 1; i <= m; i++) if (!c[i]) c[i] = ++TT;
	assert(TT <= 100500);
	for (int i = 1; i <= m; i++) cout << c[i] << " \n"[i == m];
}

int main() {
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		solve();
	}
	return 0;
}