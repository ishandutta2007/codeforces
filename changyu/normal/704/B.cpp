#include<bits/stdc++.h>
typedef long long ll;
const int N=5003;
int n,S,T,x[N],a[N],b[N],c[N],d[N];ll dp[N][N];
int main(){
	scanf("%d%d%d",&n,&S,&T);
	for(int i=1;i<=n;i++)scanf("%d",x+i);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++)scanf("%d",d+i);
	for(int i=0;i<=n;i++)for(int j=0;j<=i+1;j++)dp[i][j]=1e15;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=i;j++){
		if(i<n&&!j)continue;
		if(!(j==1&&T<i&&S>i)&&!((i==S||i==T)&&S<T))dp[i][j]=std::min(dp[i][j],dp[i-1][j]+a[i]+d[i]);
		if(!(j==1&&T>i&&S<i)&&!((i==S||i==T)&&S>T))dp[i][j]=std::min(dp[i][j],dp[i-1][j]+b[i]+c[i]);
		if(j>0&&i!=std::max(S,T))dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]+d[i]+b[i]-2*x[i]);
		if(j<i&&i!=std::min(S,T))dp[i][j]=std::min(dp[i][j],dp[i-1][j+1]+a[i]+c[i]+2*x[i]);
	  }
	printf("%lld\n",dp[n][0]-(T<S?(ll)x[S]-x[T]+d[T]+a[S]:(ll)x[T]-x[S]+c[T]+b[S]));
	return 0;
}