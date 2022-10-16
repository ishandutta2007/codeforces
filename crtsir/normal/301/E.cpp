#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dp[2][103][103][103],n,m,q,C[103][103],ans;
int main(){
	for(int i=0;i<103;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=min(101,C[i-1][j]+C[i-1][j-1]);
	}
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		dp[1][i][1][i]=1;
	for(int i=2;i<=m;i++){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j=1;j<=n;j++)
			for(int k=1;k<=q;k++)
				for(int l=1;l<=j;l++)
					if(dp[i-1&1][j][k][l]){
						for(int o=l;j+o<=n&&k*C[o-1][l-1]<=q;o++){
							dp[i&1][j+o][k*C[o-1][l-1]][o-l]+=dp[i-1&1][j][k][l];
							if(dp[i&1][j+o][k*C[o-1][l-1]][o-l]>=mod)
								dp[i&1][j+o][k*C[o-1][l-1]][o-l]-=mod;
						}
					}
		for(int j=1;j<=n;j++)
			for(int k=1;k<=q;k++)
				ans=(ans+dp[i&1][j][k][0]*(m-i+1ll))%mod;
	}cout<<ans;
}