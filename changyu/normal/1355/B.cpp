#include<cstdio>
#include<algorithm>
const int N=2e5+3;
int n,a[N],dp[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	  if(i>=a[i])dp[i]=std::max(dp[i-a[i]]+1,dp[i-1]);
	  else dp[i]=dp[i-1];
	printf("%d\n",dp[n]);
	}return 0;
}