#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,maxn=2000020;
ll f[maxn],n,k,now,ans;
inline ll pw(ll a,ll b) {
	ll res=1;
	for(;b;(a*=a)%=mod,b>>=1)
		if(b&1)
			(res*=a)%=mod;
	return res;
}
int main() {
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++) {
		(ans+=(((now+=(f[i]+=((pw(i,n)-pw(i-1,n))%mod+mod)%mod)%mod)%=mod)^i))%=mod;
		for(int j=i*2;j<=k;j+=i)
			(((f[j]-=f[i])%=mod)+=mod)%=mod;
	}
	printf("%lld\n",ans);
}