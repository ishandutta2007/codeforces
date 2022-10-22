#include<bits/stdc++.h>
using namespace std;
const int mod=1000000009;
const int N=1000,M=30;
int n,m;
int dp[N+1][2][M+1][M+1][M+1];
int &get(int a,bool b,int c,int d,int e){
	if(c>d)swap(c,d);if(c>e)swap(c,e);if(d>e)swap(d,e);
	return dp[a][b][c][d][e];
}
int main(){
	scanf("%d%d",&n,&m);
	dp[0][true][0][0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=1;j++)
		for(int k=0;k<=m;k++)for(int o=k;o<=m;o++)for(int p=o;p<=m;p++)
			(get(i+1,j,min(k+1,m),min(o+1,m),min(p+1,m))+=dp[i][j][k][o][p])%=mod,
			(get(i+1,k<m,j?1:m,min(o+1,m),min(p+1,m))+=dp[i][j][k][o][p])%=mod,
			(get(i+1,o<m,min(k+1,m),j?1:m,min(p+1,m))+=dp[i][j][k][o][p])%=mod,
			(get(i+1,p<m,min(k+1,m),min(o+1,m),j?1:m)+=dp[i][j][k][o][p])%=mod;
	int ans=0;
	for(int j=0;j<=1;j++)for(int k=0;k<=m;k++)for(int o=k;o<=m;o++)for(int p=o;p<=m;p++)
		if(j||k<m)(ans+=dp[n][j][k][o][p])%=mod;
	printf("%d",ans);
	return 0;
}
/*1
5 1
*/
/*2
4 2
*/
/*3
4 3
*/
/*4
5 2
*/