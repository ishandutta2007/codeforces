#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353;
int n,i,j;
long long f[N],s,iv2=(M+1)/2,iv3=(M+1)/3,ans,as1,as2,g[N],sum[N];
int main()
{
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(i=2;i<=n;++i)
	{
		s=(s+f[i-2])%M;
		f[i]=(f[i-1]*(f[i-1]+1)%M*iv2+s*f[i-1])%M;
		g[i]=(f[i-1]*(f[i-1]+1)%M*iv2+(s-1)*f[i-1])%M;
	}
	s=(s+f[n-1])%M;
	ans=(ans+f[n]*(f[n]+1)%M*(f[n]+2)%M*iv2%M*iv3)%M;
	ans=(ans+f[n]*(f[n]+1)%M*iv2%M*s)%M;
	for(i=0;i<n;++i)
	{
		as1=(as1+f[i]*(f[i]+1)%M*iv2)%M;
		as2=(as2+(s-f[i])*f[i])%M;
		s=(s-f[i])%M;
	}
	ans=(ans+(as1+as2)*f[n])%M;
	ans=(ans*2-1)%M;
	sum[2]=g[2];
	for(i=3;i<=n;++i)
		sum[i]=(sum[i-1]+g[i])%M;
	for(i=2;i<=n;++i)
		ans=(ans+g[i]*sum[n-i+1])%M;
	cout<<(ans%M+M)%M;
}