#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#define sqr(x) (x)*(x)
using namespace std;
struct ii
{
	long long cost,id;
}co[1000005];
long long n,m,k,ans1,ans2,l,r,mid,now,i;
bool cmp(ii x,ii y)
{
	if (x.cost+x.id*mid<y.cost+y.id*mid) return 1;
	return 0;
}
long long check(long long x)
{
	long long i,sum=0;
	for (i=1;i<=x;i++)
	{
		sum+=co[i].cost+co[i].id*mid;
	}
	return sum;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) 
	{
		scanf("%d",&co[i].cost);
		co[i].id=i;
	}
	l=0;r=n+1;
	while (l<r)
	{
		mid=(l+r)/2;
		for (i=1;i<=n;i++) swap(co[i],co[rand()%n+1]);
		sort(co+1,co+n+1,cmp);
		now=check(mid);
		if (now<=m)
		{
			ans1=mid;
			ans2=now;
			l=mid+1;
		}
		else r=mid;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}