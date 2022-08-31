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
int n,m,i,j,x,y,fa[305],mi[305],mx[305],cnt[305],fi[305],q[305];
vector<int> bi[305],od,ans,nod;
bool cmp(int x,int y)
{
	return mi[x]<mi[y];
}
bool cmp2(int x,int y)
{
	return fi[x]<fi[y];
}
bool dfs1(int x,int fath)
{
	int i;
	mx[x]=-1;mi[x]=n+1;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]!=fath)
		{
			if (dfs1(bi[x][i],x)) return 1;
			mx[x]=max(mx[x],mx[bi[x][i]]);
			mi[x]=min(mi[x],mi[bi[x][i]]);
			cnt[x]+=cnt[bi[x][i]];
		}
	}
	if (x!=1&&bi[x].size()==1)
	{
		mx[x]=mi[x]=q[x];
		cnt[x]=1;
	}
	if (mx[x]-mi[x]+1!=cnt[x]) return 1;
	return 0;
}
void dfs2(int x,int fath)
{
	int i;
	ans.push_back(x);
	fi[x]=ans.size();
	for (i=0;i<bi[x].size();i++)
	{	
		if (bi[x][i]!=fath)
		{
			dfs2(bi[x][i],x);
			ans.push_back(x);
		}
	}
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		//cerr<<x<<' '<<y<<endl;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=0;j<bi[i].size();j++)
		{
			cerr<<bi[i][j]<<' ';
		}
		cerr<<endl;
	}*/
	int c=0;
	while (cin>>x)
	{
		od.push_back(x);
		q[x]=++c;
	}
	if (dfs1(1,0)) 
	{
		cout<<-1;
		return 0;
	}
	for (i=1;i<=n;i++) sort(bi[i].begin(),bi[i].end(),cmp);
	dfs2(1,0);
	for (i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}