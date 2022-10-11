#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> to[300011];
set<int> remain;

int dfs(int o)
{
	int ch = 0;
	int edge = 0;
	for(set<int>::iterator i = remain.begin() ; i != remain.end() ;)
	{
		while(edge < to[o].size() && to[o][edge] < (*i))edge++;
		if(edge < to[o].size() && (*i) == to[o][edge])
		{
			edge++;
			i++;
			continue;
		}
		ch++;
		int nownode = *i;
		remain.erase(nownode);
		dfs(nownode);
		i = remain.upper_bound(nownode);
	}
	return ch;
}

int bfs()
{
	int all = n - 1 - int(to[1].size());
	return all;
}

int main()
{
	int k;int m;scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i++)
	{
		int a , b;scanf("%d%d" , &a , &b);
		to[a].push_back(b);
		to[b].push_back(a);
	}
	for(int i = 1 ; i <= n ; i++)remain.insert(i);

	for(int i = 1 ; i <= n ; i++)
		sort(to[i].begin() , to[i].end());
	remain.erase(1);
	int l = dfs(1);
	if(remain.size() > 0)
	{
		printf("impossible\n");
		return 0;
	}
	int r = bfs();
	if(l <= k && k <= r)printf("possible\n");
	else printf("impossible\n");
	return 0;
}