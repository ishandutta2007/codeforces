#include<cstdio>
using namespace std;
const int o=2e5+10,MOD=998244353;
int n,m,s[o],t[o],a[o],b[o],fac[o],inv[o],ans,coef;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<o;pos+=lowbit(pos)) b[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
int main(){
	scanf("%d%d",&n,&m);
	inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i)
		fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD,scanf("%d",&s[i]),++a[s[i]],modify(s[i],1);
	for(int i=coef=1;i<o;++i) coef=coef*1ll*inv[a[i]]%MOD;
	for(int i=1;i<=m;++i){
		scanf("%d",&t[i]);
		if(i>n) ans=(ans+1)%MOD;
		ans=(ans+fac[n-i]*1ll*coef%MOD*query(t[i]-1))%MOD;
		coef=coef*1ll*fac[a[t[i]]]%MOD;
		if(!a[t[i]]--) break;
		coef=coef*1ll*inv[a[t[i]]]%MOD;modify(t[i],-1);
	}
	printf("%d",ans);
	return 0;
}