#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,vis[300005],dis[300005],pre[300005],x,y,fa[300005],cnt[300005];
vector<int> bi[300005],seq[600005];
void bfs(int x,int cnt)
{
	queue<int> qx;
	dis[x]=0;
	vis[x]=1;
	qx.push(x);
	while (!qx.empty())
	{
		int x=qx.front();
		qx.pop();
		seq[cnt].push_back(x);
		int i;
		for (i=0;i<bi[x].size();i++)
		{
			if (!vis[bi[x][i]])
			{
				vis[bi[x][i]]=1;
				dis[bi[x][i]]=dis[x]+1;
				pre[bi[x][i]]=x;
				qx.push(bi[x][i]);
			}
		}
	}
}
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void check()
{
	int i;
	for (i=2;i<n;i++)
	{
		if (dis[i]==2)
		{
			printf("4\n1 %d %d 1 %d",pre[i],i,n);
			exit(0);
		}
	}
}
void check2()
{
	int i,j,k,l,w,x,y;
	for (i=0;i<bi[1].size();i++) cnt[find(bi[1][i])]++;
	for (i=0;i<bi[1].size();i++)
	{
		w=bi[1][i];
		if (bi[w].size()>=cnt[find(w)]) continue;
		for (j=0;j<bi[w].size();j++)
		{
			x=bi[w][j];
			if (x==1) continue;
			for (k=0;k<bi[x].size();k++)
			{
				y=bi[x][k];
				if (w==y) continue;
				if (y==1) continue;
				if (!binary_search(bi[w].begin(),bi[w].end(),y))
				{
					printf("5\n1 %d %d %d %d %d",w,x,y,w,n);
					exit(0);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
		if (x==1||x==n||y==1||y==n) continue;
		fa[find(x)]=find(y);
	}
	for (i=1;i<=n;i++) sort(bi[i].begin(),bi[i].end());
	memset(vis,0,sizeof(vis));
	memset(dis,22,sizeof(dis));
	memset(pre,0,sizeof(pre));
	bfs(1,0);
	if (dis[n]<5)
	{
		vector<int> ans;
		for (i=n;i>=1;i=pre[i])
		{
			ans.push_back(i);
		}
		reverse(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size()-1);
		for (i=0;i<ans.size();i++) printf("%d ",ans[i]);
		return 0;
	}
	check();
	check2();
	printf("-1");
	return 0;
}