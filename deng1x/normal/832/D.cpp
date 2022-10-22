#include <bits/stdc++.h>

#define MAXN (100010)

int n, q;
std::vector<int> vec[MAXN];
int f[MAXN][20], dep[MAXN];

void dfs(int u){
	for(auto v : vec[u]){
		if(v == f[u][0]) continue;
		f[v][0] = u;
		dep[v] = dep[u] + 1;
		for(int j = 0; f[v][j + 1] = f[f[v][j]][j]; ++ j);
		dfs(v);
	}
}

int find(int u, int d){
	for(int i = 19; i >= 0; -- i){
		if(dep[f[u][i]] >= d){
			u = f[u][i];
		}
	}
	return u;
}

int lca(int u, int v){
	if(dep[u] < dep[v]) std::swap(u, v);
	u = find(u, dep[v]);
	if(u == v) return u;
	for(int i = 19; i >= 0; -- i){
		if(f[u][i] != f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

int solve(int a, int b, int c){
	//a -> b... return ca or cb
	int ab = lca(a, b), ac = lca(a, c), bc = lca(c, b);
	if(dep[ac] > dep[ab]){
		return std::max(dep[a] - dep[ac], dep[ac] - dep[ab] + dep[b] - dep[ab]) + 1;
	}
	if(dep[bc] > dep[ab]){
		return std::max(dep[b] - dep[bc], dep[bc] - dep[ab] + dep[a] - dep[ab]) + 1;
	}
	return std::max(dep[a], dep[b]) - dep[ab] + 1;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++ i){
		int pi;
		scanf("%d", &pi);
		vec[pi].push_back(i);
		vec[i].push_back(pi);
	}
	dfs(dep[1] = 1);
	while(q --){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ans = INT_MIN;
		ans = std::max(ans, solve(a, b, c));
		ans = std::max(ans, solve(a, c, b));
		ans = std::max(ans, solve(b, c, a));
		printf("%d\n", ans);
	}
	return 0;
}