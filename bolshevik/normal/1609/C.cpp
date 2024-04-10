#include<cstdio>
using namespace std;
const int o=2e5+10,O=1e6+10;
int T,n,e,a[o],pri[o],cnt,s[o],nxt[o];long long ans;bool vis[O];
inline void linear_sieve(){
	for(int i=2;i<O;++i){
		if(!vis[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<O;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int main(){
	linear_sieve();
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&e);nxt[n+1]=n+1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=n;i;--i) if(a[i]>1&&!vis[a[i]]) nxt[i]=i;else nxt[i]=(i+e>n?n+1:nxt[i+e]);
		for(int i=1;i<=n;++i) s[i]=(i>e?s[i-e]:0)+(a[i]!=1);
		for(int i=1,l,r,md;i<=n;++i) if(nxt[i]<=n&&s[nxt[i]]-(i>e?s[i-e]:0)==1){
			for(l=(nxt[i]-i)/e,r=(n-i)/e;l<r;) if(s[i+e*(md=(l+r>>1)+1)]-(i>e?s[i-e]:0)==1) l=md;else r=md-1;
			if(nxt[i]==i) nxt[i]+=e;
			ans+=r-(nxt[i]-i)/e+1;
		}
	}
	return 0;
}