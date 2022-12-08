#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=30;
ll inv[maxn],sgn;
ll n,m,a[maxn],ans;
inline ll lowbit(ll x){return x&(-x);}
inline ll C(ll n,ll m){
	ll res=1;
	for (int i=n;i>=n-m+1;--i) res=res*i%mod;
	for (int i=1;i<=m;++i) res=res*inv[i]%mod;
	return res;
}
int main(){
	scanf("%lld%lld",&n,&m); m+=n;
	for (ll i=1;i<=n;++i) scanf("%lld",&a[i]),++a[i];
	inv[1]=1;
	for (ll i=2;i<maxn;++i) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for (ll i=0;i<(1<<n);++i){
		ll cur=i,len=0,sum=0;
		while (cur){cur-=lowbit(cur); ++len;}
		if (len%2==0) sgn=1; else sgn=mod-1;
		for (ll j=1;j<=n;++j)
		if (i&(1<<(j-1))) sum+=a[j];
		if (sum>=m) continue;
		ans=(ans+sgn*C((m-sum-1)%mod,n-1))%mod;
	}
	printf("%lld",ans);
	return 0;
}