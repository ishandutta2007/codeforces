#include<cstdio>
using namespace std;
const int o=1e5+10,MOD=998244353;
int T,n,fac[o],inv[o],a,b;char s[o];
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",C(a,b))){
		scanf("%d%s",&n,s+1);inv[1]=1;
		for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
		a=n;b=0;
		for(int i=1,j;i<=n;++i) if(s[i]>48){
			for(j=i;j<n&&s[j+1]>48;++j);
			a-=(j-i+2)/2;b+=(j-i+1)/2;i=j;
		}
	}
	return 0;
}