#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int a[50000],b[50000],n;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		long long x=1ll*a[1]*a[n];
		int cnt=0;
		for(int i=2;1ll*i*i<=x;i++)
			if (x%i==0)
			{
				b[++cnt]=i;
				if (i!=x/i)b[++cnt]=x/i;
			}
		if (cnt!=n){ puts("-1"); continue; }
		sort(b+1,b+n+1);
		int flag=1;
		rep(i,n)if (a[i]!=b[i])flag=0;
		if (flag)printf("%lld\n",x);
		else puts("-1");
	}
}