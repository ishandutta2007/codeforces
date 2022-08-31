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
struct bing
{
	int fa[505],sz=0;
	int find(int x)
	{
		if (fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	int hebing(int x,int y)
	{
		x=find(x);
		y=find(y);
		if (x!=y)
		{
			fa[find(x)]=find(y);
			sz++;
		}
	}
}pr[10005],su[10005],ans;
int n,m,i,j,x[10005],y[10005],l,r,q;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
	}
	for (i=1;i<=n;i++) pr[0].fa[i]=su[m+1].fa[i]=i;
	for (i=1;i<=m;i++)
	{
		pr[i]=pr[i-1];
		pr[i].hebing(x[i],y[i]);
	}
	for (i=m;i;i--)
	{
		su[i]=su[i+1];
		su[i].hebing(x[i],y[i]);
	}
	cin>>q;
	for (i=1;i<=q;i++)
	{
		cin>>l>>r;
		ans=pr[l-1];
		for (j=1;j<=n;j++)
		{
			ans.hebing(j,su[r+1].find(j));
		}
		cout<<n-ans.sz<<endl;
	}
	return 0;
}