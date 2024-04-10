#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,l[2004],r[2004],a[2004],dp[2004];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&l[i],&r[i],&a[i]);
	for(int i=n;i;i--){
		ll w=a[i];
		if(i<n&&r[i]==l[i+1])w+=dp[i+1];
		if((ll)(r[i]-l[i]+1)*k<w)return puts("-1"),0;
		ll v=(ll)(r[i]-l[i])*k;
		if(v>=w)dp[i]=0;else dp[i]=w-v;
	}
	ll ans=0,now=k;
	for(int i=1;i<=n;i++){
		if(now<dp[i])ans+=now,now=k;
		ans+=a[i],now=((now-a[i]%k+k)%k);
	}printf("%lld",ans);
}