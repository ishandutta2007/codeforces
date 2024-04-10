#include<bits/stdc++.h>
using namespace std;
const int N=5+1e4;
typedef long long ll;
ll f[N];
int p[N],s[N];
int main(){
	int n,c; scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=1;i<=n;++i) scanf("%d",&s[i]);
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j>=0;--j){
			f[j]=min(j==i?1e18:f[j]+s[i],j==0?1e18:f[j-1]+p[i]+1ll*c*(i-j));
//			printf("<%d %d %lld>",i,j,f[j]);
		}
	}
	ll ans=1e18;
	for(int j=0;j<=n;++j)
		ans=min(ans,f[j]);
	printf("%lld\n",ans);
	return 0;
}