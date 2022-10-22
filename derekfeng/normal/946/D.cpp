#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[503][503];
int num[503][503],cnt[503][503],qt[503][503];
char c[503][503];
int main(){
	for (int i=0;i<503;i++)for(int j=0;j<503;j++)dp[i][j]=1e8,qt[i][j]=10000;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>c[i][j];
		num[i][j]=num[i][j-1];
		if (c[i][j]=='1') num[i][j]++;
	}
	for (int i=1;i<=n;i++){ 
		cnt[i][m+1]=0;
		for (int j=m;j>=1;j--){
			cnt[i][j]=cnt[i][j+1];
			if (c[i][j]=='1') cnt[i][j]++;
		}
	}
	for (int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int l=m+1;l>j;l--)
				qt[i][num[i][j]+cnt[i][l]]=min(l-1-j,qt[i][num[i][j]+cnt[i][l]]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			qt[i][j]=min(qt[i][j],qt[i][j-1]);
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			for (int l=0;l<=j;l++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-l]+qt[i][l]);
			}
	cout<<dp[n][k];
}