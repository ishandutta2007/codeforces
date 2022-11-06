#include <iostream>
#include <utility>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std; 
vector<int> adj[204800]; 
int fa[204800], u[204800], v[204800], c[204800]; 
bool vis[204800]; 
int getfa(int x)
{
	if (fa[x] == x)
		return x; 
	return fa[x] = getfa(fa[x]); 
}
pair<int, int> bfs(int st)
{
	queue<pair<int, int> > que; 
	que.push(mp(st, 0)); 
	memset(vis, false, sizeof(vis)); 
	vis[st] = true; 
	pair<int, int> res = mp(-1, -1); 
	while (!que.empty())
	{
		int x = que.front().first, d = que.front().second; 
		que.pop(); 
		res = max(res, mp(d, x)); 
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (!vis[adj[x][i]])
			{
				vis[adj[x][i]] = true; 
				que.push(mp(adj[x][i], d + 1)); 
			}
		}
	}
	return res; 
}
int main()
{
	// freopen("734E.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", c + i); 
		fa[i] = i; 
	}
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", u + i, v + i); 
		u[i]--; 
		v[i]--; 
		if (c[u[i]] == c[v[i]])
			fa[getfa(u[i])] = getfa(v[i]); 
	}
	for (int i = 0; i < n - 1; i++)
	{
		adj[getfa(u[i])].pb(getfa(v[i])); 
		adj[getfa(v[i])].pb(getfa(u[i])); 
	}
	int tmp = bfs(getfa(0)).second;
	// cout << tmp << endl; 
	printf("%d\n", (bfs(tmp).first + 1) / 2);
	return 0; 
}