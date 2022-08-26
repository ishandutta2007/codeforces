//n_with_stdio(0);   " !!!!!!
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
long long n,m,w,i,j,l,r,mid,hi[100005],used[100005],ans;
bool check(long long x)
{
	long long sum=0,s=0,i;
	for (i=1;i<=n;i++)
	{
		if (i>w) sum-=used[i-w];
		if (hi[i]+sum>=x)
		{
			used[i]=0;
			continue;
		}
		used[i]=x-(hi[i]+sum);
		sum+=used[i];
		s+=used[i];
	}
	return s<=m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>w;
	for (i=1;i<=n;i++)
	{
		cin>>hi[i];
	}
	l=1;r=1e12;
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans;
	return 0;
}