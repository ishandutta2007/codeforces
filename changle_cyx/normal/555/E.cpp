#include <bits/stdc++.h>

using namespace std; 

#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

void invalid() {
	puts("No"), exit(0); 
}

const int MaxN = 2e5 + 5; 
const int MaxE = 4e5 + 5; 
 
int ect = 1, adj[MaxN]; 
int nxt[MaxE], to[MaxE]; 

void addEdge(int u, int v) {
	nxt[++ect] = adj[u], adj[u] = ect, to[ect] = v; 
}

int belrt[MaxN]; 
vector<int> rt, son[MaxN]; 

bool cutfa[MaxN]; 
int nB, bcc[MaxN]; 
int dfsClock, dfn[MaxN], low[MaxN]; 

vector<int> adjBcc[MaxN]; 

void dfsCol(int u, int s) {
	bcc[u] = s; 
	for (int v : son[u]) {
		if (!cutfa[v]) dfsCol(v, s); 
		else adjBcc[s].push_back(bcc[v]); 
	}
}

void dfsTarjan(int u, int frm, int bel) {
	belrt[u] = bel; 
	dfn[u] = low[u] = ++dfsClock; 

	foredge(u) if ((e ^ 1) != frm) {
		if (!dfn[v]) {
			dfsTarjan(v, e, bel), tense(low[u], low[v]); 
			son[u].push_back(v); 

			if (low[v] > dfn[u]) {
				cutfa[v] = true; 
				dfsCol(v, ++nB); 
			}
		} else tense(low[u], dfn[v]); 
	}
}

const int MaxLog = 18; 

int anc[MaxN][MaxLog + 1], dep[MaxN]; 

void treeInit(int u) {
	for (int i = 0; anc[u][i]; ++i) anc[u][i + 1] = anc[anc[u][i]][i]; 

	for (int v : adjBcc[u]) {
		anc[v][0] = u; 
		dep[v] = dep[u] + 1; 

		// cerr << "edge : " << u << ' ' << v << '\n'; 
		treeInit(v); 
	}
}

int s[MaxN][2]; 
int queryLCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v); 
	for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, ++i)
		if (d & 1) u = anc[u][i]; 
	if (u == v) return u; 

	for (int i = MaxLog; i >= 0; --i)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i]; 
	return anc[u][0]; 
}

int n, m, Q; 

int main() {
	read(n), read(m), read(Q); 
	for (int i = 1; i <= m; ++i) {
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}

	for (int u = 1; u <= n; ++u)
		if (!dfn[u]) {
			rt.push_back(u); 
			
			dfsTarjan(u, 0, u); 
			dfsCol(u, ++nB); 
		}

	for (int u : rt) treeInit(bcc[u]); 
	for (int q = 1; q <= Q; ++q) {
		int u, v, w; 
		read(u), read(v); 

		if (belrt[u] != belrt[v]) invalid(); 
		w = queryLCA(u = bcc[u], v = bcc[v]); 

		// cerr << u << ' ' << v << ':' << w << '\n'; 
		++s[u][0], --s[w][0], ++s[v][1], --s[w][1]; 
	}
	
	for (int u = 1; u <= nB; ++u) {
		for (int v : adjBcc[u])
			s[u][0] += s[v][0], s[u][1] += s[v][1]; 
		
		// cerr << u << ' ' << s[u][0] << ' ' << s[u][1] << '\n'; 
		if (s[u][0] && s[u][1]) invalid(); 
	}

	puts("Yes"); 
	return 0; 
}