#include<cstdio>
using namespace std;
const int o=1e6+10,MOD=1e9+7;
int T,n,m,k,fac[o],inv[o],pw[o],ans;
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d%d",&n,&m,&k);
		inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=fac[0]=inv[0]=pw[0]=1;i<=n;++i)
			fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD,pw[i]=pw[i-1]*(MOD+1ll)/2%MOD;
		if(n==m){ans=k*1ll*m%MOD;continue;}
		for(int i=1;i<=m;++i) ans=(ans+C(n-i-1,m-i)*1ll*pw[n-i]%MOD*i%MOD*k)%MOD;
	}
	return 0;
}