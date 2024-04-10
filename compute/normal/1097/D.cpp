#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e4+7;
long long dp[500][maxn],k;
long long invo[500];
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long inv(long long n)
{
	return quick(n,mod-2);
}
void db()
{
	for(int i=1;i<500;i++)
		invo[i]=inv(i);
}
long long solve(long long cur,long long num)
{
	memset(dp,0,sizeof(dp));
	dp[num][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=num;j>=0;j--)
		{
			if(!dp[j][i-1]) continue;
			for(int p=j;p>=0;p--)
				dp[p][i]=(dp[p][i]+dp[j][i-1]*invo[j+1]%mod)%mod;
		}
	}
	long long ret=0;
	for(int i=0;i<=num;i++)
	{
		ret=(ret+quick(cur,i)*dp[i][k]%mod)%mod;
	}
	return ret;
}
int main()
{
	db();
	long long n;
	scanf("%lld%lld",&n,&k);
	long long ans=1;
	for(long long i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0)
			{
				cnt++;
				n/=i;
			}
			ans=ans*solve(i,cnt)%mod;
		}
	}
	if(n>1) ans=ans*solve(n,1)%mod;
	printf("%lld\n",ans);
}