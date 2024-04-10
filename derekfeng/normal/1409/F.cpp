#include<bits/stdc++.h>
using namespace std;
int dp[203][203][203];
string s,t;
int n,K;
void MAX(int &A,int B){
	A=max(A,B);
}
int main(){
	cin>>n>>K>>s>>t;s=")"+s;
	for(int i=0;i<203;i++)for(int j=0;j<203;j++)for(int k=0;k<203;k++)dp[i][j][k]=-1;
	dp[0][0][0]=0;
	for(int i=0;i<s.size();i++)for(int j=0;j<=K;j++){
		for(int k=0;k<203;k++)if(dp[i][j][k]>=0){
			MAX(dp[i+1][j][k+(s[i+1]==t[0])],dp[i][j][k]+(s[i+1]==t[1]?k:0));
			MAX(dp[i+1][j+1][k+1],dp[i][j][k]+(t[0]==t[1]?k:0));
			MAX(dp[i+1][j+1][k+(t[1]==t[0])],dp[i][j][k]+k);
		}
	}
	int ans=0;
	for(int i=0;i<=K;i++)for(int j=0;j<203;j++)ans=max(ans,dp[n][i][j]);
	cout<<ans;
}