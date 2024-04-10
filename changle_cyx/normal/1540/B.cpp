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

const int mod = 1000000007; 
const int inv2 = (mod + 1) / 2; 

inline void madd(int &x, const int &y) {
	x = x + y >= mod ? x + y - mod : x + y; 
}

inline int qpow(int x, int y) {
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1) res = 1LL * res * x % mod; 
	return res; 
}

const int MaxN = 200 + 5; 

int n; 
int C[MaxN][MaxN], f[MaxN][MaxN]; 

vector<int> adj[MaxN]; 

int ans; 
int sze[MaxN][MaxN]; 

void dfsSize(int u, int pre, int st) {
	sze[st][u] = 1; 
	for (int v : adj[u]) if (v != pre) {
		dfsSize(v, u, st); 
		sze[st][u] += sze[st][v]; 
	}
}

int szep[MaxN]; 
void dfs(int u, int pre, int d, int st) {
	if (u < st) {
		madd(ans, sze[u][st]); 
		for (int i = 1; i < d; ++i) {
			madd(ans, 1LL * f[i][d - i] * szep[i] % mod); 
		}
	}

	int all = 0; 
	for (int v : adj[u]) if (v != pre) {
		all += sze[st][v]; 
	}

	for (int v : adj[u]) if (v != pre) {
		szep[d] = all - sze[st][v] + 1; 
		dfs(v, u, d + 1, st); 
	}
}
//orzczk
int main() {
	read(n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	for (int i = 1; i <= n; ++i)
		f[0][i] = 1; 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			f[i][j] = 1LL * inv2 * (f[i - 1][j] + f[i][j - 1]) % mod; 
		}
	
	for (int u = 1; u <= n; ++u) {
		dfsSize(u, 0, u); 
	}
	for (int u = 1; u <= n; ++u) {
		dfs(u, 0, 0, u); 
	}
	
	ans = 1LL * ans * qpow(n, mod - 2) % mod; 
	cout << ans << '\n'; 

	return 0; 
}