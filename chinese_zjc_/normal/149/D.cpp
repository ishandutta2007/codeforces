//This code was made by Chinese_zjc_
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#define int long long
#define INF (1ll<<62)
#define MOD 1000000007
using namespace std;
int t,dp[1001][1001][4][4],now,x[1001],sum,ans;
//0:no color
//1:purple
//2:pink
string s;
stack <int> sta;
void dfs(int l,int r)
{
	if(l+1==r)
	{
		for(int i=1;i<=2;++i)
		{
			dp[l][r][i][0]=dp[l][r][0][i]=1;
		}
		return;
	}
	if(x[l]==r)
	{
		dfs(l+1,r-1);
		for(int i=1;i<=2;++i)
		{
			for(int j=0;j<=2;++j)
			{
				for(int k=0;k<=2;++k)
				{
					if(i!=j)
					{
						dp[l][r][i][0]+=dp[l+1][r-1][j][k];
						dp[l][r][i][0]%=MOD;
					}
					if(i!=k)
					{
						dp[l][r][0][i]+=dp[l+1][r-1][j][k];
						dp[l][r][0][i]%=MOD;
					}
				}
			}
		}
		return;
	}
	for(int i=l;i<=r;++i)
	{
		dfs(i,x[i]);
		i=x[i];
	}
	for(int i=x[l]+1;i<=r;++i)
	{
		int last=i-1;
		i=x[i];
		for(int j=0;j<=2;++j)
		{
			for(int k=0;k<=2;++k)
			{
				for(int j1=0;j1<=2;++j1)
				{
					for(int k1=0;k1<=2;++k1)
					{
						if(j1!=k1||j1==0)
						{
							dp[l][i][j][k]+=dp[l][last][j][j1]*dp[x[i]][i][k1][k];
							dp[l][i][j][k]%=MOD;
						}
					}
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
		cin>>s;
		s=' '+s;
		for(int i=1;i<s.length();++i)
		{
			if(s[i]=='(')
			{
				sta.push(i);
			}
			else
			{
				x[i]=sta.top();
				x[sta.top()]=i;
				sta.pop();
			}
		}
		for(int i=1;i<s.length();++i)
		{
			for(int j=i+1;j<=s.length();++j)
			{
				for(int k=0;k<=2;++k)
				{
					for(int l=0;l<=2;++l)
					{
						dp[i][j][k][l]=0;
					}
				}
			}
		}
		dfs(1,s.length()-1);
		ans=0;
		for(int i=0;i<=2;++i)
		{
			for(int j=0;j<=2;++j)
			{
				ans+=dp[1][s.length()-1][i][j];
				ans%=MOD;
			}
		}
		cout<<ans<<endl;
	return 0;
}