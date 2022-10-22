//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[4001],b[2001],n,m,now,ans=INF;
bool flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i)
	{
		a[i+n]=a[i];
		now=(b[1]-a[i]+m)%m;
		flag=true;
		for(int j=2;j<=n;++j)
		{
			if((b[j]-a[j+i-1]+m)%m!=now)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			ans=min(now,ans);
		}
	}
	cout<<ans;
	return 0;
}