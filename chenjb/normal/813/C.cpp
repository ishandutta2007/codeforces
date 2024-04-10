#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> g[300000];
int n,start,x,father[300000],dep[300000],deepest[300000];
void dfs(int x,int pre,int depp)
{
	father[x]=pre;
	dep[x]=depp;
	deepest[x]=0;
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
		if (g[x][i]!=pre)
		{
			dfs(g[x][i],x,depp+1);
			deepest[x]=max(deepest[x],deepest[g[x][i]]+1);
		}
}
int main()
{

	int x,y;
	cin>>n>>start;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0,1);
	int ans=0;
	int now=start;
	while (now!=1)
	{
		if (dep[start]-dep[now]>=dep[now]-1)break;
		ans=max(ans,2*(deepest[now]+dep[now]-1));
		now=father[now];
	}
	cout<<ans<<endl;
	return 0;
}