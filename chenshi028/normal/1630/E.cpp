#include<cstdio>
using namespace std;
const int o=1e6+10,MOD=998244353;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,n,fac[o],inv[o],sum,cnt,g,st[o],tp,a[o],s[o],c[o];
int main(){
	for(scanf("%d",&T);T--;g=cnt=sum=tp=0){
		scanf("%d",&n);inv[1]=1;
		for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
		for(int i=1;i<=n;++i) a[i]=0;
		for(int i=n,j;i--;++a[j]) scanf("%d",&j);
		for(int i=1;i<=n;g=gcd(g,a[i++])) if(a[i]) st[++tp]=a[i];
		if(tp==1){printf("1\n");continue;}
		for(int i=1;i<=g;++i) if(g%i==0){
			s[i]=0;c[i]=fac[n/i];
			for(int j=1,p=0;j<=tp;++j) c[i]=c[i]*1ll*inv[st[j]/i]%MOD,s[i]=(s[i]+p*2ll*st[j]/i)%MOD,p+=st[j]/i;
			s[i]=s[i]*1ll*qp(n/i,MOD-2)%MOD*qp(n/i-1,MOD-2)%MOD*c[i]%MOD*n%MOD;
		}
		for(int i=0,j;i<n;++i) if(g%(j=n/gcd(n,i))==0) sum=(sum+s[j])%MOD,cnt=(cnt+c[j])%MOD;
		printf("%lld\n",sum*1ll*qp(cnt,MOD-2)%MOD);
	}
	return 0;
}