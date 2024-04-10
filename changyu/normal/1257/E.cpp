#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
const int N=200003;
int k1,k0,k2,a[N],dp[N][3],ans;
int main(){
	scanf("%d%d%d",&k0,&k1,&k2);
	for(int i=1,j;i<=k0;i++)scanf("%d",&j),a[j]=0;
	for(int i=1,j;i<=k1;i++)scanf("%d",&j),a[j]=1;
	for(int i=1,j;i<=k2;i++)scanf("%d",&j),a[j]=2;
	ans=N;
	for(int i=1;i<=k0+k1+k2;i++)
	  for(int j=0;j<3;j++){
	  	dp[i][j]=N;
		for(int k=0;k<=j;k++){
		  dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]!=j));
		}
		if(i==k0+k1+k2)ans=min(ans,dp[i][j]);
	  }printf("%d",ans);
	return 0;
}