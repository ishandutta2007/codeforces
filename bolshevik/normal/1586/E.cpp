#include<cstdio>
using namespace std;
const int o=6e5+10;
int n,m,q,U[o],V[o],w[o],h[o],cnt,deg[o],ans,fa[o],dfn[o],ed[o],st1[o],tp1,st2[o],tp2;bool vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw){
	vis[nw]=1;dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v]) fa[e[i].v]=nw,Dfs(e[i].v);
	ed[nw]=cnt;
}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p) if(fa[e[i].v]==nw) dfs(e[i].v),w[nw]^=w[e[i].v];
}
inline bool isanc(int x,int y){return dfn[x]<=dfn[y]&&ed[y]<=ed[x];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	Dfs(1);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) scanf("%d%d",&U[i],&V[i]),w[U[i]]^=1,w[V[i]]^=1;
	dfs(1);
	for(int i=2;i<=n;++i) if(w[i]) ++deg[i],++deg[fa[i]];
	for(int i=1;i<=n;++i) ans+=deg[i]%2;
	if(!ans){
		printf("YES\n");
		for(int i=1;i<=q;++i){
			for(tp1=0;!isanc(U[i],V[i]);U[i]=fa[U[i]]) st1[++tp1]=U[i];
			for(tp2=0;!isanc(V[i],U[i]);V[i]=fa[V[i]]) st2[++tp2]=V[i];
			printf("%d\n",tp1+tp2+1);
			for(int j=1;j<=tp1;++j) printf("%d ",st1[j]);
			printf("%d ",U[i]);
			for(int j=tp2;j;--j) printf("%d ",st2[j]);
			putchar('\n');
		}
	}
	else printf("NO\n%d",ans/2);
	return 0;
}