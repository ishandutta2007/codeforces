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
int n,m,i,j,x,y,fa[100005][18],dep[100005],fi[100005],ed[100005],ti;
vector<int> bi[100005],seq[100005];
void dfs(int x,int fa)
{
	if (fi[x]) return;
	int i;
	fi[x]=++ti;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		dep[bi[x][i]]=dep[x]+1;
		dfs(bi[x][i],x);
	}
	ed[x]=ti;
}
int getfa(int x,int y)
{
	int i;
	for (i=0;i<18;i++)
	{
		if ((1<<i)&y)
		{
			x=fa[x][i];
		}
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>fa[i][0];
		bi[fa[i][0]].push_back(i);
	}
	for (i=1;i<=n;i++)
	{
		if (fa[i][0]==0)
		{
			fa[i][0]=i;
			dfs(i,0);
		}
	}
	for (j=1;j<=17;j++)
	{
		for (i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	for (i=1;i<=n;i++)
	{
		seq[dep[i]].push_back(fi[i]);
	}
	for (i=0;i<=n;i++) sort(seq[i].begin(),seq[i].end());
//	for (i=0;i<seq[1].size();i++) cerr<<seq[1][i]<<' ';
//	cerr<<endl;
	cin>>m;
	while (m--)
	{
		cin>>x>>y;
		if (dep[x]<y)
		{
			cout<<"0 ";
			continue;
		}
		int z=getfa(x,y);
		cout<<upper_bound(seq[dep[x]].begin(),seq[dep[x]].end(),ed[z])-lower_bound(seq[dep[x]].begin(),seq[dep[x]].end(),fi[z])-1<<' ';
	}
	return 0;
}