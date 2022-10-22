#include<bits/stdc++.h>
using namespace std;
const int N=5005;
typedef long long ll;
template<class T> void chmax(T& x,T y){ return y>x?void(x=y):void(); }
ll f[N],g[N];
int s[N],tag[N],n;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&tag[i]);
		for(int i=1;i<=n;++i) scanf("%d",&s[i]);
		for(int i=1;i<=n;++i){
			f[0]=0;
			for(int k=1;k<i;++k){
				if(tag[i]!=tag[k])
					f[k]=g[k]+abs(s[i]-s[k]);
				else
					f[k]=(ll)-1e18;
//				printf("<%d %d %lld>",i,k,f[i][k]);
			}
			ll key=0;
			for(int j=i-1;j>=1;--j){
				if(tag[j]!=tag[i])
					chmax(g[j],key+abs(s[i]-s[j]));
				key=max(key,f[j]);
			}
			g[i]=key;
		}
		ll ans=0;
		for(int i=1;i<=n;++i) chmax(ans,g[i]);
		printf("%lld\n",ans);
	}
	return 0;
}