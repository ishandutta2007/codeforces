#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const int max_n = 2e5 + 20;

int n, q;
vector<int>	val, adj[max_n], depth, id, firstf, firstg, secondf, secondg;
int f, g;
int lazy[3][6 * max_n];

void dfs(int v, int p, int d){
	depth[v] = d;
	firstf[v] = f;
	firstg[v] = g;
	if (d % 2 == 0)
		id[v] = f++;
	else
		id[v] = g++;

	for (int u:adj[v]){
		if (u == p)	continue;
		dfs(u, v, d + 1);
	}

	secondf[v] = f;
	secondg[v] = g;
}

void resize(){
	val.resize(n);
	depth.resize(n);
	id.resize(n);
	firstf.resize(n);
	secondf.resize(n);
	firstg.resize(n);
	secondg.resize(n);
}

void shift(int v, int type){
	lazy[type][v<<1] += lazy[type][v];
	lazy[type][v<<1^1] += lazy[type][v];
	lazy[type][v] = 0;
}

void add(int v, int b, int e, int l, int r, int x, int type){
	if (r - l <= 0)	return;
	if (r <= b || e <= l)	return;
	if (l <= b && e <= r){
		lazy[type][v] += x;
		return;
	}
	shift(v, type);
	int mid = (b + e) / 2;
	add(v<<1, b, mid, l, r, x, type);
	add(v<<1^1, mid, e, l, r, x, type);
}

int get(int v, int b, int e, int ind, int type){
	if (ind >= e || ind < b)	return 0;
	if (e - b == 1)
		return	lazy[type][v];
	shift(v, type);
	int mid = (b + e) / 2;
	return	get(v<<1, b, mid, ind, type) + get(v<<1^1, mid, e, ind, type);
}

int main(){
	scanf("%d%d", &n, &q);
	resize();
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);

	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);		
	}
	dfs(0, -1, 0);
	
	while (q--){
		int type, v;	scanf("%d%d", &type, &v);	v--;
		if (type == 1){
			int	x;	scanf("%d", &x);
			if (depth[v] % 2 == 0){
				add(1, 0, n, firstf[v], secondf[v], x, 0);
				add(1, 0, n, firstg[v], secondg[v], -x, 1);
			}
			else{
				add(1, 0, n, firstf[v], secondf[v], -x, 0);
				add(1, 0, n, firstg[v], secondg[v], x, 1);
			}
			continue;
		}
		if (depth[v] % 2 == 0)
			printf("%d\n", val[v] + get(1, 0, n, id[v], 0));
		else	
			printf("%d\n", val[v] + get(1, 0, n, id[v], 1));
	}

	return 0;
}