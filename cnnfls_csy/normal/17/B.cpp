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
struct peo
{
	long long nl,id;
}pe[1005];
long long n,m,i,j,dis[1005][1005],x,y,z,ans,mi;
bool cmp(peo x,peo y)
{
	return x.nl>y.nl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>pe[i].nl;
		pe[i].id=i;
	}
	sort(pe+1,pe+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			dis[i][j]=1ll<<55;
		}
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		dis[x][y]=min(dis[x][y],z);
	}
	for (i=2;i<=n;i++)
	{
		mi=1ll<<55;
		for (j=1;j<i;j++)
		{
			mi=min(mi,dis[pe[j].id][pe[i].id]);
		}
		if (mi>=(1ll<<54))
		{
			cout<<-1;
			return 0;
		}
		ans+=mi;
	}
	cout<<ans;
	return 0;
}