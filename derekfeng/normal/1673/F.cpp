#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int R[33][33],C[33][33];
void built(int l,int r,int d){
	if(r<l)return;
	int md=(l+r)>>1;
	for(int i=1;i<=n;i++)R[i][md]=d,C[md][i]=d>>1;
	built(l,md-1,d>>2),built(md+1,r,d>>2);
}
int dp[33][33];
int main(){
	scanf("%d%d",&n,&k);
	built(1,n-1,512);
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<n;j++)printf("%d ",R[i][j]);
	for(int i=1;i<n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",C[i][j]);
	fflush(stdout);
	for(int i=2;i<=n;i++)dp[i][1]=dp[i-1][1]^C[i-1][1];
	for(int i=1;i<=n;i++)for(int j=2;j<=n;j++)dp[i][j]=dp[i][j-1]^R[i][j-1];
	int lst=0;
	while(k--){
		int x;scanf("%d",&x);lst^=x;fflush(stdout);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			if(dp[i][j]==lst)printf("%d %d\n",i,j);
		fflush(stdout);
	}
}