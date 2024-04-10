#include<cstdio>
using namespace std;
const int o=1e6+10;
int n,h[o],cnt,dfn[o],ed[o],ls[o*20],rs[o*20],s[o*20],f[o],rt[o],sz[o],tot,g[o];long long ans;
struct Edge{int v,p,w;}e[o];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
void modify(int&id,int pos,int val,int l=1,int r=n){
	if(!id) id=++tot;
	s[id]+=val;
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify(ls[id],pos,val,l,md);
	else modify(rs[id],pos,val,md+1,r);
}
int query(int id,int ql,int qr,int l=1,int r=n){
	if(!id) return 0;
	if(ql<=l&&r<=qr) return s[id];
	int md=l+r>>1;
	return (ql<=md?query(ls[id],ql,qr,l,md):0)+(md<qr?query(rs[id],ql,qr,md+1,r):0);
}
void Dfs(int nw,int fa){
	sz[nw]=1;dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		Dfs(e[i].v,nw),modify(rt[e[i].w],dfn[e[i].v],f[e[i].v]=sz[e[i].v]-query(rt[e[i].w],dfn[e[i].v],ed[e[i].v])),sz[nw]+=sz[e[i].v];
	ed[nw]=cnt;
}
void dfs(int nw,int fa){
	for(int i=h[nw],j,k;i;i=e[i].p) if(e[i].v^fa) ans+=(k=g[j=e[i].w])*1ll*f[e[i].v],g[j]=f[e[i].v],dfs(e[i].v,nw),g[j]=k;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;++i) scanf("%d%d%d",&u,&v,&w),ad(u,v,w),ad(v,u,w);
	Dfs(1,cnt=0);
	for(int i=1;i<=n;++i) g[i]=n-query(rt[i],1,n);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}