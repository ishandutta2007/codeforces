#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
map<int,int>M;
int x[222222],y[222222],s[222222],n,dp[222222],pre[222222],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&x[i],&y[i],&s[i]),M[x[i]]=i,dp[i]=((x[i]-y[i]+pre[i-1]-pre[lower_bound(x+1,x+1+i,y[i])-x-1])%mod+mod)%mod,
		ans=(ans+s[i]*dp[i])%mod,pre[i]=(pre[i-1]+dp[i])%mod;
	printf("%d",(ans+x[n]+1)%mod);
}