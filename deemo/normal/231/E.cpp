#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 3;
const int MAXN = 1e5 + 20;
const int MAXE = 3e5 + 20;
const int LOG = 18 + 2;

int n, m;
int from[MAXE], to[MAXE], prv[MAXE], head[MAXN], ec, dc, vc, g;
int depth[MAXN], save[MAXN], col[MAXN], cnt[MAXN];
bool vis[MAXN], mark[MAXE];
int par[MAXN][LOG];
ll ss[MAXN];

void add_edge(int u, int v){
	from[ec] = u, to[ec] = v, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, prv[ec] = head[v];	head[v] = ec++;
}

void input(){
	memset(head, -1, sizeof(head));
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		add_edge(a, b);
	}
}

int cedge(int v, int p = -1, int de = 0){
	vis[v] = 1;
	depth[v] = de;

	int mini = INF;
	for (int e = head[v]; e != -1; e = prv[e]){
		int u = to[e];
		if (vis[u]){
			if (u != p)
				mini = min(mini, depth[u]);
		}
		else{
			int t = cedge(u, v, de + 1);
			if (t > de)	mark[e] = mark[e ^ 1] = 1;
			mini = min(mini, t);
		}
	}
	return	mini;
}

void build(int v, int c){
	col[v] = c;
	vis[v] = 1;
	vc++;

	for (int e = head[v]; e != -1; e = prv[e])
		if (!mark[e]){
			dc++;
			if (!vis[to[e]])
				build(to[e], c);
		}		
}

void init(){
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = (ss[i - 1] * 2) % MOD;
}

void add_new_edges(){
	int tc = ec;
	ec = 0;

	memset(head, -1, sizeof(head));
	for (int i = 0; i < tc; i += 2)
		if (mark[i])
			add_edge(col[from[i]], col[to[i]]);
}

void build_the_tree(int v, int p = -1, int x = 0, int de = 0){
	par[v][0] = p;
	x += cnt[v];
	depth[v] = de;
	save[v] = x;
	for (int e = head[v]; e != -1; e = prv[e])
		if (to[e] != p)
			build_the_tree(to[e], v, x, de + 1);
}

void pre_lca(){
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
		if (depth[u] - (1 << i) >= depth[v])
			u = par[u][i];
	if (u == v)	return	u;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return	par[v][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	cedge(0);

	//building the new tree
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			vc = dc = 0;
			build(i, g);
			if (vc == 0)
				cnt[g++] = 0;
			else
				cnt[g++] = (dc - vc * 2)/ 2 + 1;
		}
	add_new_edges();
	build_the_tree(0);
	pre_lca();

	init();//precalculating powers of 2
	//answering queries
	int q;	cin >> q;
	while (q--){
		int u, v;	cin >> u >> v;	u--, v--;
		if (col[u] == col[v])	
			cout << ss[cnt[col[v]]] << "\n";
		else{
			u = col[u], v = col[v];
			int p = lca(u, v);
			int ret = save[v] + save[u] - save[p] * 2 + cnt[p];
			cout << ss[ret] << "\n";
		}
	}
	
	return 0;
}