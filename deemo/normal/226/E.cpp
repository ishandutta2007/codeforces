//I know I'm not the only one
//Who regrets the things they've done
//Sometimes I just feel it's only me
//Who can't stand the reflection that they see..

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 1e5 + 30;
const int LOG = 20;
const int MAX = 3e6;//XXX
const int INF = 1e9 + 7;

int n, q, root[max_n], rt;
int par[max_n][LOG];
vector<int>	child[max_n];
int depth[max_n], s_t[max_n], f_t[max_n], sz;
int le[MAX], ri[MAX];
int seg[MAX];
int mark[max_n];

void dfs(int v, int de){
	s_t[v] = sz++;
	depth[v] = de;
	for (int u:child[v])
		dfs(u, de + 1);
	f_t[v] = sz;
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
	dfs(rt, 0);
	sz = 0;
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[u][i];
	if (u == v)	return	v;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return	par[v][0];
}

int build(int b, int e){
	int id = sz++;
	if (e - b == 1)	return	id;

	int mid = (b + e)/ 2;
	le[id] = build(b, mid);
	ri[id] = build(mid, e);
	return	id;
}

int add(int id, int b, int e, int l, int r, int val){
	int newid = sz++;
	le[newid] = le[id];
	ri[newid] = ri[id];
	seg[newid] = seg[id];
	if (l <= b && e <= r){
		seg[newid]++;
		return newid;
	}
	if (r <= b || e <= l)	return	newid;

	int mid = (b + e)/ 2;
	le[newid] = add(le[newid], b, mid, l, r, val);
	ri[newid] = add(ri[newid], mid, e, l, r, val);
	return	newid;
}

int get(int id, int b, int e, int x){
	if (e - b == 1)	return	seg[id];
	
	int mid = (b + e)/ 2;
	if (x < mid)
		return	seg[id] + get(le[id], b, mid, x);
	return	seg[id] + get(ri[id], mid, e, x);
}

int f(int u, int p, int k, int y, int cur){
	if (k <= 0)	return	-INF;
	for (int i = LOG - 1; k && i >= 0; i--){
		if (depth[u] - (1 << i) < depth[p])	continue;
		int x = get(root[cur], 0, n, s_t[par[u][i]]) - get(root[y], 0, n, s_t[par[u][i]]);
		x = get(root[cur], 0, n, s_t[u]) - get(root[y], 0, n, s_t[u]) - x;
		x = (1 << i) - x;
		if (x < k)
			u = par[u][i], k -= x;
	}

	if (u != p){
		u = par[u][0];
		return	u;
	}	
	if (k == 0 && mark[u] <= y)	return	u;
	return	-k;
}

int g(int u, int p, int k, int y, int cur){
	int v = u;
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[p] + 1)	v = par[v][i];
	p = v;

	int x = get(root[cur], 0, n, s_t[u]) - get(root[y], 0, n, s_t[u]);
	x = x - get(root[cur], 0, n, s_t[p]) + get(root[y], 0, n, s_t[p]);
	x = depth[u] - depth[p] - x;
	x = x - k + 1; 
	return	f(u, p, x, y, cur);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &par[i][0]);
		par[i][0]--;
		if (par[i][0] != -1)	child[par[i][0]].push_back(i);
		if (par[i][0] == -1)	rt = i;
	}
	init();

	root[0] = build(0, n);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		int type;	scanf("%d", &type);
		if (type == 1){
			int v;	scanf("%d", &v);	v--;
			root[i] = add(root[i - 1], 0, n, s_t[v] + 1, f_t[v], 1);
			mark[v] = i;
		}
		else{
			int u, v, k, y;	scanf("%d%d%d%d", &u, &v, &k, &y);	u--, v--; 
			root[i] = root[i - 1];
			int p = lca(u, v);
			int ans = f(u, p, k, y, i);
			if (ans >= 0 && ans != v)	printf("%d\n", ans + 1);
			else{
				if (ans == -INF)	printf("-1\n");
				else{
					k = -ans;
					ans = g(v, p, k, y, i);
					if (ans < 0)	ans = -2;
					printf("%d\n", ans + 1);
				}
			}
		}
	}
	return	0;
}