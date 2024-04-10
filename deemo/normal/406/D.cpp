#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 19;

int n, depth[MAXN], par[LOG][MAXN], vec[MAXN];
ll x[MAXN], y[MAXN];
vector<int>	adj[MAXN];

ll cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
	return (a.F - c.F) * (b.S - c.S) - (a.S - c.S) * (b.F - c.F);}

void add(){
	int t = 0;
	for (int i = n - 1; i >= 0; i--){
		while (t > 1 && cross({x[vec[t - 1]], y[vec[t - 1]]}, {x[vec[t - 2]], y[vec[t - 2]]}, {x[i], y[i]}) > 0)	t--;
		if (t)
			adj[vec[t - 1]].push_back(i);
		vec[t++] = i;
	}
}

void dfs(int v, int p = -1, int de = 0){
	depth[v] = de;
	par[0][v] = p;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de + 1);
}

void init(){
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (par[w - 1][i] == -1)
				par[w][i] = -1;
			else
				par[w][i] = par[w - 1][par[w - 1][i]];
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int w = LOG - 1; w >= 0; w--)
		if (depth[u] - (1<<w) >= depth[v])	
			u = par[w][u];
	if (u == v)	return u;

	for (int w = LOG - 1; w >= 0; w--)
		if (par[w][u] != par[w][v])
			u = par[w][u], v = par[w][v];
	return par[0][v];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%I64d %I64d", &x[i], &y[i]);
	add();
	dfs(n-1);
	init();

	int q;	scanf("%d", &q);
	while (q--){
		int u, v;	scanf("%d %d", &u, &v), u--, v--;
		printf("%d ", lca(u, v) + 1);
	}
	printf("\n");
	return 0;
}