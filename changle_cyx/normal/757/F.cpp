#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 
typedef pair<s64, int> pli; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline bool tense(T &x, const T &y) {
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

const int MaxN = 2e5 + 5; 
const int MaxE = 6e5 + 5; 
const s64 INFll = 1LL << 60; 

int n, m; 
int ect, adj[MaxN], nxt[MaxE], to[MaxE], weight[MaxE]; 

#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])
inline void addEdge(int u, int v, int w) {
	nxt[++ect] = adj[u], adj[u] = ect, to[ect] = v, weight[ect] = w; 
}

s64 dis[MaxN]; 
void Dijkstra(int src) {
	fill(dis + 1, dis + n + 1, INFll); 
	static bool vis[MaxN]; 
	
	priority_queue<pli, vector<pli>, greater<pli> > heap; 
	heap.push({dis[src] = 0, src}); 
	
	while (!heap.empty()) {
		int u = heap.top().second; 
		heap.pop(); 
		
		if (vis[u]) continue; 
		vis[u] = true; 
		
		foredge(u) if (!vis[v] && tense(dis[v], dis[u] + weight[e]))
			heap.push({dis[v], v});
	} 
}

const int MaxLog = 20; 

int inDeg[MaxN]; 
vector<int> adjDag[MaxN], adjSon[MaxN]; 

int src; 
int dep[MaxN], sze[MaxN], fa[MaxN], anc[MaxN][MaxLog + 1];  

void addLeaf(int x) { // fa[x] has been confirmed
	adjSon[fa[x]].push_back(x); 
	anc[x][0] = fa[x], dep[x] = dep[fa[x]] + 1; 
	for (int i = 0; anc[x][i]; ++i) anc[x][i + 1] = anc[anc[x][i]][i]; 
}

int queryLCA(int u, int v) {
	if (!u || !v) return u + v; 
	if (dep[u] < dep[v]) swap(u, v); 
	for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, ++i)
		if (d & 1) u = anc[u][i]; 
	
	if (u == v) return u; 
	
	for (int i = MaxLog - 1; i >= 0; --i)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i]; 
	return anc[u][0]; 
}

int ans; 

void dfs(int u) {
	sze[u] = 1; 
	for (int v : adjSon[u]) {
		dfs(v); 
		sze[u] += sze[v]; 
	}

	if (u != src) relax(ans, sze[u]); 
}

void topoSort() {
	for (int u = 1; u <= n; ++u) if (dis[u] < INFll)
		foredge(u) if (dis[u] + weight[e] == dis[v]) {
			adjDag[u].push_back(v), ++inDeg[v]; 
		}
	
	static int que[MaxN], qr; 

	que[qr = 1] = src; 
	for (int i = 1, u; i <= qr; ++i) {
		u = que[i]; 
		if (fa[u]) addLeaf(u); 
		for (int v : adjDag[u]) {
			if (!--inDeg[v]) que[++qr] = v; 
			
			fa[v] = queryLCA(fa[v], u); 
		}
	}

	dfs(src); 
}

int main() {
	read(n), read(m), read(src); 
	for (int i = 1; i <= m; ++i) {
		int u, v, w; 
		read(u), read(v), read(w); 
		addEdge(u, v, w), addEdge(v, u, w); 
	}
	
	Dijkstra(src);
	topoSort(); 
	
	cout << ans << '\n'; 
	
	return 0; 
}