#include <bits/stdc++.h>

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

using std::cerr; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

inline s64 gcd(s64 n, s64 m) {
	return m ? gcd(m, n % m) : n; 
}

const int MaxN = 2e5 + 5; 

int n, m; 
vector<pii> adj[MaxN], adjR[MaxN]; 

int dfsClock, dfn[MaxN], low[MaxN]; 
int top, stk[MaxN]; 

int nS, scc[MaxN]; 
vi ver[MaxN]; 

void tarjan(int u) {
	stk[++top] = u; 
	dfn[u] = low[u] = ++dfsClock; 

	for (pii e : adj[u]) {
		int v = e.first; 

		if (!dfn[v]) {
			tarjan(v); 	
			tense(low[u], low[v]); 
		} else if (!scc[v]) {
			tense(low[u], dfn[v]); 
		}
	}

	if (dfn[u] == low[u]) {
		++nS; 
		
		int v; 
		do {
			v = stk[top--]; 
			scc[v] = nS; 
			ver[nS].push_back(v); 
		} while (v != u); 
	}
}

bool vis[MaxN][2]; 
s64 dis[MaxN][2], g[MaxN]; 

void dfsDis(int u, int opt, int col) {
	vis[u][opt] = true; 

	if (opt == 0) {
		for (pii e : adj[u]) {
			int v = e.first; 
			if (!vis[v][opt] && scc[v] == col) {
				dis[v][opt] = dis[u][opt] + e.second; 
				dfsDis(v, opt, col); 
			}
		}
	} else {
		for (pii e : adjR[u]) {
			int v = e.first; 
			if (!vis[v][opt] && scc[v] == col) {
				dis[v][opt] = dis[u][opt] + e.second; 
				dfsDis(v, opt, col); 
			}
		}
	}
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	read(n), read(m); 
	for (int i = 1; i <= m; ++i) {
		int u, v, w; 
		read(u), read(v), read(w); 

		adj[u].emplace_back(v, w); 
		adjR[v].emplace_back(u, w); 
	}

	for (int u = 1; u <= n; ++u)
		if (!dfn[u]) tarjan(u); 
	
	for (int c = 1; c <= nS; ++c) {
		int rt = ver[c].back(); 

		// cerr << "==============\n"; 
		// cerr << c << ' ' << rt << ':' << '\n'; 

		dfsDis(rt, 0, c); 
		dfsDis(rt, 1, c); 
	
		for (int u : ver[c]) {
			// cerr << u << ':' << dis[u][0] << ' ' << dis[u][1] << '\n'; 

			for (pii e : adj[u]) {
				int v = e.first; 
				if (scc[v] == c) {
					g[c] = gcd(g[c], e.second + dis[u][0] + dis[v][1]); 
				}
			}
		}
		
		// cerr << g[c] << '\n'; 
	}

	int Q; 
	read(Q); 
	while (Q--) {
		int v, s, t; 
		read(v), read(s), read(t); 

		s64 d = s - dis[v][0] - dis[v][1]; 
		if (d % gcd(g[scc[v]], t) == 0)
			puts("YES"); 
		else
			puts("NO"); 
	}

	return 0; 
}