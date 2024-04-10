#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[200005];
queue<int> q;

int a[200005];
int par[200005];
int table[200005][20];
long long dist[200005][20];
long long dx[200005];
long long ans[200005];
int indeg[200005];

int main()
{
	int n;	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	par[1] = 1;
	for(int i = 0; i < n - 1; i++)
	{
		int p, w;	scanf("%d %d", &p, &w);
		par[i + 2] = p;
		adj[p].push_back(i + 2);
		table[i + 2][0] = p;
		dist[i + 2][0] = w;
		indeg[p]++;
	}

	for(int i = 0; i < 20; i++)
	{
		table[1][i] = 1;
		dist[1][i] = 0;
	}

	for(int j = 1; j < 20; j++)
	{
		for(int i = 2; i <= n; i++)
		{
			table[i][j] = table[table[i][j - 1]][j - 1];
		}
	}

	for(int j = 1; j < 20; j++)
	{
		for(int i = 2; i <= n; i++)
		{
			dist[i][j] = dist[i][j - 1] + dist[table[i][j - 1]][j - 1];
		}
	}

	for(int i = 2; i <= n; i++)
	{
		if(dist[i][0] > a[i])	continue;
		dx[par[i]]++;
		long long sum = 0;
		int now = i;
		for(int j = 19; j >= 0; j--)
		{
			if(sum + dist[now][j] > a[i])	continue;
			sum += dist[now][j];
			now = table[now][j];
		}
		if(now != 1)	dx[par[now]]--;
	}

	for(int i = 1; i <= n; i++)	if(!indeg[i])	q.push(i);

	while(!q.empty())
	{
		int now = q.front();	q.pop();
		ans[now] = dx[now];
		for(int i = 0; i < adj[now].size(); i++)
		{
			dx[now] += dx[adj[now][i]];
			ans[now] += dx[adj[now][i]];
		}
		indeg[par[now]]--;
		if(indeg[par[now]] == 0)	q.push(par[now]);
	}

	for(int i = 1; i <= n; i++)	printf("%d ", ans[i]);

	return 0;
}