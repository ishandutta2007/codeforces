#include<bits/stdc++.h>
using namespace std;
int n,K,m,f[200005],a[200005];
int dp[2003];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(m--){
		int x,y;scanf("%d%d",&x,&y);
		f[x]=max(f[x],y);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=K;i++)f[i]=i-f[i];
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=K;i++)
		for(int j=1;j<=i;j++)
			dp[i]=min(dp[i],dp[i-j]+a[i]-a[i-f[j]]);
	printf("%d",dp[K]);
}