#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=6e6+50,MOD=1e9+7,iv=(MOD+1)/3;
int n,q,fac[o],inv[o],f[o];
inline int C(int x,int y){return fac[x]*1ll*inv[x-y]%MOD*inv[y]%MOD;}
int main(){
	read(n);read(q);n=3*n+3;
	inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	for(int i=0;i<n;++i) f[i]=C(n,i+1);
	f[0]=f[0]*1ll*iv%MOD;
	f[1]=(f[1]-f[0]*3ll%MOD+MOD)*1ll*iv%MOD;
	for(int i=2;i<n;++i) f[i]=(f[i]-f[i-2]-f[i-1]*3ll%MOD+2ll*MOD)*iv%MOD;
	for(int i;q--;) read(i),printf("%d\n",f[i]);
	return 0;
}