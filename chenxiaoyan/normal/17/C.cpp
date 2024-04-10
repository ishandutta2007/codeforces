/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int mod=51123987;
const int N=150;
int n,m;
char a[N+5];
int las[N+1][3];
int dp[N+1][N/3+5][N/3+5][N/3+5];
int main(){
	cin>>n>>a+1;
	m=unique(a+1,a+n+1)-1-a;
	int now[3]={};
	for(int i=1;i<=m;i++)now[a[i]-'a']=i,las[i][0]=now[0],las[i][1]=now[1],las[i][2]=now[2];
	for(int i=1;i<=m;i++)dp[i][0][0][0]=1;
	for(int i=1;i<=m;i++)for(int j=0;j<=n/3+2;j++)for(int k=0;k<=n/3+2;k++)for(int o=0;o<=n/3+2&&j+k+o<=n;o++)if(j||k||o){
		if(las[i][0]&&j)(dp[i][j][k][o]+=dp[las[i][0]][j-1][k][o])%=mod;
		if(las[i][1]&&k)(dp[i][j][k][o]+=dp[las[i][1]][j][k-1][o])%=mod;
		if(las[i][2]&&o)(dp[i][j][k][o]+=dp[las[i][2]][j][k][o-1])%=mod;
//		printf("dp[%d][%d][%d][%d]=%d\n",i,j,k,o,dp[i][j][k][o]);
	}
	int ans=0;
	for(int j=0;j<=n/3+2;j++)for(int k=0;k<=n/3+2;k++)
		if(abs(j-k)<=1&&abs(j-(n-j-k))<=1&&abs(k-(n-j-k))<=1)
			(ans+=dp[m][j][k][n-j-k])%=mod;
	cout<<ans;
	return 0;
}
/*1
4
abca
*/
/*2
4
abbc
*/
/*3
2
ab
*/