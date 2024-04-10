#include <bits/stdc++.h>
using namespace std;

namespace MCMF {
	const int N = 1500;
	const int M = 11000;
	const int C_INF = 1e9;
	const int F_INF = 1e9;
	
	int fst[N], to[M], cap[M], nxt[M], cost[M];
	int dis[N], q[N], prv[N], chk[N];
	int V, E;
	void init() {
		memset(fst, -1, sizeof fst);
		V = E = 0;
	}
	
	inline void add_edge(int u, int v, int f, int c) {
		to[E] = v, cap[E] = f, cost[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, cost[E] = -c, nxt[E] = fst[v], fst[v] = E++;
	}
	
	inline void SSSP(int S, int T, int n) {
		for (int i = 0; i < n; i++) dis[i] = C_INF;
		memset(prv, -1, sizeof(int) * n);
		memset(chk, 0, sizeof(int) * n);
		int h = 0, t = 0;
		q[t++] = S, dis[S] = 0, chk[S]++;
		while (h != t) {
			int u = q[h++];
			chk[u] = 0;
			if (h == N) h = 0;
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u] + cost[e]) {
				dis[to[e]] = dis[u] + cost[e];
				prv[to[e]] = e;
				if (!chk[to[e]]) {
					q[t++] = to[e];
					if (t == N) t = 0;
					chk[to[e]]++;
				}
			}
		}
	}
	
	inline int get_cost(int S, int T, int n) {
		int ret = 0;
		while (true) {
			SSSP(S, T, n);
			if (prv[T] == -1) break;
			int flw = F_INF;
			for (int u = T; u != S; u = to[prv[u] ^ 1]) flw = min(flw, cap[prv[u]]);
			for (int u = T; u != S; u = to[prv[u] ^ 1]) cap[prv[u]] -= flw, cap[prv[u] ^ 1] += flw;
			ret += flw * dis[T];
		}
		return ret;
	}
};

int cn[26], b[110];
char s[110];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) cn[s[i] - 'a']++;
	for (int i = 0; i < n; i++) cin >> b[i];
	int S = n + 26 * n / 2 + 26, T = S + 1;
	MCMF::init();
	for (int i = 0; i < n; i++) MCMF::add_edge(S, i, 1, 0);
	int cur = n;
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < n / 2; i++) {
			int ri = n - 1 - i;
			MCMF::add_edge(i, cur, 1, s[i] == j + 'a' ? 100 - b[i] : 100);
			MCMF::add_edge(ri, cur, 1, s[ri] == j + 'a' ? 100 - b[ri] : 100);
			MCMF::add_edge(cur, n + 13 * n + j, 1, 0);
			cur++;
		}
		MCMF::add_edge(n + 13 * n + j, T, cn[j], 0);
	}
	assert(cur == n + 13 * n);
	cout << 100 * n - MCMF::get_cost(S, T, T + 1) << endl;
	return 0;
}