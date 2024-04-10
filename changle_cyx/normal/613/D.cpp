#include <bits/stdc++.h>

using namespace std; 

#define range(x) x.begin(), x.end()

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}
//orzczk
template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

const int INF = 0x3f3f3f3f; 
const int MaxLog = 17; 
const int MaxN = 100000 + 5; 

int n, Q; 
vector<int> adj[MaxN]; 

int fa[MaxN], dep[MaxN], anc[MaxN][MaxLog + 1]; 
int dfsClock, dfn[MaxN], sze[MaxN]; 

void dfsInit(int u) {
	for (int i = 0; anc[u][i]; ++i) anc[u][i + 1] = anc[anc[u][i]][i]; 
	dfn[u] = ++dfsClock, sze[u] = 1; 

	for (int v : adj[u]) {
		if (v == fa[u]) continue; 

		dep[v] = dep[u] + 1, fa[v] = u; 
		anc[v][0] = u; 

		dfsInit(v); 

		sze[u] += sze[v]; 
	}
}

int queryLCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v); 
	for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, ++i)
		if (d & 1) u = anc[u][i]; 
	if (u == v) return u; 

	for (int i = MaxLog; i >= 0; --i)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i]; 
	return anc[u][0]; 
}

bool inTree(int u, int v) {
	return dfn[v] >= dfn[u] && dfn[v] < dfn[u] + sze[u]; 
}

bool type[MaxN]; 
vector<int> auxAdj[MaxN]; 

int auxtree(vector<int> p) { //return root
	static int stk[MaxN], top; 
	sort(range(p), [=](int x, int y){return dfn[x] < dfn[y];}); 
	
	top = 0; 
	for (int i = 0; i < (int)p.size(); ++i) {
		int x = p[i]; 
		auxAdj[x].clear(); 
		type[x] = 1; 

		if (top && !inTree(stk[top], x)) {
			int y = queryLCA(stk[top], x); 
			while (top > 1 && dfn[stk[top - 1]] > dfn[y])
				auxAdj[stk[top - 1]].push_back(stk[top]), --top; 
			
			if (y != stk[top - 1]) {
				auxAdj[y] = {stk[top]}; 
				type[stk[top] = y] = 0; 
			} else {
				auxAdj[y].push_back(stk[top--]); 
			}
		}
		stk[++top] = x; 
	}
	for (int i = 1; i < top; ++i) auxAdj[stk[i]].push_back(stk[i + 1]); 

	return stk[1]; 	
}

int ans, f[MaxN]; 
bool flg; 

void dfsSolve(int u) {
	f[u] = 0;  

	for (int v : auxAdj[u]) {
		flg |= type[u] && type[v] && fa[v] == u; 
		dfsSolve(v); 
		
		f[u] += f[v]; 
	}

	if (type[u]) ans += f[u], f[u] = 1; 
	else if (f[u] > 1) f[u] = 0, ++ans; 
}

int main() {
	read(n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	dfsInit(1); 

	read(Q); 
	while (Q--) {
		int k; 
		vector<int> ver; 

		read(k); 
		for (int i = 0, x; i < k; ++i) read(x), ver.push_back(x); 

		int rt = auxtree(ver); 
		flg = false, ans = 0; 

		dfsSolve(rt); 

		if (flg) puts("-1"); 
		else putint(ans), putchar('\n'); 
	}

	return 0; 
}