#include<cstdio>
using namespace std;
const int o=2e5+10,MOD=1e9+7;
int n,a[o],pw[o],cnt[30],ans;
int main(){
	scanf("%d",&n);
	for(int i=pw[0]=1,j;i<=n;++cnt[j],++i) for(scanf("%d",&a[i]),pw[i]=pw[i-1]*2%MOD,j=0;a[i]%2==0;a[i]/=2) ++j;
	ans=(pw[cnt[0]]-1ll)*pw[n-cnt[0]]%MOD;
	for(int i=1,s=n-cnt[0];i<30;++i) if(cnt[i]) s-=cnt[i],ans=(ans+(pw[cnt[i]]*(MOD+1ll)/2-1)%MOD*pw[s])%MOD;
	printf("%d",ans);
	return 0;
}