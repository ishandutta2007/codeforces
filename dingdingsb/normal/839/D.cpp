#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5,mod=1e9+7;
int n,cnt[maxn],dp[maxn],ans=0;
int quick_pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod,b>>=1;
	}
	return ans;
}
int ttt=0;
signed main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),cnt[x]++,ttt=max(ttt,x);
	for(int i=maxn-1;i>1;i--){
		int cur=0;
		for(int j=i;j<maxn;j+=i)
			cur+=cnt[j];
		if(cur==0)
			continue;
		dp[i]=cur*quick_pow(2,cur-1)%mod;
		for(int j=i*2;j<maxn;j+=i)
			dp[i]=(((dp[i]-dp[j])%mod)+mod)%mod;
		(ans+=dp[i]*i)%=mod;
	}
	cout<<ans;
}