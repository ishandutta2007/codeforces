#include<bits/stdc++.h>
#define MaxN 400123
typedef long long LL;
LL a[MaxN],sum[MaxN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
	a[i+n]=a[i];
	sum[1]=a[1];
	for(int i=2;i<=2*n;++i)
	sum[i]=sum[i-2]+a[i];
	LL maxv=0;
	for(int i=n;i<=2*n;++i)
	{
		LL ans=sum[i]-(i-n-1==-1?0:sum[i-n-1]);
		maxv=std::max(maxv,ans);
	}
	printf("%lld\n",maxv);
	return 0;
}