#include<cstdio>
using namespace std;
const int o=5000,MOD=998244353;
int n,m,fac[o],inv[o],r[o],z[o],ans;
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
inline int slv(int n,int m){
	int res=0;
	for(int i=1;i<n;++i) r[i]=0;
	for(int i=m-1;i;--i) for(int j=1;j<n;++j)
		r[j]=(r[j]+C(m+n-i-j-1,m-i-1)*1ll*C(i+n-j-1,i))%MOD,res=(res+C(i+j-1,i-1)*1ll*C(m-i+j-1,m-i)%MOD*r[j])%MOD;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	inv[1]=1;for(int i=2;i<=n+m;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=inv[0]=fac[0]=1;i<=n+m;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	ans=(slv(n,m)+slv(m,n))%MOD;
	for(int i=1;i<n;++i){
		r[0]=0;z[m]=1;
		for(int j=1;j<m;++j) r[j]=C(n-i+j-2,j-1),z[j]=C(m-j+i-1,m-j);
		for(int j=m-1;j;--j) z[j]=(z[j]+z[j+1])%MOD;
		for(int j=1;j<m;++j) r[j]=(r[j-1]+r[j])%MOD;
		for(int j=1;j<m;++j) ans=(ans-C(i+j-1,j)*1ll*C(n+m-i-j-1,m-j)%MOD*r[j]%MOD*z[j+1])%MOD;
	}
	if(ans<0) ans+=MOD;
	printf("%d",ans*2%MOD);
	return 0;
}