#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const int SQRT = 320;
const int LOG = 19;
const int max_n = 1e5 + 100;
const int INF = 1e9 + 2;

int n, q, f;
int vec[SQRT + 100];
int par[max_n][LOG + 2];
int depth[max_n], mark[max_n];
vector<int>	adj[max_n];
int d[max_n];
int qu[max_n];
bool seen[max_n];

void dfs(int v, int p, int de){
	depth[v] = de;
	if (mark[v])	d[v] = 0;
	par[v][0] = p;
	for (int u:adj[v]){
		if (u == p)	continue;
		dfs(u, v, de + 1);
		d[v] = min(d[v], d[u] + 1);
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

int lca(int v, int u){
	if (depth[v] < depth[u])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[u])	v = par[v][i];
	if (v == u)	return	v;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return	par[v][0];
}

void refresh(){
	int h = 0, t = 0;
	fill(seen, seen + n, 0);
	for (int i = 0; i < f; i++)
		qu[t++] = vec[i], seen[vec[i]] = 1;

	while (h < t){
		int v = qu[h++];
		for (int u:adj[v])
			if (!seen[u])	d[u] = min(d[u], d[v] + 1),	seen[u] = 1, qu[t++] = u;
	}
	f = 0;
}

int get(int v){
	int ret = d[v];
	for (int i = 0; i < f; i++){
		int p = lca(vec[i], v);
		ret = min(ret, -depth[p] - depth[p] + depth[v] + depth[vec[i]]);
	}
	return	ret;
}

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(d, d + n, INF);
	dfs(0, -1, 0);
	init();

	d[0] = 0;
	vec[f++] = 0;
	for (int i = 0; i < q; i++){
		if (i % 250 == 0)	refresh();
		int type;	scanf("%d", &type);
		if (type == 1){
			int v;	scanf("%d", &v); v--;
			d[v] = 0;
			vec[f++] = v;
			continue;
		}
		int v;	scanf("%d", &v);	v--;
		printf("%d\n", get(v));
	}
	return 0;
}