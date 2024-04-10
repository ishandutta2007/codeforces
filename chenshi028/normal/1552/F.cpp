#include<cstdio>
using namespace std;
const int o=2e5+10,MOD=998244353;
int n,x[o],y[o],s[o],f[o],g[o],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&x[i],&y[i],&s[i]);
	ans=(x[n]+1)%MOD;
	for(int i=1,l,r,md;i<=n;++i){
		f[i]=(x[i]-y[i])%MOD;
		for(l=1,r=i;l<r;) if(x[md=l+r>>1]>=y[i]) r=md;else l=md+1;
		f[i]=(f[i]+(g[i-1]+MOD-g[l-1])%MOD)%MOD;g[i]=(g[i-1]+f[i])%MOD;
	}
	for(int i=1;i<=n;++i) if(s[i]) ans=(ans+f[i])%MOD;
	printf("%d",ans);
	return 0;
}