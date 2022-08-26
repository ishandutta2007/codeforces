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
int num[300005],n,m,i,j,ans=0,sl,sr,l,r,mid,now,cnt[300005],ssl,ssr;
bool check(int x)
{
	int i;
	for (i=1;i+x-1<=n;i++)
	{
		if (cnt[i+x-1]-cnt[i-1]<=m)
		{
			sl=i;
			sr=i+x-1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>num[i];
	for (i=1;i<=n;i++) cnt[i]=cnt[i-1]+1-num[i];
	l=0;r=n+1;
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			ans=mid;
			ssl=sl;
			ssr=sr;
			l=mid+1;
		}
		else r=mid;
	}
	cout<<ans<<endl;
	for (i=1;i<sl;i++) cout<<num[i]<<' ';
	for (i=sl;i<=sr;i++) cout<<"1 ";
	for (i=sr+1;i<=n;i++) cout<<num[i]<<' ';
	return 0;
}