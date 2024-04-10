#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int dp[5003][5003],n;
char c;
int main(){
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		cin>>c;
		if(c=='f')
			for(int j=1;j<=n;j++)
				dp[i][j]=dp[i-1][j-1]%inf;
		else
		{
			int cnt=0;
			for(int j=n;j>=0;j--)
			{
				cnt+=dp[i-1][j];
				dp[i][j]=cnt%inf;
				cnt%=inf;
			}
		}
	}
	cin>>c;
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+dp[n-1][i])%inf;
	cout<<ans;
	return 0;
}