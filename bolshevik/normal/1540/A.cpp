#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,d[o];long long ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&d[i]);
		sort(d+1,d+n+1);
		for(int i=2;i<=n;++i) ans+=d[i]-d[i-1];
		for(int i=1;i<=n;++i) ans-=(i-1ll)*d[i]-(n-i)*1ll*d[i];
	}
	return 0;
}