#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,dp[1005][2005];
string st,ans;
int main()
{
	cin>>n>>m>>st;
	//cerr<<n<<endl;
	st=" "+st;
	dp[0][1002]=-1;
	for (i=1;i<=n;i++)
	{
		for (j=1002-m+(i<n);j<=1002+m-(i<n);j++)
		{
			if (st[i]=='W'||st[i]=='?') if (dp[i-1][j-1]) dp[i][j]=1;
			if (st[i]=='L'||st[i]=='?') if (dp[i-1][j+1]) dp[i][j]=3;
			if (st[i]=='D'||st[i]=='?') if (dp[i-1][j]) dp[i][j]=2;
		}
	}
	//cerr<<n<<endl;
	if (dp[n][1002+m]==0&&dp[n][1002-m]==0)
	{
		cout<<"NO";
		return 0;
	}
	j=dp[n][1002+m]==0?1002-m:1002+m;
	ans="";
	for (i=n;i>=1;i--)
	{
		cerr<<i<<endl;
		if (dp[i][j]==1)
		{
			ans+="W";
			j--;
		}
		else if (dp[i][j]==3)
		{
			ans+="L";
			j++;
		}
		else if (dp[i][j]==2)
		{
			ans+="D";
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}