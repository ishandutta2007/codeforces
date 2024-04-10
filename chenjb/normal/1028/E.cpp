#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
#define mod 1000000007
using namespace std;
long long a[510000],ans[510000];
int n;
int getpre(int x)
{
	if (x==0)return n-1;
	return x-1;
}
int getsuf(int x)
{
	if (x==n-1)return 0;
	return x+1;
}
int main()
{
	cin>>n;
	long long minp=2147483647;
	long long maxp=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		maxp=max(maxp,a[i]);
		minp=min(minp,a[i]);
	}
	if (maxp==minp)
	{
		if (!maxp)
		{
			puts("YES");
			for(int i=0;i<n;i++)printf("1%c",i==n-1?'\n':' ');
		}
		else puts("NO");
		return 0;
	}
	int t;
	for(int i=0;i<n;i++)
		if (maxp!=a[getpre(i)]&&maxp==a[i])t=i;


	ans[t]=a[t];
	int now=getpre(t);
	while (now!=t)
	{
		ans[now]=a[now];
		int tmp=1;
		if (now==getpre(t))tmp++;
		ans[now]+=ans[getsuf(now)]*tmp;
		now=getpre(now);
	}

	puts("YES");
	for(int i=0;i<n;i++)printf("%lld%c",ans[i],i==n-1?'\n':' ');
}