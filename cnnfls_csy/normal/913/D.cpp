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
struct ii
{
	int num,ti,id;
}prb[200005];
bool cmp(ii x,ii y)
{
	return x.ti<y.ti;
}
int n,m,i,j,l,r,mid,ans;
bool check(int x)
{
	int cnt=0,ti=m,i;
	for (i=1;i<=n;i++)
	{
		if (prb[i].ti<=ti&&prb[i].num>=x)
		{
			ti-=prb[i].ti;
			cnt++;
		}
	}
	return cnt>=x;
}
void print(int x)
{
	int cnt=0,ti=m,i;
	for (i=1;i<=n;i++)
	{
		if (cnt>=x) return;
		if (prb[i].ti<=ti&&prb[i].num>=x)
		{
			ti-=prb[i].ti;
			cnt++;
			cout<<prb[i].id<<' ';
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>prb[i].num>>prb[i].ti;
		prb[i].id=i;
	}
	sort(prb+1,prb+n+1,cmp);
	l=0;r=n+1;ans=0;
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
	cout<<ans<<endl<<ans<<endl;
	print(ans);
	return 0;
}