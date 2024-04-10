#include<cstdio>
using namespace std;
const int o=1e5+10,MOD=1e9+7;
int n,k,fac[o],inv[o],ans;
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	scanf("%d%d",&n,&k);inv[1]=1;
	for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	for(int i=0;i<=n&&i<=k;++i) ans=(ans+C(n,i))%MOD;
	printf("%d",ans);
	return 0;
}