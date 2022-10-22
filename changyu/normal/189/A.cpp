#include<cstdio>
#define max(a,b)a>b?a:b
int n,a[4],dp[4001];
int main(){
	scanf("%d%d%d%d",&n,a,a+1,a+2);
	dp[a[0]]=dp[a[1]]=dp[a[2]]=1;
	for(int i=1;i<=n;i++){
	  for(int j=0;j<3;j++)
		if(a[j]<i&&dp[i-a[j]]&&dp[i-a[j]]>=dp[i])
		  dp[i]=dp[i-a[j]]+1;
	}
	printf("%d",dp[n]);
	return 0;
}