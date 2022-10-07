#include<bits/stdc++.h>
using namespace std;
const int N=2000005,M=1000000007;
int n,m,ca,cb,da,db,i,cs,ds,w,f[N],mu[N],j,prime[200005],tot;
char c[N],d[N];
long long fac[N],inv[N],ans,mi[N];
long long C(int n,int m)
{
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
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
long long cal(int n,int m)
{
	int g=__gcd(n,m);
	n/=g,m/=g;
	return (mi[w/max(n,m)+1]-2)%M;
}
long long sq(long long n)
{
	return n*n%M;
}
int main()
{
	scanf("%s",c+1);
	scanf("%s",d+1);
	scanf("%d",&w);
	inv[0]=inv[1]=fac[0]=1;
	for(i=2;i<=2000000;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=2000000;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(i=1;i<=1000000;++i)
		mu[i]=1;
	mi[0]=1;
	for(i=1;i<=1000002;++i)
		mi[i]=mi[i-1]*2%M;
	for(i=2;i<=1000000;++i)
	{
		if(!f[i])
		{
			prime[++tot]=i;
			mu[i]=-1;
		}
		for(j=1;j<=tot&&prime[j]*i<=1000000;++j)
		{
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
			f[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
	for(i=1;i<=1000000;++i)
		mu[i]+=mu[i-1];
	n=strlen(c+1);
	m=strlen(d+1);
	for(i=1;c[i];++i)
	{
		if(c[i]=='A')
			++ca;
		if(c[i]=='B')
			++cb;
		if(c[i]=='?')
			++cs;
	}
	for(i=1;d[i];++i)
	{
		if(d[i]=='A')
			++da;
		if(d[i]=='B')
			++db;
		if(d[i]=='?')
			++ds;
	}
	long long s2=1,as=0;
	for(i=1;i<=w;++i)
	{
		s2=s2*2%M;
		int t=w/i;
		for(j=1;j<=t;)
		{
			int u=t/(t/j);
			as=(as+s2*sq(t/j)%M*(mu[u]-mu[j-1]))%M;
			j=u+1;
		}
	}
	for(i=-1000000;i<=1000000;++i)
		if(cs+ds>=ds+i&&ds+i>=0)
		{
			if(ca-da+i==0&&ca-da+m-n+i==0)
				ans=(ans+C(cs+ds,ds+i)*as)%M;
			if(ca-da+i<0&&ca-da+m-n+i<0)
				ans=(ans+C(cs+ds,ds+i)*cal(-(ca-da+i),-(ca-da+m-n+i)))%M;
			if(ca-da+i>0&&ca-da+m-n+i>0)
				ans=(ans+C(cs+ds,ds+i)*cal(ca-da+i,ca-da+m-n+i))%M;
		}
	if(n==m)
	{
		long long s=1;
		for(i=1;i<=n;++i)
			if(c[i]==d[i])
			{
				if(c[i]=='?')
					s=s*2%M;
			}
			else
			{
				if(c[i]!='?'&&d[i]!='?')
					break;
			}
		if(i>n)
			ans=(ans+s*(sq(mi[w+1]-2)-as))%M;
	}
	cout<<(ans%M+M)%M;
}