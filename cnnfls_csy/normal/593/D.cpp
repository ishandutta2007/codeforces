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
long long n,m,i,j,ex[200005],ey[200005],ez[200005],op,dep[200005],fa[200005],nxt[200005],nxts[200005],pre[200005];
int find(int x)
{
	if (pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
struct bian
{
	long long to,wei,id;
};
vector<bian> bi[200005];
void dfs(long long x,long long par)
{
	long long i;
	fa[x]=par;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].to==par) continue;
		if (bi[x][i].to!=ex[bi[x][i].id])
		{
			 swap(ex[bi[x][i].id],ey[bi[x][i].id]);
		}
		dep[bi[x][i].to]=dep[x]+1;
		nxts[bi[x][i].to]=bi[x][i].wei;
		dfs(bi[x][i].to,x);
	}
}
/*9long long lca(long long x,long long y)
{
	if (dep[x]>dep[y]) swap(x,y);
	long long i,t=dep[y]-dep[x];
	for (i=0;i<=18;i++)
	{
		if ((1<<i)&t) y=fa[y][i];
	}
	if (x==y) return x;
	for (i=18;i>=0;i--)
	{
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}*/
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>ex[i]>>ey[i]>>ez[i];
		bi[ex[i]].push_back((bian){ey[i],ez[i],i});
		bi[ey[i]].push_back((bian){ex[i],ez[i],i});
	}
	for (i=1;i<=n;i++) pre[i]=i;
	dep[0]=-1;
	dfs(1,0);
	nxt[1]=1;
	nxts[1]=1;
	nxts[0]=1;
	/*for (j=1;j<=18;j++)
	{
		for (i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}*/
	//for (i=2;i<=n;i++) nxt[i]=fa[i];
	for (i=2;i<=n;i++)
	{
		if (nxts[i]==1)
		{
			pre[i]=fa[i];
		}
	}
	for (i=1;i<=m;i++)
	{
		cin>>op;
		if (op==1)
		{
			long long x,y,z,t;
			cin>>x>>y>>z;
			x=find(x);y=find(y);
			while (x!=y&&z!=0)
			{
				if (dep[x]>dep[y])
				{
					z/=nxts[x];
					x=find(fa[x]);
				}
				else
				{
					z/=nxts[y];
					y=find(fa[y]);
				}
			}
			cout<<z<<endl;
		}
		else
		{
			long long x,y,z,t;
			cin>>x>>y;
			x=ex[x];
			nxts[x]=y;
			if (y==1) pre[x]=fa[x];
		}
	}
	return 0;
}