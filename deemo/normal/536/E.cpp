//I pray in My heart That this dream Never ends..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<functional>

using namespace std;

#define Query pair<pair<int, int>, pair<int, int>>
#define U first.first
#define V first.second
#define W second.first
#define ID second.second

#define F first
#define S second

#define Node pair<pair<int, int>, pair<int, int>>
#define L first.first
#define R first.second
#define TOT second.first
#define SM second.second

const int MAXN = 1e5 + 10;
const int LOG = 19;

int n, m, f[MAXN], ans[MAXN], depth[MAXN], par[LOG][MAXN], subsz[MAXN];
int s_t[MAXN], f_t[MAXN], tm, sz;
int chain_id[MAXN], chain_sz[MAXN], pos[MAXN], head[MAXN], cur;
vector<pair<int, int>>	adj[MAXN];
Query que[MAXN];
pair<int, int>	sec[MAXN];
Node NL, weed[4 * MAXN];

bool cmp(Query a, Query b){return a.W > b.W;}

void dfs(int v = 0, int p = -1, int w = 0){
	depth[v] = (~p?depth[p]+1:0);
	par[0][v] = p;
	subsz[v] = 1;
	for (auto e:adj[v])
		if (e.F^p)
			dfs(e.F, v, e.S), subsz[v] += subsz[e.F];

	if (~p)
		sec[sz++] = {w, v};
}

void preLca(){
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			par[w][i] = (~par[w - 1][i]?par[w-1][par[w-1][i]]:-1);
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int w = LOG - 1; ~w; w--)
		if (depth[u] - (1<<w) >= depth[v])
			u = par[w][u];
	if (u == v)	return u;

	for (int w = LOG - 1; w >= 0; w--)
		if (par[w][u] ^ par[w][v])
			u = par[w][u], v = par[w][v];
	return par[0][v];
}

void hld(int v = 0){
	if (head[cur] == -1)	head[cur] = v;
	pos[v] = chain_sz[cur]++;
	chain_id[v] = cur;
	s_t[v] = tm++;
	
	pair<int, int>	mx(-1, -1);
	for (auto e:adj[v])
		if (e.F ^ par[0][v])
			mx = max(mx, make_pair(subsz[e.F], e.F));

	if (~mx.F)
		hld(mx.S);
	for (auto e:adj[v])
		if (e.F ^ par[0][v] && e.F ^ mx.S)
			cur++, hld(e.F);
	f_t[v] = tm;
}

Node merge(Node a, Node b){
	Node ret;	
	ret.TOT = a.TOT + b.TOT;
	ret.L = a.L + (a.L == a.TOT? b.L: 0);
	ret.R = b.R + (b.R == b.TOT? a.R: 0);
	ret.SM = a.SM + b.SM + ((a.R != a.TOT && b.L != b.TOT)? f[a.R + b.L]: 0);
	return ret;
}

void plant(int v = 1, int b = 0, int e = n){
	weed[v].TOT = e - b;
	if (e - b == 1)	return;

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
}

void water(int v, int b, int e, int x){
	if (e - b == 1){
		weed[v].L = weed[v].R = 1;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x);
	else
		water(v<<1^1, mid, e, x);
	weed[v] = merge(weed[v<<1], weed[v<<1^1]);
}

Node smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return NL;

	int mid = (b + e)/ 2;
	return merge(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

Node cal(int u, int p){
	Node ret = NL;
	while (u^p){
		int dif = (depth[u] - depth[p]);
		if (pos[u] < dif)
			ret = merge(smoke(1, 0, n, s_t[u] - pos[u], s_t[u]+1), ret), u = par[0][head[chain_id[u]]];
		else
			ret = merge(smoke(1, 0, n, s_t[u]+1 - dif, s_t[u]+1), ret), u = p;
	}
	return ret;
}

void solve(Query x){
	int u = x.U, v = x.V;
	int p = lca(u, v);

	Node y = cal(u, p);
	Node z = cal(v, p);	
	swap(z.L, z.R);
	y = merge(z, y);	
	ans[x.ID] = y.SM + f[y.L] + (y.L!=y.TOT?f[y.R]:0);
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++)	scanf("%d", &f[i]);
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	scanf("%d %d %d", &a, &b, &c), a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	memset(head, -1, sizeof(head));
	dfs();
	preLca();
	hld();
	sort(sec, sec + sz, greater<pair<int, int>>());
	
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &que[i].U, &que[i].V, &que[i].W), que[i].ID = i, que[i].U--, que[i].V--;
	sort(que, que + m, cmp);	

	plant();
	int b = 0;
	for (int i = 0; i < sz; i++){
		while (b < m && que[b].W > sec[i].F)
			solve(que[b++]);
		water(1, 0, n, s_t[sec[i].S]);
	}
	while (b < m)	solve(que[b++]);

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}