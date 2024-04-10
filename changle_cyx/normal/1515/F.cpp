#include <bits/stdc++.h>

using std::cerr; 
using std::pair; 
using std::vector; 
typedef long long s64; 

#define mp(x, y) std::make_pair(x, y)	

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

const int MaxN = 3e5 + 5; 
const int MaxM = MaxN; 

struct edge {
	int u, v; 
	void scan() {
		read(u), read(v); 
	}
}e[MaxM]; 

struct halfEdge {
	int v, w; 
	halfEdge *next; 
}; 

halfEdge *adj[MaxN], *adjE[MaxN]; 
halfEdge adjPool[MaxM << 1], *adjTail = adjPool; 

int n, m, cost; 
int ufs[MaxN]; 
s64 a[MaxN]; 

std::set<pair<s64, int> > S; 

int ufsFind(int x) {
	return ufs[x] == x ? x : ufs[x] = ufsFind(ufs[x]); 
}

bool ufsMerge(int x, int y) { // x->y
	int u = ufsFind(x), v = ufsFind(y); 
	if (u == v) 
		return false; 
	return ufs[u] = v, a[v] += a[u], true; 
}

void addEdge(int u, int v, int w) {
	adjTail->v = v; 
	adjTail->w = w; 
	adjTail->next = adj[u]; 

	if (adj[u] == NULL) adjE[u] = adjTail; 
	adj[u] = adjTail++; 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	read(n), read(m), read(cost); 

	s64 sum = 0; 
	for (int i = 1; i <= n; ++i) {
		read(a[i]), a[i] -= cost; 
		sum += a[i]; 

		ufs[i] = i; 
		S.insert(mp(a[i], i)); 
	}
	for (int i = 1; i <= m; ++i) {
		e[i].scan(); 

		addEdge(e[i].u, e[i].v, i); 
		addEdge(e[i].v, e[i].u, i); 
	}

	if (sum < -cost) {
		puts("NO"); 
		return 0; 
	}
	puts("YES"); 

	while (S.begin()->first < 0 && (--S.end())->first >= 0) {
		int u = (--S.end())->second; 
		
		while (adj[u] && ufsFind(adj[u]->v) == ufsFind(u))
			adj[u] = adj[u]->next; 
		
		if (adj[u]) {
			printf("%d\n", adj[u]->w); 

			int v = ufsFind(adj[u]->v); 

			adjE[u]->next = adj[v];  
			adjE[u] = adjE[v]; 

			S.erase(mp(a[u], u)); 
			S.erase(mp(a[v], v)); 
			S.insert(mp(a[u] += a[v], u)); 
			ufs[v] = u; 
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (ufsMerge(e[i].u, e[i].v)) {
			printf("%d\n", i); 
		}
	}
	
	return 0; 
}