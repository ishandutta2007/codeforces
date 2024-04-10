#include <bits/stdc++.h>

using namespace std; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 1 << 16 | 5; 

int n, nV; 
vector<int> adj[MaxN]; 

int idx[MaxN]; 

void work() {
	read(n), nV = 1 << n; 
	
	for (int i = 0; i < nV; ++i) adj[i].clear(); 
	for (int i = 0; i < nV * n / 2; ++i) {
		int u, v; 
		read(u), read(v); 

		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	
	static bool vis[MaxN]; 
	for (int i = 0; i < nV; ++i) idx[i] = 0, vis[i] = false; 

	vector<int> cur, nxt; 
	vis[idx[0] = 0] = true; 
	for (int i = 0; i < n; ++i) {
		int v = adj[0][i]; 
		vis[v] = true, idx[v] = 1 << i; 
		cur.push_back(v); 
	}

	for (int c = 2; c <= n; ++c) {
		for (int u : cur)
			for (int v : adj[u])
				if (!vis[v]) idx[v] |= idx[u]; 
		
		for (int u = 0; u < nV; ++u)
			if (idx[u] && !vis[u]) {
				nxt.push_back(u); 
				vis[u] = true; 
			}

		cur = nxt, nxt.clear(); 
	}
	
	static int p[MaxN]; 
	for (int i = 0; i < nV; ++i) p[idx[i]] = i; 
	for (int i = 0; i < nV; ++i) printf("%d%c", p[i], " \n"[i == nV - 1]); 
//
	if (nV % n) puts("-1"); 
	else {
		static int ans[MaxN]; 
		for (int i = 0; i < nV; ++i) {
			int sum = 0; 
			for (int j = 0; j < n; ++j)
				if (i >> j & 1) sum ^= j; 
			ans[p[i]] = sum; 
		}
		for (int i = 0; i < nV; ++i) printf("%d%c", ans[i], " \n"[i == nV - 1]); 
	}
}

int main() {
	int T; 
	read(T); 
	while (T--) work(); 
	return 0; 
}