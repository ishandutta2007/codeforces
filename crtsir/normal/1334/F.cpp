#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500003],b[500003],p[500003],cost[500003],dp[500003];
int main(){
	scanf("%lld",&n);memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)scanf("%lld",p+i);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)scanf("%lld",b+i);
	b[m+1]=23333333333333333;
	for(int i=1;i<=n;i++){
		int x=lower_bound(b+1,b+m+2,a[i])-b;
		if(x==m+1||p[i]<0)cost[x]+=p[i];
	}dp[0]=0;
	for(int i=1;i<=n;i++){
		int x=lower_bound(b+1,b+m+2,a[i])-b;
		if(x<=m){
			if(b[x]==a[i])
				dp[x]=min(dp[x],dp[x-1]+cost[x]-min(p[i],0ll));
			if(p[i]>0)cost[x]+=p[i];
		}
	}
	if(dp[m]>1e14)
		cout<<"NO";
	else
		cout<<"YES\n"<<dp[m]+cost[m+1];
}