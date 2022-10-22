#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,m;
char c[21][21];
int dp[11000000],a[22][22];
int cost[21][26],msk[21][26],maxn[21][26];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		for(int j=0;j<m;j++)c[i][j]-='a';
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)cost[i][c[j][i]]+=a[j][i],maxn[i][c[j][i]]=max(maxn[i][c[j][i]],a[j][i]),msk[i][c[j][i]]|=(1<<j);
		for(int j=0;j<26;j++)cost[i][j]-=maxn[i][j]; 
	}
	for(int i=0;i<(1<<n);i++)dp[i]=6e8;
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)if(((1<<j)&i)==0)
			for(int k=0;k<m;k++){
				dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+a[j][k]);
				int go=msk[k][c[j][k]],cos=cost[k][c[j][k]];
				dp[i|go]=min(dp[i|go],dp[i]+cos);
			}
	cout<<dp[(1<<n)-1];
}