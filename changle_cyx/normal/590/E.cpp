#include <bits/stdc++.h>

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

typedef long long s64; 

const int base = 2; 
const int MaxN = 755; 
const int MaxL = 1e7 + 5;
const int INF = 0x3f3f3f3f; 

int n; 
int g[MaxN][MaxN]; 
int que[MaxL], length[MaxN]; 

inline bool cmp(int x, int y) {
	return length[x] > length[y]; 
}

struct ACAutomaton {
	int endPos[MaxL]; 
	int trans[MaxL][base]; 
	
	int nT, fail[MaxL], pre[MaxL], fa[MaxL]; 

	ACAutomaton() {
		nT = 1; 
		for (int i = 0; i < base; ++i) {
			trans[0][i] = 1; 
		}
		fail[1] = 0; 
	}

	inline void extend(char *s, int p) {
		int n = strlen(s + 1), x = 1; 
		for (int i = 1; i <= n; ++i) {
			int ch = s[i] - 'a'; 
			if (!trans[x][ch]) {
				trans[x][ch] = ++nT; 
				fa[nT] = x; 
			}
			x = trans[x][ch]; 
		}
		endPos[x] = p;  
		length[p] = n; 
	}

	inline void buildFail() {
		int qr; 
		que[qr = 1] = 1; 
		for (int i = 1; i <= qr; ++i) {
			int u = que[i]; 
			for (int c = 0; c < base; ++c) {
				int &v = trans[u][c], w = fail[u]; 
				while (!trans[w][c]) w = fail[w]; 
				w = trans[w][c]; 

				if (!v) {
					v = w; 
				} else {
					fail[que[++qr] = v] = w; 
				}
			}
		}

		endPos[1] = n + 1; 
		for (int i = 2; i <= qr; ++i) {
			int u = que[i]; 
			if (endPos[fail[u]]) {
				pre[u] = fail[u]; 
			} else {
				pre[u] = pre[fail[u]]; 
			}
			if (endPos[u]) {
				g[endPos[u]][endPos[pre[u]]] = true; 

				int v = fa[u]; 
				while (!endPos[v]) {
					g[endPos[u]][endPos[pre[v]]] = true; 
					v = fa[v]; 
				}
				g[endPos[u]][endPos[v]] = true; 
			}
		}

		static int p[MaxN]; 
		
		++n; 
		for (int i = 1; i <= n; ++i) p[i] = i; 
		std::sort(p + 1, p + n + 1, cmp); 

		for (int k = 1; k <= n; ++k) {
			int w = p[k]; 
			for (int i = 1; i < k; ++i)
				for (int j = k + 1; j <= n; ++j) {
					int u = p[i], v = p[j]; 
					g[u][v] |= g[u][w] && g[w][v]; 
				}
		}
	}
}T; 


namespace Dinic {
	const int MaxV = 2e3 + 5;
	const int MaxE = 3e6 + 5;

	int ect = 1, src, des, nV, adj[MaxV]; 
	int nxt[MaxE], cap[MaxE], to[MaxE]; 

	int lev[MaxV], curAdj[MaxV]; 

	inline void addEdge(int u, int v, int w) {
		nxt[++ect] = adj[u], adj[u] = ect, to[ect] = v, cap[ect] = w; 
		nxt[++ect] = adj[v], adj[v] = ect, to[ect] = u, cap[ect] = 0;  
	}

	inline bool bfs() {
		static int que[MaxV], qr; 
		for (int i = 1; i <= nV; ++i) {
			lev[i] = -1, curAdj[i] = adj[i]; 
		}

		lev[que[qr = 1] = des] = 0; 
		for (int i = 1; i <= qr; ++i) {
			int u = que[i]; 
			for (int e = adj[u], v; v = to[e], e; e = nxt[e])
				if (cap[e ^ 1] > 0 && lev[v] == -1) {
					lev[que[++qr] = v] = lev[u] + 1; 
					if (v == src) return true; 
				}
		}
		return false; 
	}
	inline int augment(int u = src, int tar = INF) {
		if (u == des || !tar) return tar; 

		int res = 0; 
		for (int &e = curAdj[u], v; v = to[e], e; e = nxt[e])
			if (cap[e] > 0 && lev[v] < lev[u]) {
				int delta = augment(v, std::min(tar - res, cap[e])); 
				if (delta) {
					cap[e ^ 0] -= delta; 
					cap[e ^ 1] += delta; 
					res += delta; 
					if (res == tar) return res; 
				}
			}
		return lev[u] = -1, res; 
	}
	inline int maxFlow() {
		int res = 0; 
		while (bfs()) res += augment(); 
		return res; 
	}
}
using namespace Dinic; 

inline int getPos(int x, int opt) {
	return x * 2 - opt; 
}

char s[MaxL]; 
int epos[MaxN]; 

int main() {
#ifdef orzczk
	freopen("birthday.in", "r", stdin);
#endif

	scanf("%d", &n); 
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		T.extend(s, i); 
	}
	T.buildFail(); 

	src = n * 2 + 1, des = nV = n * 2 + 2; 
	for (int i = 1; i <= n; ++i) {
		addEdge(src, getPos(i, 0), 1); 
		addEdge(getPos(i, 1), des, 1); 
		for (int j = 1; j <= n; ++j)
			if (g[i][j]) {
				addEdge(getPos(i, 0), getPos(j, 1), 1); 
			}
	}

	int ans = n - maxFlow(); 
	printf("%d\n", ans); 

	if (ans == 1) {
		puts("1"); 
		return 0; 
	}
	
	for (int i = 1; i <= n; ++i)
		if (lev[getPos(i, 0)] == -1 && lev[getPos(i, 1)] != -1) {
			printf("%d ", i); 
		}
	putchar('\n'); 

	return 0; 
}