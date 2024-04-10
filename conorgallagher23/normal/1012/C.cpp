#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+5;
int n,a[N],dp[N][N][2][2],ans[N];
void rel(int &x,int y){x=x<y?x:y;}
int need(int x,int y){return x>y?0:y-x+1;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1){puts("0");return 0;}
	memset(dp,0x3f,sizeof(dp));dp[1][1][1][0]=dp[1][0][0][0]=0;
	for(int i=1;i<n;i++)for(int j=0;j<=i;j++)for(int k=0;k<2;k++){
		int t;if(!k)t=a[i];else t=min(a[i-1]-1,a[i]);
		if(dp[i][j][0][k]!=dp[0][0][0][0]){
			rel(dp[i+1][j][0][0],dp[i][j][0][k]);
			rel(dp[i+1][j+1][1][0],dp[i][j][0][k]+need(a[i+1],t));
		}
		if(dp[i][j][1][k]!=dp[0][0][0][0])rel(dp[i+1][j][0][1],dp[i][j][1][k]+need(t,a[i+1]));
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=((n+1)>>1);i;i--){
		rel(ans[i],ans[i+1]);
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)rel(ans[i],dp[n][i][j][k]);
	}
	for(int i=1;i<=((n+1)>>1);i++)printf("%d%c",ans[i]," \n"[i==((n+1)>>1)]);
	return 0;
}