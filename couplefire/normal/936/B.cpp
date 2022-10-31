#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 100001;
 
vector <int> G[maxN], res;
int vis[maxN][2];
bool is_cycle;
 
void dfs(int v, int par)
{
	vis[v][par] = 1;
	res.push_back(v);
	if (G[v].empty() and par == 1)
	{
		printf("Win\n");
		for (int u : res)	printf("%d ", u);
		printf("\n");
		exit(0);
	}
	for (int u : G[v])
	{
		int xase = vis[u][par ^ 1];
		if (xase == 0)	dfs(u, par ^ 1);
		if (xase == 1)	is_cycle = true;		
	}
	vis[v][par] = 2;
	res.pop_back();
}
 
int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		int a;
		scanf ("%d", &a);
		G[i].resize(a);
		for (int j=0; j<a; j++)
			scanf ("%d", &G[i][j]);
	}
	int s;
	scanf ("%d", &s);
	dfs(s, 0);
	printf("%s\n", is_cycle ? "Draw" : "Lose");
	return 0;
}