#include<cstdio>
#include<vector>
using namespace std;
const int o=2e5+10,MOD=998244353,O=1e7+10;
int T,n,h[o],cnt,inv[o],w[o],a[o],b[o],val[O],tp,ans;int*stk[O];bool vis[o];vector<int> d[o];
struct Edge{int v,p,x,y;}e[o*2];
inline void ad(int U,int V,int X,int Y){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].x=X;e[cnt].y=Y;}
void dfs(int nw,int fa){
	for(int i=h[nw],j;i;i=e[i].p) if(e[i].v^fa){
		w[e[i].v]=w[nw]*1ll*e[i].y%MOD*inv[e[i].x]%MOD;j=tp;
		for(int v:d[e[i].y]){
			stk[++tp]=a+v;val[tp]=a[v];
			for(long long k=v;e[i].y%k==0;k*=v) --a[v];
		}
		for(int v:d[e[i].x]){
			stk[++tp]=a+v,val[tp]=a[v];
			for(long long k=v;e[i].x%k==0;k*=v) b[v]=max(b[v],++a[v]);
		}
		dfs(e[i].v,nw);
		for(;tp>j;--tp) *stk[tp]=val[tp];
	}
}
int main(){
	for(int i=2;i<o;++i) for(int j=2*i;j<o;j+=i) vis[j]=1;
	for(int i=2;i<o;++i) if(!vis[i]) for(int j=i;j<o;j+=i) d[j].push_back(i);
	for(scanf("%d",&T);T--;printf("%d\n",ans),cnt=ans=0){
		scanf("%d",&n);
		for(int i=2;i<=n;++i) for(int j=2*i;j<=n;j+=i) vis[j]=1;
		inv[1]=1;for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=1;i<=n;++i) h[i]=a[i]=b[i]=0;
		for(int i=1,u,v,x,y;i<n;++i) scanf("%d%d%d%d",&u,&v,&x,&y),ad(u,v,x,y),ad(v,u,y,x);
		dfs(w[1]=1,0);
		for(int i=1;i<=n;++i) ans=(ans+w[i])%MOD;
		for(int i=2;i<=n;++i) if(!vis[i]) for(;b[i]--;ans=ans*1ll*i%MOD);
	}
	return 0;
}