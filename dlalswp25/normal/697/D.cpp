#include <stdio.h>
#include <vector>

using namespace std;

vector<int> adj[100005];
int num[100005];
double ans[100005];

int numDFS(int now, int par)
{
	int ret = 1;
	for(int i = 0; i < adj[now].size(); i++)
	{
		if(adj[now][i] == par)	continue;
		ret += numDFS(adj[now][i], now);
	}
	num[now] = ret;
	return ret;
}

void DFS(int now, int par)
{
	long long sum = 0;
	for(int i = 0; i < adj[now].size(); i++)
	{
		if(adj[now][i] == par)	continue;
		sum += num[adj[now][i]];
	}

	for(int i = 0; i < adj[now].size(); i++)
	{
		if(adj[now][i] == par)	continue;
		ans[adj[now][i]] = ans[now] + 1.0 + (double)(sum - num[adj[now][i]]) / 2.0;
		DFS(adj[now][i], now);
	}
}

int main()
{
	int N;	scanf("%d", &N);
	for(int i = 2; i <= N; i++)
	{
		int p;	scanf("%d", &p);
		adj[p].push_back(i);
		adj[i].push_back(p);
	}

	numDFS(1, -1);
	ans[1] = 1.0;

	DFS(1, -1);

	for(int i = 1; i <= N; i++)	printf("%.15f ", ans[i]);

	return 0;
}