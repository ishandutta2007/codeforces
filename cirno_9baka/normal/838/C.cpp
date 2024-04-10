#include<bits/stdc++.h>
using namespace std;
const int N=266666;
int n,k,i,j,u,v,w,M=1000000009;
long long fac[N],inv[N],dp[30][22],a[18][N],b[N];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		b>>=1;
		s=s*s%M;
	}
	return ans;
}
int main()
{
	scanf("%d %d %d",&n,&k,&M);
	if(n&1)
	{
		cout<<qpow(k,n);
		return 0;
	}
	fac[0]=1;
	for(i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%M;
	inv[n]=qpow(fac[n],M-2);
	for(i=n-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%M;
	for(i=0;i<=n;++i)
		if((n&i)==i)
		{
			int pp=__builtin_popcount(i);
			int u=0,s=0;
			for(j=0;j<18;++j)
			{
				if((i>>j)&1)
					s+=1<<u;
				if((n>>j)&1)
					++u;
			}
			a[pp][s]=inv[i];
		}
	int pn=__builtin_popcount(n);
	for(i=0;i<pn;++i)
		for(j=0;j<pn;++j)
			for(u=0;u<(1<<pn);++u)
				if((u>>j)&1)
					a[i][u]+=a[i][u^(1<<j)];
	for(i=0;i<pn;++i)
		for(u=0;u<(1<<pn);++u)
			a[i][u]%=M;
	for(i=0;i<(1<<pn);++i)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(j=1;j<=k;++j)
		{
			for(u=0;u<=pn;++u)
			{
				for(v=0;u+v<=pn;++v)
					dp[j][u+v]=dp[j][u+v]+a[u][i]*dp[j-1][v];
				if(u&7==0)
					for(v=0;v<=pn;++v)
						dp[j][v]%=M;
			}
			for(v=0;v<=pn;++v)
				dp[j][v]%=M;
		}
		b[i]=dp[k][pn];
	}
	for(i=0;i<pn;++i)
		for(j=0;j<(1<<pn);++j)
			if((j>>i)&1)
				b[j]-=b[j^(1<<i)];
	cout<<((qpow(k,n)-b[(1<<pn)-1]%M*fac[n])%M+M)%M<<endl;
}