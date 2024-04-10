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
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 600 + 5; 
const int MaxE = MaxN * MaxN * 4; 

const int INF = 0x3f3f3f3f; 

int n, m; 

int ans[MaxN][MaxN]; 
int ect, adj[MaxN], to[MaxE], nxt[MaxE], weight[MaxE]; 

void addEdge(int u, int v, int w) {
	nxt[++ect] = adj[u]; 
	adj[u] = ect; 
	to[ect] = v; 
	weight[ect] = w; 
}

#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

void dijkstra(int st, int *dis) {
	static bool vis[MaxN]; 
	for (int i = 0; i < n; ++i) {
		vis[i] = false; 
		dis[i] = INF; 
	}

	foredge(st) tense(dis[v], weight[e]); 

	for (int t = 1; t <= n; ++t) {
		int u = -1; 
		for (int i = 0; i < n; ++i)
			if (!vis[i] && (u == -1 || dis[i] < dis[u]))
				u = i; 
		
		vis[u] = true; 
		foredge(u) {
			tense(dis[(v + dis[u]) % n], dis[u] + weight[e]); 
		}

		tense(dis[(u + 1) % n], dis[u] + 1); 
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

		addEdge(u, v, w); 
	}

	for (int i = 0; i < n; ++i) {
		dijkstra(i, ans[i]); 

		for (int j = 0; j < n; ++j)
			printf("%d%c", i == j ? 0 : ans[i][j], " \n"[j == n - 1]); 
	}

	return 0; 
}