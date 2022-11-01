#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

int ask(int u) {
	printf("? %d\n", u); 
	fflush(stdout); 

	int res; 
	read(res); 
	return res; 
}

const int MaxN = 100000 + 5; 

int n; 
vector<int> adj[MaxN]; 

int ans; 

vector<pii> sonf[MaxN], sonAll[MaxN]; 
pii f[MaxN], g[MaxN]; 

int calc(vector<pii> V) {
	static int dp[3]; 
	memset(dp, 0, sizeof(dp)); 

	for (int i = 0; i < (int)V.size(); ++i) {
		++dp[0], ++dp[1]; 
		relax(dp[2], dp[1] + V[i].first - 1); 
		relax(dp[1], dp[0] + V[i].first - 1); 
	}

	return max(dp[1], dp[2]); 
}

void dfs1(int u, int preu) {
	sonf[u].clear();  
	
	for (int v : adj[u])
		if (v != preu) {
			dfs1(v, u); 
			sonf[u].push_back(f[v]); 
		}
	
	if (sonf[u].empty()) {
		f[u] = make_pair(1, u); 
	} else {
		f[u] = make_pair(0, 0); 

		sort(sonf[u].begin(), sonf[u].end(), greater<pii>()); 
		for (int i = 0; i < (int)sonf[u].size(); ++i) {
			relax(f[u], make_pair(sonf[u][i].first + i, sonf[u][i].second)); 
		}
		f[u].second = sonf[u].front().second; 
	}
}

void dfs2(int u, int preu) {
	static vector<pii> cur; 
	
	cur.clear(); 
	for (int v : adj[u])
		if (v != preu)
			cur.emplace_back(f[v].first, v); 
	if (u != 1) {
		cur.emplace_back(g[u].first, preu); 
	}

	sort(cur.begin(), cur.end(), greater<pii>()); 
	relax(ans, calc(cur)); 

	static pii pre[MaxN], suf[MaxN]; 
	int sze = cur.size(); 

	pre[0] = suf[sze - 1] = {0, 0}; 
	for (int i = 1; i < sze; ++i)
		relax(pre[i] = pre[i - 1], {cur[i - 1].first + i - 1, cur[i - 1].second}); 
	for (int i = sze - 2; i >= 0; --i)
		relax(suf[i] = suf[i + 1], {cur[i + 1].first + i, cur[i + 1].second}); 

	for (int i = 0; i < sze; ++i) {
		if (cur[i].second == preu) continue; 
		int v = cur[i].second; 

		g[v] = max(pre[i], suf[i]); 
		if (!g[v].first) g[v] = {1, v}; 
	}

	for (int v : adj[u])
		if (v != preu) {
			dfs2(v, u); 
		}
}

int s; 

int solve(int u, int lst) {
	for (int i = 0; i < (int)sonf[u].size(); ++i) {
		if (sonf[u][i].second == lst) continue; 

		int w = ask(sonf[u][i].second); 
		if (w == u) continue; 

		return solve(w, sonf[u][i].second); 
	}
	return u; 
}

int main() {
	read(n); 
	if (n == 1) {
		puts("0\n! 1 1"); 
		return 0; 
	}
	
	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	dfs1(1, 0); 
	dfs2(1, 0); 

	printf("%d\n", ans); 
	fflush(stdout); 

	read(s); 
	dfs1(s, 0); 

	int A = 0, B = 0; 
	bool sideA = false, sideB = false; 

	for (pii p : sonf[s]) {
		if (sideB) break; 
		
		int w = ask(p.second); 
		if (w == s) continue; 

		if (!sideA) {
			A = solve(w, p.second); 
			sideA = true; 
		} else if (!sideB) {
			B = solve(w, p.second); 
			sideB = true; 
		}
	}

	if (!sideA) A = s; 
	if (!sideB) B = s; 

	cout << "! " << A << ' ' << B << '\n'; 
	
	return 0; 
}