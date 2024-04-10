#include<bits/stdc++.h>
using namespace std;
int dp[2][200003];
bool x;
int main(){
	int r,g;
	cin>>r>>g;
	int n=0;
	for(;n*n+n<=2*(r+g);n++);
	dp[0][1]=1;
	n--;
	dp[0][0]=1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<=r;j++)dp[x^1][j]=0;
		x^=1;
		for(int j=0;j<=r;j++)
		{
			if((i+3)*(i+2)/2-j<=g&&(i+3)*(i+2)/2-j>=0)dp[x][j]=(dp[x][j]+dp[x^1][j])%1000000007;
			if(j+i+2<=r&&(i+3)*(i+2)/2-j-i-2>=0)dp[x][j+i+2]=(dp[x][j+i+2]+dp[x^1][j])%1000000007;
		}
	}
	long long ans=0;
	for(int i=max(0,n*(n+1)/2-g);i<=r;i++)ans=(ans+dp[x][i])%1000000007;
	cout<<ans;
}