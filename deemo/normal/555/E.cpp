#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int LOG = 20;

int n, m, q, sz;
int from[MAXN], to[MAXN], aa[MAXN], bb[MAXN];
vector<int>	adj[MAXN];
bool del[MAXN];
short vis[MAXN];
int comp[MAXN], depth[MAXN];

void go(int v, int g){
	if (vis[v])	return;
	vis[v] = 1;
	comp[v] = g;
	for (int e:adj[v]){
		if (del[e])	continue;
		int u = from[e]^to[e]^v;
		go(u, g);
	}
}

int dfs(int v, int p = -1, int de = 0){
	vis[v] = 1;
	depth[v] = de;
	int ret = de;
	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			if (vis[u])
				ret = min(ret, depth[u]);
			else{
				int temp = dfs(u, e, de + 1);
				if (temp > de)
					del[e] = 1;
				ret = min(ret, temp);
			}
		}
	return ret;
}

int par[LOG][MAXN], ss[MAXN], tt[MAXN];

void plant(int v, int p = -1, int de = 0){
	depth[v] = de;
	par[0][v] = p;
	for (int u:adj[v])
		if (u^p)
			plant(u, v, de + 1);
}

void preLca(){
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < sz; i++)
			if (par[w - 1][i] == -1)
				par[w][i] = -1;
			else
				par[w][i] = par[w - 1][par[w - 1][i]];
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

pair<int, int> dfs2(int v, int p = -1){
	vis[v] = 1;
	int s = ss[v];
	int t = tt[v];
	for (int u:adj[v])
		if (u^p){
			auto temp = dfs2(u, v);
			s += temp.first;
			t += temp.second;
		}
	if (bool(s) && bool(t)){
		printf("No\n");
		exit(0);
	}
	return {s, t};
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);
	for (int i = 0; i < n; i++)
		if (!vis[i])
			go(i, i);
	for (int i = 0; i < q; i++){
		scanf("%d %d", &aa[i], &bb[i]), aa[i]--, bb[i]--;
		if (comp[aa[i]] ^ comp[bb[i]]){
			printf("No\n");
			return 0;
		}
	}
	memset(vis, 0, sizeof(vis));
	dfs(0);
	memset(vis, 0, sizeof(vis));
	memset(comp, 0, sizeof(comp));
	for (int i = 0; i < n; i++)
		if (!vis[i])
			go(i, sz++);
	for (int i = 0; i < n; i++)
		adj[i].clear();

	for (int e = 0; e < m; e++)
		if (del[e]){
			adj[comp[from[e]]].push_back(comp[to[e]]);
			adj[comp[to[e]]].push_back(comp[from[e]]);
		}
		
	plant(0);
	preLca();
	
	for (int i = 0; i < q; i++)
		if (comp[aa[i]] ^ comp[bb[i]]){
			int a = comp[aa[i]], b = comp[bb[i]];
			int p = lca(a, b);
			ss[a]++;
			ss[p]--;
			tt[p]--;
			tt[b]++;
		}

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < sz; i++)
		if (!vis[i])
			dfs2(i);
	printf("Yes\n");
	return 0;
}