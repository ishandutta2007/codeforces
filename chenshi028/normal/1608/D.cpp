#include<cstdio>
using namespace std;
const int o=1e5+10,MOD=998244353;
int n,a,b,c,d,fac[o],inv[o],ans,e,f,g;char s[2];
inline int C(int x,int y){if(y<0||x<y) return false;return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	scanf("%d",&n);
	inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i]*1ll*inv[i-1]%MOD;
	for(int i=1;i<=n;++i)
		scanf("%s",s),a+=(s[0]=='?'),b+=(s[0]=='W'),c+=(s[1]=='?'),d+=(s[1]=='B'),
		e+=(s[0]=='B'&&s[1]!='B'||s[1]=='W'&&s[0]!='W'),f+=(s[0]=='W'&&s[1]!='W'||s[1]=='B'&&s[0]!='B'),g+=(s[0]=='?'&&s[1]=='?');
	for(int i=0;i<=n;++i) ans=(ans+C(a,i-b)*1ll*C(c,i-d))%MOD;
	if(e+f+g==n) for(int i=1;i<n;++i) ans=(ans+MOD-C(g,i-e))%MOD;
	printf("%d",ans);
	return 0;
}