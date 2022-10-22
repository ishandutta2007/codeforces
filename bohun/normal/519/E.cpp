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
vector <int> v[nax];
int a, b;
int siz[nax];
int lca[nax][17];
int h[nax];

void dfs(int node, int par)
{
	siz[node] = 1;
	for(auto it: v[node])
		if(it != par)
		{
			h[it] = h[node] + 1;
			dfs(it, node);
			siz[node] += siz[it];
			lca[it][0] = node;
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
	for(int i = 16; 0 <= i; --i)
		if(lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	return lca[x][0];
}
int dis(int x, int y)
{
	return h[x] + h[y] - 2 * h[daj(x, y)];
}
int pls(int node, int up)
{
	for(int i = 16; 0 <= i; --i)
		if((1 << i) & up)
			node = lca[node][i];
	return siz[node];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	int q;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &a, &b);
		if(dis(a, b) & 1)
		{
			printf("0\n");
			continue;
		}
		if(a == b)
		{
			printf("%d\n", n);
			continue;
		}
		int c = daj(a, b);
		int hh = h[c];
		if(h[a] == h[b])
		{
			int dif = h[a] - hh - 1;
			printf("%d\n", n - pls(a, dif) - pls(b, dif));
			continue;
		}
		if(h[b] > h[a])
			swap(a, b);
		printf("%d\n", n - pls(a, dis(a, b) / 2 - 1) - (n - pls(a, dis(a, b) / 2)));
	}
			
		
		
	return 0;
}