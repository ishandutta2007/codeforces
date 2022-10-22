#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const int max_n = 1e5 + 100;
const int LOG = 20 + 2;

int n, q;
int mark[max_n], save[max_n], depth[max_n], par[max_n][LOG + 2], ans[max_n];
vector<pair<int, int>>	adj[max_n];

void dfs(int v, int p, int d, int z){
	mark[v] = z;
	depth[v] = d;
	par[v][0] = p;
	for (pair<int, int> u:adj[v]){
		if (u.first == p)	continue;
		dfs(u.first, v, d + 1, u.second);
	}	
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[u][i];
	if (u == v)	return	u;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[u][0];
}

int get(int v, int p){
	int t = 0;
	for (pair<int, int> u:adj[v]){
		if (p == u.first)	continue;
		t += get(u.first, v);
	}	
	t += save[v];
	if (p != -1)	ans[mark[v]] = t;
	return	t;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}	
	dfs(0, -1, 0, -1);
	init();
	scanf("%d", &q);
	while (q--){
		int u, v;	scanf("%d%d", &u, &v);	u--, v--;
		int p = lca(u, v);
		save[p] -= 2, save[v] += 1, save[u] += 1;
	}
	get(0, -1);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}