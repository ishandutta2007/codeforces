#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=998244353;
inline int read()
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
int n,a[5001],lim[5001],sum[5001],isum[5001],dp[5001];
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2)
			z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
int A(int n,int m)
{
	if(n<0 || m<0 || n<m)
		return 0;
	return 1ll*sum[n]*isum[n-m]%mod;
}
int main()
{
	n=read();
	sum[0]=isum[0]=1;
	for(int i=1;i<=n;++i)
	{
		sum[i]=1ll*sum[i-1]*i%mod;
		isum[i]=ksm(sum[i],mod-2);
	}
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int l=0,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(2*a[mid]<=a[i])
				lim[i]=mid,l=mid+1;
			else
				r=mid-1;
		}
	}
	dp[0]=1;
	lim[0]=-1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=lim[i];++j)
			dp[i]=(dp[i]+1ll*dp[j]*A(n-2-lim[j],lim[i]-lim[j]-1)%mod)%mod;
	if(lim[n]==n-1)
		printf("%d\n",dp[n]);
	else
		puts("0");
	return 0;
}