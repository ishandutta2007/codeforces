#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;
int n;
vector <pair<int, int >> v[nax];
int a, b;		
int val[nax];
int h[nax];
int lca[nax][17];
void go(int node, int par)
{
	for(auto it: v[node])
		if(it.fi != par)
		{
			h[it.fi] = h[node] + 1;
			go(it.fi, node);
			lca[it.fi][0] = node;
		}
}
int daj(int x, int y)
{
	if(h[x] < h[y])
		swap(x, y);
	for(int i = 16; i >= 0; --i)
		if(h[x] - (1 << i) >= h[y])
			x = lca[x][i];
	if(x == y)
		return x;
	for(int i = 16; i >= 0; --i)
		if(lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	return lca[x][0];
}
int ans[nax];
void dfs(int node, int par, int nr)
{
	for(auto it: v[node])
		if(it.fi != par)
		{
			dfs(it.fi, node, it.se);
			val[node] += val[it.fi];
		}
	ans[nr] = val[node];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb({b, i});
		v[b].pb({a, i});
	}
	go(1, -1);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	int k;
	scanf("%d", &k);
	for(int i = 1; k >= i; ++i)
	{
		scanf("%d %d", &a, &b);
		val[a]++;
		val[b]++;
		val[daj(a, b)] -= 2;
	}
	dfs(1, -1, n);
	for(int i = 0; n - 1 > i; ++i)
		printf("%d ", ans[i]);
	return 0;
}