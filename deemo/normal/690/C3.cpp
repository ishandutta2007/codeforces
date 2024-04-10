#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 200000 + 100;
const int LOG = 20;

int n, par[LOG][MAXN], depth[MAXN];

void add(int v, int p){
	par[0][v] = p;
	for (int w = 1; w < LOG; w++)
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
		if (par[w][u] != par[w][v])
			u = par[w][u], v = par[w][v];
	return par[0][u];
}

int get(int u, int v){
	int p = lca(u, v);
	return depth[u] + depth[v] - depth[p] - depth[p];
}

int main(){
	scanf("%d", &n);
	memset(par, -1, sizeof(par));
	int x = 0, y = 0;
	int ans = 0;
	for (int i = 1; i < n; i++){
		int p;	scanf("%d", &p), p--;
		depth[i] = depth[p] + 1;
		add(i, p);
	
		if (get(i, x) > ans)	y = i, ans = get(i, x);
		if (get(i, y) > ans)	x = i, ans = get(i, y);
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}