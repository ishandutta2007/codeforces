#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
const int N=2005;
ll dp[N][N],ans,n,m;
int b,minb;
string s;
 
int main()
{
	cin>>n>>m>>s;
	dp[0][0]=1;
	for(int i=1;i<=n-m;i++)
	{
		dp[i][0]=dp[i-1][1];
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1];
			dp[i][j]%=mod;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(s[i]=='(') b++;
		else b--;
		minb=min(b,minb);
	}
	for(int c=0;c<=n-m;c++)
	{
		for(int d=0;d<=c;d++)
		{
			if(d>=-minb)
			{
				if(d+b<=n-m && d+b>=0)
				{
					ans+=dp[c][d]*dp[n-m-c][d+b]%mod;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}