#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int d[300005];
vector<int> ans;
vector<pair<int, int> > adj[300005];
int par[300005];

int parent(int x)
{
	if(x == par[x])	return x;
	return par[x] = parent(par[x]);
}

int DFS(int now, int par)
{
	int ret = 0;
	int tmp;
	for(int i = 0; i < adj[now].size(); i++)
	{
		if(adj[now][i].first == par)\
		{
			tmp = i;
			continue;
		}
		ret += DFS(adj[now][i].first, now);
	}
	if(d[now] == -1)	return 0;
	if((d[now] + ret) % 2)
	{
		ans.push_back(adj[now][tmp].second);
		return 1;
	}
	return 0;
}

int main()
{
	int N, M;	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)	scanf("%d", &d[i]);
	for(int i = 1; i <= N; i++)	par[i] = i;

	for(int i = 1; i <= M; i++)
	{
		int a, b;	scanf("%d %d", &a, &b);
		if(parent(a) != parent(b))
		{
			adj[a].push_back(make_pair(b, i));
			adj[b].push_back(make_pair(a, i));
			par[par[a]] = par[b];
		}
	}

	int c1, c2, c3;	c1 = c2 = c3 = 0;
	for(int i = 1; i <= N; i++)
	{
		if(d[i] == -1)	c1++;
		if(d[i] == 0)	c2++;
		if(d[i] == 1)	c3++;
	}

	if(c1 == 0 && c3 % 2)
	{
		puts("-1");
		return 0;
	}
	int root;
	if(c1)
	{
		bool rooted = false;
		for(int i = 1; i <= N; i++)
		{
			if(d[i] == -1)
			{
				if(!rooted) {	rooted = true; root = i; }
				else	d[i] = 0;
			}
		}
	}
	else	root = 1;

	DFS(root, -1);

	printf("%d\n", ans.size());
	for(int i = 0; i < (int)ans.size(); i++)	printf("%d ", ans[i]);
	return 0;
}