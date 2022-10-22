#include<cstdio>
#include<algorithm>
using namespace std;
const int o=3e5+10,MOD=998244353;
int d,n,m,L[o],p[o],q,f[1<<16],g[1<<16],inv[o],ans;
int main(){
	scanf("%d%d%d",&d,&n,&m);inv[1]=1;
	for(int i=2;i<=d;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=1;i<=n;++i) scanf("%d",&L[i]);
	for(int i=0;i<m;++i) scanf("%d",&p[i]);
	sort(L+1,L+n+1);sort(p,p+m);
	for(int i=0;i<(1<<m);++i) f[i]=1;
	for(int i=1;i<=n;++i) for(int j=0,l,r,md,S;j<m;++j)
		if(p[j]<L[i]){
			for(l=0,r=m;l<r;) if(p[md=l+r>>1]-L[i]>L[i]-p[j]) r=md;else l=md+1;
			S=((1<<(j+1))-1)|(((1<<(m-l))-1)<<l);
			f[S]=f[S]*1ll*(L[i]-p[j])%MOD;f[S^(1<<j)]=f[S^(1<<j)]*1ll*inv[L[i]-p[j]]%MOD;
		}
		else{
			for(l=-1,r=m-1;l<r;) if(L[i]-p[md=(l+r>>1)+1]>=p[j]-L[i]) l=md;else r=md-1;
			S=((1<<(l+1))-1)|(((1<<(m-j))-1)<<j);
			f[S]=f[S]*1ll*(p[j]-L[i])%MOD;f[S^(1<<j)]=f[S^(1<<j)]*1ll*inv[p[j]-L[i]]%MOD;
		}
	for(int md=1;md<(1<<m);md<<=1) for(int i=0;i<(1<<m);i+=md<<1)
		for(int j=0;j<md;++j) f[i+j]=f[i+j]*1ll*f[i+j+md]%MOD;
	for(int i=1;i<=n;++i) f[0]=f[0]*(d+1ll)%MOD;
	for(int i=0;i<(1<<m);++i) g[i]=f[i]*1ll*((__builtin_popcount(i)&1)?MOD-1:1)%MOD;
	for(int md=1;md<(1<<m);md<<=1) for(int i=0;i<(1<<m);i+=md<<1)
		for(int j=0;j<md;++j) g[i+j+md]=(g[i+j]+g[i+j+md])%MOD;
	scanf("%d",&q);
	for(int P;q--;printf("%d\n",ans)){
		scanf("%d",&P);ans=(g[(1<<m)-1]+f[0]*1ll*d)%MOD;
		for(int i=0,l,r,md,S;i<m;++i)
			if(p[i]<P){
				for(l=0,r=m;l<r;) if(p[md=l+r>>1]-P>P-p[i]) r=md;else l=md+1;
				S=((1<<(i+1))-1)|(((1<<(m-l))-1)<<l);ans=(ans+(g[S]+MOD-g[S^(1<<i)])*(P-p[i]-1ll))%MOD;
			}
			else{
				for(l=-1,r=m-1;l<r;) if(P-p[md=(l+r>>1)+1]>=p[i]-P) l=md;else r=md-1;
				S=((1<<(l+1))-1)|(((1<<(m-i))-1)<<i);ans=(ans+(g[S]+MOD-g[S^(1<<i)])*(p[i]-P-1ll))%MOD;
			}
	}
	return 0;
}