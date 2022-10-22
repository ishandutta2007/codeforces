#include<bits/stdc++.h>
const int N=503;
char a[N];
int n,dp[N][N];
int main(){
	scanf("%d%s",&n,a+1);
	for(int i=0;i<=n;i++)dp[i+1][i]=-1;
	for(int k=1;k<n;k++)
		for(int i=1;i+k<=n;i++){
			dp[i][i+k]=k;
			for(int j=i;j<i+k;j++)dp[i][i+k]=std::min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+1);
			if(a[i]==a[i+k]){
				dp[i][i+k]=std::min(dp[i][i+k],dp[i+1][i+k-1]+1);
				for(int j=i+1;j<i+k;j++)
					if(a[i]==a[j])
						dp[i][i+k]=std::min(dp[i][i+k],dp[i][j]+dp[j][i+k]);
			}
		}
	printf("%d\n",dp[1][n]+1);
	return 0;
}