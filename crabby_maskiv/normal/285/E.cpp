#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
int n,m;
int dp[N][N][2][2],C[N][N];
int main(){
	int i,j;
	cin>>n>>m;
	dp[0][0][0][0]=1;
	for(i=0;i<=n;i++){
		for(j=0;j<=i;j++){
			if(!j||j==i) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			if(j){
				if(i>1){
					dp[i][j][0][0]=(dp[i-1][j-1][0][0]+dp[i][j][0][0])%mod;
					dp[i][j][1][0]=(dp[i-1][j-1][0][1]+dp[i][j][1][0])%mod;
				}
				if(i<n){
					dp[i][j][0][1]=(dp[i][j][0][1]+dp[i-1][j-1][0][0])%mod;
					dp[i][j][0][1]=(dp[i][j][0][1]+dp[i-1][j-1][1][0])%mod;
					dp[i][j][1][1]=(dp[i][j][1][1]+dp[i-1][j-1][0][1])%mod;
					dp[i][j][1][1]=(dp[i][j][1][1]+dp[i-1][j-1][1][1])%mod;
				}
			}
			dp[i][j][0][0]=(dp[i-1][j][0][0]+dp[i][j][0][0])%mod;
			dp[i][j][0][0]=(dp[i-1][j][1][0]+dp[i][j][0][0])%mod;
			dp[i][j][1][0]=(dp[i-1][j][0][1]+dp[i][j][1][0])%mod;
			dp[i][j][1][0]=(dp[i-1][j][1][1]+dp[i][j][1][0])%mod;
		}
	}
	int ans=0;
	for(i=m;i<=n;i++){
		int w=(dp[n][i][0][0]+dp[n][i][1][0])%mod;
		for(j=n;j>i;j--) w=1ll*w*(n-j+1)%mod;
		if((i-m)&1) ans=(ans-1ll*C[i][m]*w%mod+mod)%mod;
		else ans=(ans+1ll*C[i][m]*w)%mod;
	}
	cout<<ans;
	return 0;
}