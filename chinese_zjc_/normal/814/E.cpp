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
int n,v[55],l[55][55][55],dp[55][55],sum1[55],sum2[55],ans,w[55][55],g[55],c[55][55];
//l[i][j][k]:i1,j2k
//dp[i][j][k]:i,j 
inline int C(int a,int b)
{
	return c[a][b]?c[a][b]:(c[a][b]=C(a-1,b-1)+C(a-1,b));
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	l[0][0][0]=1;
	g[0]=1;
	c[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		g[i]=g[i-1]*i%MOD;
		c[i][0]=1;
		c[i][i]=1;
	}
//	for(int i=0;i<=n;++i)
//	{
//		for(int j=0;i+j<=n;++j)
//		{
//			cout<<dfs(i,j,3)<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=2;i<=n;++i)
	{
		--v[i];
		sum1[i]=sum1[i-1]+(v[i]==1);
		sum2[i]=sum2[i-1]+(v[i]==2);
	}
	dp[v[1]+1][1]=1;
//	for(int i=1;i<=v[1]+1;++i)
//	{
//		cout<<setw(3)<<i<<":";
//		for(int j=1;j<i;++j)
//		{
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;i+j<=n;++j)
		{
			for(int k=0;i+j+k<=n;++k)
			{
				int s1=j,s2=k,t=i;
				if(l[s1][s2][t])
				{
					continue;
				}
				if(!t)
				{
					if(!s1&&s2)
					{
						for(int I=2;I<s2;++I)
						{
							l[s1][s2][t]=(l[s1][s2][t]+l[s1][s2-1-I][t]*C(s2-1,I)%MOD*g[I]%MOD*500000004)%MOD;
						}
					}
					else
					{
						if(s1>=2)
						{
							l[s1][s2][t]=(l[s1][s2][t]+l[s1-2][s2][t]*(s1-1))%MOD;
						}
						if(s2>=1)
						{
							l[s1][s2][t]=(l[s1][s2][t]+l[s1][s2-1][t]*s2)%MOD;
						}
					}
				}
				else
				{
					if(s1)
					{
						l[s1][s2][t]=(l[s1][s2][t]+l[s1-1][s2][t-1]*s1)%MOD;
					}
					if(s2)
					{
						l[s1][s2][t]=(l[s1][s2][t]+l[s1+1][s2-1][t-1]*s2)%MOD;
					}
				}
			}
		}
	}
	for(int i=v[1]+2;i<=n;++i)
	{
//		cout<<setw(3)<<i<<":";
		for(int j=1;j<i;++j)
		{
			for(int k=1;k<j;++k)
			{
				dp[i][j]=(dp[i][j]+dp[j][k]*l[sum1[j]-sum1[k]][sum2[j]-sum2[k]][i-j])%MOD;
			}
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=0;i<n;++i)
	{
		ans=(ans+l[sum1[n]-sum1[i]][sum2[n]-sum2[i]][0]*dp[n][i])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}