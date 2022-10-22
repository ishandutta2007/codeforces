#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n,K,ans;
ll cur;
int cnt1[1000004],cnt2[1000004];
int inv[1000004];
ll mypow(ll x,ll t){
	ll ans=1,ret=x;
	while(t){
		if(t&1)ans=ans*ret%MOD;
		ret=ret*ret%MOD,t>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	cnt1[0]=1,cnt2[K+3]=1,inv[1]=1;
	for(int i=1;i<=K+2;i++)cnt1[i]=1ll*cnt1[i-1]*(n-i)%MOD;
	for(int i=K+2;i;i--)cnt2[i]=1ll*cnt2[i+1]*(n-i)%MOD;
	for(int i=2;i<=K+2;i++)inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[0]=1;
	for(int i=2;i<=K+2;i++)inv[i]=1ll*inv[i-1]*inv[i]%MOD;
	for(int i=1;i<=K+2;i++){
		cur=(cur+mypow(i,K))%MOD;
		ll tmp1=1ll*cnt1[i-1]*cnt2[i+1]%MOD;
		ll tmp2=1ll*inv[i-1]*inv[K+2-i]%MOD;
		ll tmp=cur*tmp1%MOD*tmp2%MOD;
		if((K+2-i)%2==1)tmp=MOD-tmp; 
		ans=(ans+tmp)%MOD;
	}
	printf("%d",ans);
}