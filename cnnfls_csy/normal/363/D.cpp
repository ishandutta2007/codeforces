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
int bo[100005],co[100005],n,m,k,i,j,l,r,mid,ans1,ans2;
bool cmp(int x,int y)
{
	return x>y;
}
int check(int mid)
{
	if (mid>m||mid>n) return 0;
	int sum=0,i;
	for (i=1;i<=mid;i++)
	{
		sum+=max(0,co[mid-i+1]-bo[i]);
		if (sum>k) return 0;
	}
	return 1;
}
int main()
{
	cin>>n>>m>>k;
	for (i=1;i<=n;i++) cin>>bo[i];
	for (i=1;i<=m;i++) cin>>co[i];
	sort(co+1,co+1+m);
	sort(bo+1,bo+1+n,cmp);
	l=0;r=min(m,n)+1;
	while (l+1<r)
	{
		mid=(l+r)/2;
		if (mid>n||mid>m)
		{
			r=mid;
			continue;
		}
		if (check(mid)) l=mid;
			else r=mid;
	}
	ans1=l;
	for (i=1;i<=ans1;i++) ans2+=co[i];
	ans2-=k;
	cout<<ans1<<' '<<max(0,ans2);
	return 0;
}