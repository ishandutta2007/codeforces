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
int n, m;
int a, b;
vector <int> v[nax];
int h[nax];
int lca[nax][17];
int low[nax];
bool odw[nax];
int w[nax][17];
void dfs(int node, int par)
{
	odw[node] = 1;
	low[node] = h[node];
	for(auto it: v[node])
	{
		if(odw[it] == 0)
		{
			h[it] = h[node] + 1;
			lca[it][0] = node;
			dfs(it, node);
			low[node] = min(low[node], low[it]);
		}
		else if(it != par)
			low[node] = min(low[node], h[it]);
	}
	if(low[node] == h[node])
		w[node][0] = 1;
}
int daj(int x, int y)
{
	int ans = 0;
	if(h[x] < h[y])
		swap(x, y);
	for(int i = 16; i >= 0; --i)
		if(h[x] - (1 << i) >= h[y])
			ans += w[x][i], x = lca[x][i];
	if(x == y)
		return ans;
	for(int i = 16; i >= 0; --i)
		if(lca[x][i] != lca[y][i])
		{
			ans += w[x][i];
			ans += w[y][i];
			x = lca[x][i];
			y = lca[y][i];
		}
	ans += w[x][0] + w[y][0];
	return ans;
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; m > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
			w[i][j] = w[i][j - 1] + w[lca[i][j - 1]][j - 1];
		}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", daj(a, b));
	}
	
		
		
	return 0;
}