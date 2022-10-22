//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,b,mod,a[505],dp[505][505],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>b>>mod;
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		for(int j=1;j<=m;++j)
		{
			for(int k=a[i];k<=b;++k)
			{
				dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
			}
		}
	}
	for(int i=0;i<=b;++i)
	{
		ans=(ans+dp[m][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}