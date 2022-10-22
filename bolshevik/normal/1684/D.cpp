#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
const int o=2e5+10;
int T,n,k,a[o];long long ans;pair<int,int> p[o];
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),ans+=a[i],p[i]=make_pair(-i-a[i],i);
		sort(p+1,p+n+1);
		for(int i=1;i<=k;++i) ans+=n-(k-i)-p[i].second-a[p[i].second];
	}
	return 0;
}