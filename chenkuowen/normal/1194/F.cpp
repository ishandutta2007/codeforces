#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
vector<int> fac,inv,fac_inv,pw;
inline void init(int n){
	fac.resize(n+5); inv.resize(n+5); fac_inv.resize(n+5);
	fac[0]=inv[1]=fac_inv[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1ll*fac[i-1]*i%MOD;
		if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac_inv[i]=1ll*fac_inv[i-1]*inv[i]%MOD;
	}
}
inline int c(int m,int n){
	if(m>n) return 0;
	return 1ll*fac[n]*fac_inv[m]%MOD*fac_inv[n-m]%MOD;
}
vector<ll> s,a;
int main(){
	int n; scanf("%d",&n); init(n);
	pw.resize(n+5); pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=1ll*(MOD+1>>1)*pw[i-1]%MOD;
	ll T; scanf("%lld",&T);
	s.resize(n); a.resize(n);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
		s[i]=(i>0?s[i-1]:0)+a[i];
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		int pos=upper_bound(s.begin(),s.end(),T-i)-s.begin();
		if(i<n&&pos>0&&T-i-s[pos-1]==0){
//			printf("(%d %d)",i,pos); 
			ans=(ans+1ll*c(i,pos-1)*(pos-1)%MOD*pw[pos])%MOD;
		}
		ans=(ans+1ll*c(i,pos)*pos%MOD*pw[pos])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}