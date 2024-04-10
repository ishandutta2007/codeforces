#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y;
}

template <class T>
inline bool tense(T &x, const T &y) {
	return x > y ? x = y, true : false; 
}

const int MaxN = 200000 + 5; 

int n; 
vector<int> adj[MaxN]; 

char s[MaxN]; 
s64 ans[MaxN]; 

namespace treeDivision {
	bool vis[MaxN]; 
	
	int findG(int src) {
		static int que[MaxN], pre[MaxN], sze[MaxN], qr; 

		pre[que[qr = 1] = src] = 0; 
		for (int i = 1; i <= qr; ++i) {
			int u = que[i]; 
			for (int v : adj[u]) if (v != pre[u] && !vis[v])
				pre[que[++qr] = v] = u; 
		}

		int res = 0, mins = n + 1; 
		for (int i = qr, u, maxs; i >= 1; --i) {
			sze[u = que[i]] = 1, maxs = 0; 
			for (int v : adj[u]) if (v != pre[u] && !vis[v])
				sze[u] += sze[v], relax(maxs, sze[v]); 
			if (tense(mins, max(maxs, qr - sze[u]))) res = u;  
		}
		return res; 
	}

	const int MaxS = 1 << 20 | 5; 
	int buc[MaxS], sta[MaxN], pre[MaxN]; 

	void modify(int u, int opt) {
		buc[sta[u]] += opt; 
		for (int v : adj[u]) if (v != pre[u] && !vis[v])
			modify(v, opt); 
	}

	s64 sub[MaxN]; 
	void query(int u, int G) {
		sub[u] = 0; 
		for (int v : adj[u]) if (v != pre[u] && !vis[v]) {
			query(v, G); 
			sub[u] += sub[v]; 
		}
		for (int i = 0; i < 20; ++i) sub[u] += buc[sta[u] ^ sta[G] ^ (1 << i)]; 
		sub[u] += buc[sta[u] ^ sta[G]]; 

		// cerr << "++" << u << ' ' << sub[u] << ' ' << sta[u] << ' ' << (sta[u] ^ sta[G]) << '\n'; //
		ans[u] += sub[u]; 
	}
	
	void solve(int u) {
		pre[u = findG(u)] = 0; 
		// cerr << "solving : " << u << '\n'; //

		static int que[MaxN], qr; 
		++buc[sta[que[qr = 1] = u] = 1 << (s[u] - 'a')]; 
		for (int i = 1; i <= qr; ++i) {
			int w = que[i]; 
			for (int v : adj[w]) if (v != pre[w] && !vis[v]) {
				++buc[sta[v] = sta[w] ^ (1 << (s[v] - 'a'))]; 
				pre[que[++qr] = v] = w; 
			}

			// cerr << w << ' ' << sta[w] << '\n'; //
		}

		s64 addition = 0, cur = 0; 
		for (int v : adj[u]) if (!vis[v]) {
			modify(v, -1); 
			query(v, u); 
			modify(v, +1); 

			addition += sub[v]; 
		}
		
		cur += buc[0]; 
		for (int i = 0; i < 20; ++i) cur += buc[1 << i]; 
		ans[u] += (addition + cur) >> 1; 

		for (int i = 1; i <= qr; ++i) --buc[sta[que[i]]]; 

		vis[u] = true; 
		for (int v : adj[u]) if (!vis[v]) solve(v); 
	}
}

int main() {
	scanf("%d", &n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		scanf("%d%d", &u, &v); 

		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	scanf("%s", s + 1); 

	treeDivision::solve(1); 

	for (int i = 1; i <= n; ++i)
		printf("%lld%c", ans[i] + 1, " \n"[i == n]); 

	return 0; 
}