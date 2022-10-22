//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 1000000007
using namespace std;
int f[50],t,n,m,k,T,ans,dp[2005][50],a[200005],p[200005];
struct sp{
	int x,y;
	bool operator < (const sp &TMP)const
	{
		return x==TMP.x?y<TMP.y:x<TMP.x;
	}
}s[2005];
int power(int a,int b)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=(tmp*a)%MOD;
		}
		a=(a*a)%MOD;
		b>>=1;
	}
	return tmp;
}
int C(int N,int M)
{
	return a[M]*p[M-N]%MOD*p[N]%MOD;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k>>T;
	a[0]=1;
	p[0]=1;
	for(int i=1;i<=200000;++i)
	{
		a[i]=(a[i-1]*i)%MOD;
		p[i]=(p[i-1]*power(i,MOD-2))%MOD;
	}
	T<<=2;
	for(int i=T;i>1;i=(i+1)>>1)
	{
		f[t++]=i;
	}
	f[t]=1;
	for(int i=1;i<=k;++i)
	{
		cin>>s[i].x>>s[i].y;
	}
	s[++k]=(sp){1,1};
	s[++k]=(sp){n,m};
	sort(s+1,s+1+k);
	dp[1][1]=1;
	for(int i=2;i<=k;++i)
	{
		for(int j=2;j<=t;++j)
		{
			for(int l=1;l<i;++l)
			{
				if(s[i].x<s[l].x||s[i].y<s[l].y)
				{
					continue;
				}
				dp[i][j]=(dp[i][j]+dp[l][j-1]*C(s[i].x-s[l].x,s[i].x+s[i].y-s[l].x-s[l].y))%MOD;
			}
		}
		for(int j=2;j<t;++j)
		{
			dp[i][j]=(dp[i][j]+MOD-dp[i][j+1])%MOD;
		}
	}
	for(int i=2;i<=t;++i)
	{
		ans=(ans+dp[k][i]*f[i])%MOD;
	}
	ans=(ans*power(C(n-1,n+m-2),MOD-2))%MOD;
	cout<<ans<<endl;
	return 0;
}