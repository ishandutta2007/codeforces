#include<bits/stdc++.h>

using namespace std;

#define tm asdkflhl

const int MAXN = 2e5 + 10;
const int LOG = 19;

int n;
int s_t[MAXN], f_t[MAXN], tm;
int par[LOG][MAXN], depth[MAXN];
vector<int>	adj[MAXN];
int mark[MAXN], que[MAXN], sz, sec[MAXN];
int d[2][MAXN];

void plant(int v, int p = -1, int de = 0){
	s_t[v] = tm++;
	depth[v] = de;
	par[0][v] = p;
	for (int u:adj[v])
		if (u^p)
			plant(u, v, de + 1);
	f_t[v] = tm;
}

void preLca(){
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++)
			if (par[w - 1][v] == -1)
				par[w][v] = -1;
			else
				par[w][v] = par[w - 1][par[w - 1][v]];
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int w = LOG - 1; ~w; w--)
		if (depth[u] - (1<<w) >= depth[v])
			u = par[w][u];
	if (u == v)	return u;
	for (int w = LOG - 1; ~w; w--)
		if (par[w][u] ^ par[w][v])
			u = par[w][u], v = par[w][v];
	return par[0][u];
}

bool cmp(int u, int v){return s_t[u] < s_t[v];}

void dfs(int v, int cur){
	d[0][v] = d[1][v] = 1e7;

	int sm = 0, tot = 0;
	for (int u:adj[v]){
		dfs(u, cur);
		sm += min(d[0][u], d[1][u] + 1);
		tot += min(d[0][u], d[1][u]);
	}

	if (mark[v] ^ cur)
		d[0][v] = sm;
	else
		d[1][v] = sm;
	for (int u:adj[v])
		if (mark[v]^cur)
			d[1][v] = min(d[1][v], d[1][u] + (sm - min(d[0][u], d[1][u] + 1)));
	if (mark[v] ^ cur)
		d[0][v] = min(d[0][v], tot + 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	plant(0);
	preLca();
	int q;	scanf("%d", &q);
	for (int qq = 1; qq <= q; qq++){
		scanf("%d", &sz);
		for (int i = 0; i < sz; i++)
			scanf("%d", &que[i]), que[i]--, mark[que[i]] = qq;
		int temp = sz;
		bool fail = 0;
		for (int i = 0; !fail && i < temp; i++)
			if (~par[0][que[i]] && mark[par[0][que[i]]] == qq)
				fail = 1;
		if (fail){
			printf("-1\n");
			continue;
		}

		sort(que, que + sz, cmp);
		for (int i = 0; i < temp; i++)
			que[sz++] = lca(que[i], que[(i + 1) % temp]);
		sort(que, que + sz, cmp);
		sz = unique(que, que + sz) - que;
		for (int i = 0; i < sz; i++)	adj[que[i]].clear();
		int t = 0;
		reverse(que, que + sz);
		for (int i = 0; i < sz; i++){
			int v = que[i];
			while (t && f_t[sec[t - 1]] <= f_t[v])
				adj[v].push_back(sec[--t]);
			sec[t++] = v;
		}
		int v = que[sz - 1];
		dfs(v, qq);
		printf("%d\n", min(d[0][v], d[1][v]));
	}
	return 0;
}