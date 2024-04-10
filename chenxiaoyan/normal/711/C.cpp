/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100,M=100;
int n,m,s;
int a[N+1];
int cst[N+1][M+1];
int Mn[M+1],mN[M+2];
int dp[N+1][N+1][M+1];
signed main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>cst[i][j];
	memset(dp,0x3f,sizeof(dp));
	if(a[1])dp[1][1][a[1]]=0;
	else for(int k=1;k<=m;k++)dp[1][1][k]=cst[1][k];
	Mn[0]=mN[m+1]=inf;
	for(int i=2;i<=n;i++)for(int j=1;j<=s;j++)
		if(a[i])for(int k=1;k<=m;k++)dp[i][j][a[i]]=min(dp[i][j][a[i]],dp[i-1][j-(a[i]!=k)][k]);
		else{
			for(int k=1;k<=m;k++)Mn[k]=min(Mn[k-1],dp[i-1][j-1][k]);
			for(int k=m;k;k--)mN[k]=min(mN[k+1],dp[i-1][j-1][k]);
			for(int k=1;k<=m;k++)
				dp[i][j][k]=min(dp[i-1][j][k],min(Mn[k-1],mN[k+1]))+cst[i][k];
		}
	int ans=*min_element(dp[n][s]+1,dp[n][s]+m+1);
	if(ans<inf)cout<<ans;
	else puts("-1");
	return 0;
}
/*1
3 2 2
0 0 0
1 2
3 4
5 6
*/
/*2
3 2 2
2 1 2
1 3
2 4
3 5
*/
/*3
3 2 2
2 0 0
1 3
2 4
3 5
*/
/*4
3 2 3
2 1 2
1 3
2 4
3 5
*/