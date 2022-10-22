#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
int n,m;
ll po(ll x,ll k){
	if(k<0) return 0;
	ll ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
ll fac[N],inv[N];
ll C(int x,int k){
	if(x<k) return 0;
	return fac[x]*inv[k]%mod*inv[x-k]%mod;
}
int main(){
	int i,j;
	cin>>n>>m;
	fac[0]=1;
	for(i=1;i<=m;i++) fac[i]=fac[i-1]*i%mod;
	inv[m]=po(fac[m],mod-2);
	for(i=m-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	ll ans=0;
	for(i=1;i<=m;i++)
		ans=(ans+(C(m-1,n-2)-C(i-1,n-2)+mod)*po(2,n-3)%mod)%mod;
	cout<<ans;
	return 0;
}