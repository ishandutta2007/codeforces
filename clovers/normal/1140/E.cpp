#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200001;
const ll MOD=998244353;

ll qpow(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=(ret*x)%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll n,dp[N][2],k,a[2][N],ans=1;
int main()
{
	scanf("%lld%lld",&n,&k);
	dp[0][0]=1;
	dp[1][1]=k-1; dp[1][0]=k-2;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=(dp[i-1][1]+(k-2)*dp[i-1][0])%MOD;
		dp[i][1]=dp[i-1][0]*(k-1)%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		a[i%2][(i+1)/2]=x;
	}
	a[1][0]=a[1][(n+1)/2+1]=0;
	a[0][0]=a[0][n/2+1]=0;
	int l=0;
	for(int i=1;i<=(n+1)/2+1;i++)
	{
		if(a[1][i]!=-1)
		{
			if(l==0&&i==(n+1)/2+1)
			{
				ans=ans*k%MOD*qpow(k-1,(n+1)/2-1)%MOD;
				l=i;
				continue;
			}
			if(l==0||i==(n+1)/2+1) 
			{
				if(i-l-2<0) 
				{
					l=i;
					continue;
				}
				ans=ans*(dp[i-l-2][1]+dp[i-l-2][0]*(k-1)%MOD)%MOD;
				l=i;
				continue;
			}
			if(a[1][i]==a[1][l]) ans=ans*dp[i-l-1][1]%MOD;
			else ans=ans*dp[i-l-1][0]%MOD;
			l=i;
		}
	}
	//cout<<ans<<endl;
	l=0;
	for(int i=1;i<=n/2+1;i++)
	{
		if(a[0][i]!=-1)
		{
			if(l==0&&i==n/2+1)
			{
				ans=ans*k%MOD*qpow(k-1,n/2-1)%MOD;
				l=i;
				continue;
			}
			if(l==0||i==n/2+1) 
			{
				if(i-l-2<0) 
				{
					l=i;
					continue;
				}
				ans=ans*(dp[i-l-2][1]+dp[i-l-2][0]*(k-1)%MOD)%MOD;
				l=i;
				continue;
			}
			if(a[0][i]==a[0][l]) ans=ans*dp[i-l-1][1]%MOD;
			else ans=ans*dp[i-l-1][0]%MOD;
			l=i;
		}
	}
	cout<<ans<<endl;
}