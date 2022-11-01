//sol 2
#include <bits/stdc++.h>

using namespace std; 

const int MaxN = 1e5 + 5; 

int n, S; 
vector<int> adj[MaxN], son[MaxN], seq; 

void dfsInit(int u = 1, int pre = 0) {
	seq.push_back(u); 
	for (int v : adj[u]) if (v != pre) {
		son[u].push_back(v); 
		dfsInit(v, u); 
	}
}

int solve(int K) {
	static int f[MaxN], g[MaxN]; 
	for (int u : seq) {
		int m0 = 0, m1 = 0; 
		
		f[u] = g[u] = 0; 
		for (int v : son[u]) {
			f[u] += f[v]; 
			if (g[v] > m0) m1 = m0, m0 = g[v]; 
			else if (g[v] > m1) m1 = g[v]; 
		}
		
		if (m0 + m1 + 1 >= K) ++f[u]; 
		else g[u] = m0 + 1; 
	}
	
	return f[1]; 
}

int ans[MaxN]; 

void solve(int l, int r, int vl, int vr) {
	if (l > r || vl > vr) return; 
	if (vl == vr) {
		for (int i = l; i <= r; ++i) ans[i] = vl; 
		return; 
	}
	
	int mid = (l + r) >> 1, vmid = solve(mid); 
	ans[mid] = vmid; 
	solve(l, mid - 1, vmid, vr), solve(mid + 1, r, vl, vmid); 
}

int main() {
	scanf("%d", &n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	
	dfsInit(), reverse(seq.begin(), seq.end());
	
	solve(1, n, 0, n); 
	for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]); 
	
	return 0; 
}