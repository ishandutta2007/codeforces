#include<bits/stdc++.h>
using namespace std;
const long long mod=51123987;
int dp[153][53][53][53],nxt[3][153],n,ans;
string s;
int main(){
	cin>>n>>s;
	s='%'+s;
	for(int i=n;i>=1;i--)nxt[0][i]=nxt[0][i+1],nxt[1][i]=nxt[1][i+1],nxt[2][i]=nxt[2][i+1],nxt[s[i]-'a'][i]=i;
	dp[1][0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=(n+2)/3;j++)
			for(int k=0;k<=(n+2)/3;k++)
				for(int o=0;o<=(n+2)/3;o++){
					if(j+k+o==n&&fabs(j-k)<2&&fabs(k-o)<2&&fabs(o-j)<2)ans=(ans+dp[i][j][k][o])%mod;
					dp[nxt[0][i]][j+1][k][o]=(dp[nxt[0][i]][j+1][k][o]+dp[i][j][k][o])%mod;
					dp[nxt[1][i]][j][k+1][o]=(dp[nxt[1][i]][j][k+1][o]+dp[i][j][k][o])%mod;
					dp[nxt[2][i]][j][k][o+1]=(dp[nxt[2][i]][j][k][o+1]+dp[i][j][k][o])%mod;
				}
	cout<<ans;
}