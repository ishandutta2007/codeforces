#include<bits/stdc++.h>
const int N=103,M=10003;
int dp[N][M],n,a[N],b[N],ans[N],s,t;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",b+i,a+i);
	for(int j=0;j<N;j++)for(int k=0;k<M;k++)dp[j][k]=-0x3f3f3f3f;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
	  t+=a[i],s+=b[i];
	  for(int j=i;j;j--)
		for(int k=s;k>=b[i];k--)
		  dp[j][k]=std::max(dp[j][k],dp[j-1][k-b[i]]+a[i]);
	}
	for(int j=1;j<=n;j++)
	  for(int k=0;k<=s;k++)
		ans[j]=std::max(ans[j],std::min(k*2,dp[j][k]+t));//,printf("%d %d %d\n",j,k,dp[j][k]);
	for(int i=1;i<=n;i++)printf("%.5lf ",ans[i]/2.0);puts("");
	return 0;
}