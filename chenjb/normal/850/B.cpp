#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#define LL long long
using namespace std;
LL ans;
int maxnum;
int n,X,Y;
int a[510000];
LL c[3200000],d[3200000];
LL get(int gcd)
{
	LL res=0;
	for(int p=gcd;p-gcd<maxnum;p+=gcd)
	{
		int k=floor(p-1.0*X/Y);
		if (k>=p-gcd+1)
			res+=(LL)(c[k]-c[p-gcd])*X + (LL)Y*((LL)(c[p]-c[k])*p-(LL)(d[p]-d[k]));
		else 
			res+=(LL)Y*((LL)(c[p]-c[p-gcd])*p-(LL)(d[p]-d[p-gcd]));

		if (res>ans)return ans;
	}
	return res;
}
int main()
{
	cin>>n>>X>>Y;
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	maxnum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxnum=max(maxnum,a[i]);
		c[a[i]]++;
		d[a[i]]+=a[i];
	}
	for(int i=1;i<=2100000;i++)
	{
		c[i]+=c[i-1];
		d[i]+=d[i-1];
	}
	ans=2147483647;
	ans=ans*1000000000;
	for(int i=2;i<=maxnum+1;i++)ans=min(ans,get(i));
	cout<<ans<<endl;
}