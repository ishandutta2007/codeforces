#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

const int sigma = 26; 
const int MaxN = 1e6 + 5; 

namespace ACAutomaton {
	struct node {
		int trans[sigma], fail; 
	}tr[MaxN]; 
	
	int nT = 1; 
	
	int insert(char *s) { //return endnode
		int x = 1, len = strlen(s + 1); 
		for (int i = 1, c; i <= len; ++i) {
			if (!tr[x].trans[c = s[i] - 'a']) tr[x].trans[c] = ++nT; 
			x = tr[x].trans[c]; 
		}
		return x; 
	}
		
	void buildFail() {
		static int que[MaxN], qr; 
		for (int i = 0; i < sigma; ++i) tr[0].trans[i] = 1; 
		
		que[qr = 1] = 1; 
		for (int i = 1; i <= qr; ++i) {
			int u = que[i]; 
			for (int c = 0; c < sigma; ++c) {
				int &v = tr[u].trans[c], w = tr[u].fail; 
		
				while (!tr[w].trans[c]) w = tr[w].fail; 
				w = tr[w].trans[c]; 
				
				if (v) tr[que[++qr] = v].fail = w; 
				else v = w; 
			}
		}
	}
	
	vector<int> adj[MaxN]; 
	int dfsClock, dfn[MaxN], sze[MaxN]; 
	
	void dfsInit(int u) {
		dfn[u] = ++dfsClock, sze[u] = 1; 
		for (int v : adj[u]) {
			dfsInit(v); 
			sze[u] += sze[v]; 
		}
	}
	
	void buildTree() {
		buildFail(); 
		for (int i = 2; i <= nT; ++i) adj[tr[i].fail].push_back(i); 
		dfsInit(1); 
	}
	
	int bit[MaxN]; 
	bool vis[MaxN]; 
	
	void bitInit(int *endnode, int n) {
		for (int i = 1; i <= n; ++i) {
			int u = endnode[i]; 
			vis[u] = true, ++bit[dfn[u]], --bit[dfn[u] + sze[u]]; 
		} 
		for (int i = 1; i <= nT; ++i) if (i + (i & -i) <= nT) bit[i + (i & -i)] += bit[i]; 
	}
	
	void nodeModify(int u, int opt) {
		if ((opt > 0) == vis[u]) return; 
		
		vis[u] = opt > 0; 
		int x = dfn[u], y = dfn[u] + sze[u]; 
		for (; x <= nT; x += x & -x) bit[x] += opt; 
		for (; y <= nT; y += y & -y) bit[y] -= opt; 
	}
	
	int pathQuery(int u) {
		int x = dfn[u], res = 0; 
		for (; x; x ^= x & -x) res += bit[x]; 
		return res; 
	}
	
	s64 queryAll(char *s) {
		s64 res = 0; 
		for (int i = 1, c, x = 1, len = strlen(s + 1); i <= len; ++i) {
			res += pathQuery(x = tr[x].trans[c = s[i] - 'a']); 
		}
		return res; 	
	}
}

int n, K; 
int endnode[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

    //orzczk
	scanf("%d%d", &n, &K); 
	for (int i = 1; i <= K; ++i) {
		static char s[MaxN]; 
		scanf("%s", s + 1); 
		endnode[i] = ACAutomaton::insert(s); 
	}
	
	ACAutomaton::buildTree(); 
	ACAutomaton::bitInit(endnode, K); 
	
	for (int q = 1; q <= n; ++q) {
		static char s[MaxN]; 
		scanf("%s", s); 
			
		if (s[0] == '+' || s[0] == '-') {
			int d; 
			sscanf(s + 1, "%d", &d); 
			ACAutomaton::nodeModify(endnode[d], s[0] == '+' ? 1 : -1); 
		} else {
			printf("%lld\n", ACAutomaton::queryAll(s)); 
		}
	}
	
	return 0; 
}