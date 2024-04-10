#include<bits/stdc++.h>
using namespace std;
const int N=10000005,E=1005,L=1000000000,M=998244353;
const long long inf=2000000000;
int n,m,x,t,i;
long long mi[N],inv[N],s[N];
long long fac[N],ifac[N];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long C(int n,int m)
{
	return fac[n]*ifac[m]%M*ifac[n-m]%M;
}
int main()
{
	scanf("%d",&t);
	mi[0]=s[0]=1;
	for(i=1;i<N;++i)
		mi[i]=mi[i-1]*2%M;
	for(i=0;i<N;++i)
		--mi[i];
	for(i=1;i<N;++i)
		s[i]=s[i-1]*mi[i]%M;
	inv[N-1]=qpow(s[N-1],M-2);
	for(i=N-2;i>=1;--i)
		inv[i]=inv[i+1]*mi[i+1]%M;
	for(i=1;i<N;++i)
		inv[i]=inv[i]*s[i-1]%M;
	fac[0]=ifac[0]=1;
	for(i=1;i<N;++i)
	{
		fac[i]=fac[i-1]*mi[i]%M;
		ifac[i]=ifac[i-1]*inv[i]%M;
	}
	long long iv2=qpow(2,M-2);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&x);
		if(x==0)
		{
			if(n>m)
				puts("0");
			else
			{
				long long as=C(m,n)*fac[n]%M*qpow(2,1ll*n*(n-1)/2)%M;
				printf("%lld\n",(as%M+M)%M);
			}
		}
		else
		{
			long long su=1,ans=qpow(2,1ll*m*n);
			s[0]=1;
			long long ss=qpow(2,n);
			for(i=1;i<=m&&i<=n;++i)
			{
				s[i]=s[i-1]*(ss-1)%M;
				ss=ss*iv2%M;
			}
			for(i=0;i<=m&&i<=n;++i)
			{
				s[i]=s[i]*su%M;
				su=su*(mi[i]+1)%M;
			}
			for(i=1;i<=m&&i<=n;++i)
				ans=(ans-s[i]*C(m-1,i-1))%M;
			printf("%lld\n",(ans%M+M)%M);
		}
	}
}