//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int min(const int &A,const int &B)
{
	return A<B?A:B;
}
int t,n,a,b,dp[2][200001];
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>a>>b>>s;
		s=' '+s;
		dp[0][0]=b;
		dp[1][0]=INF;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0')
			{
				dp[0][i]=min(dp[0][i-1]+a+b,dp[1][i-1]+a+a+b);
				dp[1][i]=min(dp[0][i-1]+a+a+b+b,dp[1][i-1]+a+b+b);
			}
			else
			{
				dp[0][i]=INF;
				dp[1][i]=dp[1][i-1]+a+b+b;
			}
		}
		cout<<dp[0][n]<<endl;
	}
	return 0;
}