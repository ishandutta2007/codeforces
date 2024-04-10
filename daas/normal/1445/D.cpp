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
int n,N,a[300001],cnt1,cnt2,ans;
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
	int bck=1;
	for(int i=n;i>=n-m+1;--i)
		bck=1ll*bck*i%mod;
	return bck;
}
int C(int n,int m)
{
	return 1ll*A(n,m)*ksm(A(m,m),mod-2)%mod;
}
int main()
{
	n=read();
	N=n*2;
	for(int i=1;i<=N;++i)
		a[i]=read();
	sort(a+1,a+N+1);
	cnt1=C(N,n);
	for(int i=1;i<=n;++i)
		ans=(ans-1ll*a[i]*cnt1%mod+mod)%mod;
	for(int i=n+1;i<=N;++i)
		ans=(ans+1ll*a[i]*cnt1%mod)%mod;
	printf("%d\n",ans);
	return 0;
}