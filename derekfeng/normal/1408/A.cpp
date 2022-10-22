#include<bits/stdc++.h>
using namespace std;
int a[3][103],T,n;
bool dp[103][3];
void dfs(int x,int y){
	if(x>1){
		for(int i=0;i<3;i++)if(dp[x-1][i]&&a[i][x-1]!=a[y][x]){
			dfs(x-1,i);
			break;
		}
	}
	printf("%d ",a[y][x]);
}
void solve(){
	for(int ii=0;ii<3;ii++){
		memset(dp,0,sizeof(dp));
		dp[1][ii]=1;
		for(int i=2;i<=n;i++)for(int j=0;j<3;j++)if(dp[i-1][j])
			for(int k=0;k<3;k++)if(a[j][i-1]!=a[k][i])dp[i][k]=1;
		for(int i=0;i<3;i++)if(dp[n][i]&&a[ii][1]!=a[i][n]){
			dfs(n,i);puts("");
			return;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int j=0;j<3;j++)for(int i=1;i<=n;i++)scanf("%d",&a[j][i]);
		solve();
	}
}