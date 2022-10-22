#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int n,m,u[o],v[o],w[o],fa[o],tot,E[o][3],ans[o],h[o],cnt,d[o],deg[o],z,ls[o],rs[o];bool vis[o];
void ins(int id){
	int U=u[id],V=v[id],W=w[id];
	if(U==V) return;
	if(!E[U][W]&&!E[V][W]){E[U][W]=E[V][W]=id;return;}
	if(E[U][W]){u[fa[E[U][W]]=fa[id]=++tot]=u[E[U][W]]+v[E[U][W]]-U;v[tot]=V;w[tot]=W;E[u[tot]][W]=E[U][W]=0;ins(tot);return;}
	if(E[V][W]){v[fa[E[V][W]]=fa[id]=++tot]=u[E[V][W]]+v[E[V][W]]-V;u[tot]=U;w[tot]=W;E[v[tot]][W]=E[V][W]=0;ins(tot);return;}
}
struct Edge{int v,p,id;}e[o];
inline void ad(int U,int V,int ID){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].id=ID;}
void dfs(int nw){
	if(vis[nw]) return;
	vis[nw]=1;
	for(int i=h[nw];i;i=e[i].p) ans[e[i].id]=(u[e[i].id]==nw),dfs(e[i].v);
}
int main(){
	scanf("%d%d",&n,&m);tot=m;
	for(int i=1;i<=m;++i) scanf("%d%d%d",&u[i],&v[i],&w[i]),ins(i),d[u[i]]+=w[i],d[v[i]]+=w[i];
	for(int i=1;i<=tot;++i)
		if(!fa[i]) ad(u[i],v[i],i),ad(v[i],u[i],i),++deg[u[i]],++deg[v[i]];
		else if(ls[fa[i]]) rs[fa[i]]=i;else ls[fa[i]]=i;
	for(int i=1;i<=n;z+=(d[i++]&1)) if(deg[i]&1) dfs(i);
	for(int i=1;i<=n;++i) dfs(i);
	for(int i=tot;i;--i) if(fa[i])
		if(u[fa[i]]==v[fa[i]]) ans[i]=((i==ls[fa[i]])^(u[i]==u[fa[i]]));
		else if(ans[fa[i]]) ans[i]=(((u[i]==u[fa[i]]||v[i]==u[fa[i]])?u[fa[i]]:(u[i]+v[i]-v[fa[i]]))==u[i]);
		else ans[i]=(((u[i]==v[fa[i]]||v[i]==v[fa[i]])?v[fa[i]]:(u[i]+v[i]-u[fa[i]]))==u[i]);
	printf("%d\n",z);
	for(int i=1;i<=m;++i) printf("%d",ans[i]+1);
	return 0;
}