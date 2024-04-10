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
const int mod=1e9+7;
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
int n,K,ans=1,dp[10001][51];
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
void solve(int p,int b)
{
	memset(dp,0,sizeof(dp));
	dp[0][b]=1;
	for(int i=0;i<K;++i)
		for(int j=0;j<=b;++j)
		{
			int V=ksm(j+1,mod-2);
			for(int k=0;k<=j;++k)
				(dp[i+1][k]+=1ll*V*dp[i][j]%mod)%=mod;
		}
	int sum=1,E=0;
	for(int i=0;i<=b;++i)
	{
		(E+=1ll*dp[K][i]*sum%mod)%=mod;
		sum=1ll*sum*p%mod;
	}
	ans=1ll*ans*E%mod;
}
signed main()
{
	n=read(),K=read();
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0)
				++cnt,n/=i;
			solve(i,cnt);
		}
	if(n!=1)
		solve(n,1);
	printf("%lld\n",ans);
	return 0;
}