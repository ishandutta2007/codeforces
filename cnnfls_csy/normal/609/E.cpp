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
long long n,m,i,j,fa[200005][19],mx[200005][19],par[200005],ans,dep[200005];
struct bian
{
	long long x,y,z,id,vis;
}bi[200005];
bool cmp(bian x,bian y)
{
	return x.z<y.z;
}
bool cmp2(bian x,bian y)
{
	return x.id<y.id;
}
vector<long long> bi2[200005];
int findfa(int x)
{
	if (par[x]==x) return x;
	return par[x]=findfa(par[x]);
}
void dfs(int x,int par)
{
	fa[x][0]=par;
	int i;
	for (i=0;i<bi2[x].size();i++)
	{
		int to=bi[bi2[x][i]].x^bi[bi2[x][i]].y^x;
		if (to==par) continue;
		mx[to][0]=bi[bi2[x][i]].z;
		dep[to]=dep[x]+1;
		dfs(to,x);
	}
}
long long mxlca(int x,int y)
{
	long long ans=0;
	int i;
	if (dep[x]>dep[y]) swap(y,x);
	int t=dep[y]-dep[x];
	for (i=0;i<=18;i++)
	{
		if ((1<<i)&t)
		{
			ans=max(ans,mx[y][i]);
			y=fa[y][i];
		}
	}
	if (x==y) return ans;
	for (i=18;i>=0;i--)
	{
		if (fa[x][i]!=fa[y][i])
		{
			ans=max(ans,mx[x][i]);
			ans=max(ans,mx[y][i]);
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return max(ans,max(mx[x][0],mx[y][0]));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>bi[i].x>>bi[i].y>>bi[i].z;
		bi[i].id=i;
		bi[i].vis=0;
	}
	sort(bi+1,bi+m+1,cmp);
	for (i=1;i<=n;i++) par[i]=i;
	for (i=1;i<=m;i++)
	{
		if (findfa(bi[i].x)==findfa(bi[i].y)) continue;
		par[findfa(bi[i].x)]=findfa(bi[i].y);
		ans+=bi[i].z;
		bi[i].vis=1;
		bi2[bi[i].x].push_back(bi[i].id);
		bi2[bi[i].y].push_back(bi[i].id);
	}
	sort(bi+1,bi+m+1,cmp2);
	dfs(1,1);
	for (j=1;j<=18;j++)
	{
		for (i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
			mx[i][j]=max(mx[i][j-1],mx[fa[i][j-1]][j-1]);
		}
	}
	/*for (i=1;i<=m;i++)
	{
		if (bi[i].vis) cerr<<i<<endl;
	}*/
	/*for (i=1;i<=n;i++)
	{
		cerr<<fa[i][0]<<' '<<mx[i][0]<<endl;
	}*/
	for (i=1;i<=m;i++)
	{
		if (bi[i].vis)
		{
			cout<<ans<<endl;
			continue;
		}
		cout<<ans-mxlca(bi[i].x,bi[i].y)+bi[i].z<<endl;
	}
	return 0;
}