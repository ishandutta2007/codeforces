#include<cstdio>
using namespace std;
const int o=1e6+10,MOD=998244353;
int T,n,k,v[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%d",&n,&k);ans=1;
		for(int i=1;i<=n;++i) scanf("%d",&v[i]);
		for(int i=n-k+1;i<=n;++i) if(v[i]>0) ans=0;
		for(int i=1;i<=n-k;++i) if(v[i]>=i) ans=0;
		for(int i=1;i<=n-k;++i) if(!v[i]) ans=ans*(k+1ll)%MOD;else if(v[i]<0) ans=ans*1ll*(i+k)%MOD;
		for(int i=1;i<=k;++i) ans=ans*1ll*i%MOD; 
	}
	return 0;
}