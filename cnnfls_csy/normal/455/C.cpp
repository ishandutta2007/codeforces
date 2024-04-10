#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
vector<int> bi[300005];
int n,m,i,j,k,length[300005],x,y,cnt,lenc1[300005],lenc2[300005],fa[300005],ch,ans,s;
int findf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=findf(fa[x]);
}
void dfs(int x,int fath,int dep)
{
	//bool bo=0;
	fa[x]=i;
	if (dep>ans)
	{
		ans=dep;
		s=x;
	}
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fath) continue;
		dfs(bi[x][i],x,dep+1);
		//bo=1;
	}
	//if (bo) depth=-1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	//for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
		fa[findf(x)]=findf(y);
	}
	for (i=1;i<=n;i++)
	{
		if (fa[i]) continue;
		ans=s=-1;
		dfs(i,-1,0);
		ans=-1;
		dfs(s,-1,0);
		length[i]=ans;
	}
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&ch,&x);
		if (ch==1)
		{
			printf("%d\n",length[findf(x)]);
		}
		else
		{
			scanf("%d",&y);
			x=findf(x);
			y=findf(y);
			if (x!=y)
			length[x]=length[y]=max(length[x],max(length[y],(length[x]+1)/2+(length[y]+1)/2+1));
			fa[x]=y;
		}
	}
	return 0;
}