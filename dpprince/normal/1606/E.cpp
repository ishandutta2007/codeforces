// By: Little09
// Problem: E. Arena
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
int n,m;
const int N=505;
ll dp[N][N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
ll KSM[N][N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int main()
{
	init();
	n=read(),m=read();
	int t=max(n,m);
	for (int i=0;i<=t;i++)
	{
		for (int j=0;j<=t;j++)
		{
			KSM[i][j]=ksm(i,j);
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (j<=i-1) 
			{
				dp[i][j]=KSM[j][i];
				for (int k=1;k<j;k++)
				{
					dp[i][j]=(dp[i][j]-dp[i][k]+mod)%mod;
				}
				//cout << dp[i][j] << " ";
				continue;
			}
			dp[i][j]=(dp[i][j]+dp[i][j-(i-1)])%mod;
			for (int k=1;k<i;k++)
			{
				dp[i][j]=(dp[i][j]+C(i,k)*dp[i-k][j-(i-1)]%mod*KSM[i-1][k]%mod)%mod;
			}
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	ll ans=0;
	for (int j=1;j<=m;j++)
	{
		ans=(ans+dp[n][j])%mod;
	}
	cout << ans;
	return 0;
}