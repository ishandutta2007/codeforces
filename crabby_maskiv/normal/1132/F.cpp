#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int dp[N][N][5];//1 10 2 01 3 101
char a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n;
	cin>>(a+1);
	memset(dp,0x3f,sizeof(dp));
	for(i=1;i<=n;i++) dp[i][i][1]=dp[i][i][2]=1;
	for(i=2;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			int r=j+i-1;
			for(k=j;k<r;k++){
				dp[j][r][1]=min(dp[j][r][1],min(dp[j][k][1],dp[j][k][3])
				+min(min(dp[k+1][r][1],dp[k+1][r][2]),dp[k+1][r][3]));
				dp[j][r][2]=min(dp[j][r][1],min(min(dp[j][k][1],dp[j][k][2]),dp[j][k][3])
				+min(dp[k+1][r][2],dp[k+1][r][3]));
				if(i>=2&&a[j]==a[r]){
					dp[j][r][3]=min(dp[j][r][3],min(dp[j][k][1],dp[j][k][3])+min(dp[k+1][r][2],dp[k+1][r][3])-1);
				}
			}
		}
	}
	cout<<min(min(dp[1][n][1],dp[1][n][2]),dp[1][n][3]);
	return 0;
}