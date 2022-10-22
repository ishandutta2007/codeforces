#include<cstdio>
using namespace std;
const int o=2e5+10,MOD=1e9+7;
int T,n,a[o],b[o],d[o],h[o],cnt,ans,nn,m;bool vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	vis[nw]=1;++nn;
	for(int i=h[nw];i;i=e[i].p,++m) if(!vis[e[i].v]) dfs(e[i].v);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),cnt=0){
		scanf("%d",&n);ans=1;
		for(int i=1,x;i<=n;++i) scanf("%d",&x),a[x]=i;
		for(int i=1,x;i<=n;++i) scanf("%d",&x),b[x]=i;
		for(int i=1;i<=n;++i) d[i]=h[i]=vis[i]=0;
		for(int i=1,x;i<=n;++i) scanf("%d",&x),d[x]=i;
		for(int i=1;i<=n;++i) if(!d[i]&&a[i]-b[i]) ad(a[i],b[i]),ad(b[i],a[i]);
		for(int i=1;i<=n;++i) if(!vis[i]){
			nn=m=0;dfs(i);
			if(m==nn*2) ans=ans*2%MOD;
		}
	}
	return 0;
}