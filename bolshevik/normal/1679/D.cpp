#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,m,h[o],cnt,a[o],ans,Val;long long d[o],k;bool vis[o],inst[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	if(vis[nw]){if(inst[nw]) d[nw]=k;return;}
	vis[nw]=inst[nw]=1;d[nw]=0;
	for(int i=h[nw];i;i=e[i].p) if(a[e[i].v]<=Val) dfs(e[i].v),d[nw]=max(d[nw],d[e[i].v]);
	++d[nw];inst[nw]=0;
}
inline bool chk(int val){
	Val=val;
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i) if(a[i]<=val) dfs(i);
	for(int i=1;i<=n;++i) if(a[i]<=val&&d[i]>=k) return true;
	return false;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),ad(u,v);
	for(int l=1,r=1e9+1,md;l<r;ans=l) if(chk(md=l+r>>1)) r=md;else l=md+1;
	printf("%d",ans>1e9?-1:ans);
	return 0;
}