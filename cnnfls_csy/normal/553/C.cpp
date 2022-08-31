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
long long fa[200005],n,m,i,j,x,y,z,ans,mod=1e9+7,cnt;
long long findf(long long x)
{
	if (fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
void hebing(int x,int y)
{
	x=findf(x);
	y=findf(y);
	if (x!=y) fa[x]=y;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n*2;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z)
		{
			hebing(x,y);
			hebing(x+n,y+n);
			if (findf(x)==findf(x+n))
			{
				cout<<0;
				return 0;
			}
			if (findf(y)==findf(y+n))
			{
				cout<<0;
				return 0;
			}
		}
		else
		{
			hebing(x,y+n);
			hebing(x+n,y);
			if (findf(x)==findf(x+n))
			{
				cout<<0;
				return 0;
			}
			if (findf(y)==findf(y+n))
			{
				cout<<0;
				return 0;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		if (findf(i)==i) cnt++;
	}
	ans=1;
	for (i=1;i<cnt;i++) ans=(ans*2)%mod;
	cout<<ans;
	return 0;
}