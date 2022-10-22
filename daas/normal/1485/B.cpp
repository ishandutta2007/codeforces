#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,K,a[100001],sum[100001];
signed main()
{
	n=read(),q=read(),K=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=2;i<n;++i) sum[i]=sum[i-1]+(a[i+1]-a[i-1]-2);
	while(q--)
	{
		int l=read(),r=read();
		if(l==r)
		{
			printf("%lld\n",K-1);
			continue;
		}
		int ans=sum[r-1]-sum[l];
		printf("%lld\n",ans+(a[l+1]-2)+(K-a[r-1]-1));
	}
	return 0;
}