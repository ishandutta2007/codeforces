#include<cstdio>
using namespace std;
const int o=1e6+10;
int T,n,m,h[o],cnt,dfn[o],ed[o],col[o],fa[o],d[o],a[o],b[o],c,U,V;
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw){
	d[nw]=d[fa[nw]]+1;dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p)
		if(!d[e[i].v]) fa[e[i].v]=nw,Dfs(e[i].v);
		else if(d[e[i].v]<d[nw]&&e[i].v-fa[nw])
			if((d[nw]-d[e[i].v])%2) ++a[nw],--a[e[i].v];
			else ++b[nw],--b[e[i].v],++c,U=nw,V=e[i].v;
}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p) if(d[e[i].v]==d[nw]+1) dfs(e[i].v),a[nw]+=a[e[i].v],b[nw]+=b[e[i].v]; 
}
void pnt(int nw){for(int i=h[nw];i;i=e[i].p) if(!col[e[i].v]) col[e[i].v]=3-col[nw],pnt(e[i].v);}
inline void prt(){printf("YES\n");for(int i=1;i<=n;++i) printf("%d",col[i]-1);putchar('\n');return;}
inline void slv(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) d[i]=h[i]=col[i]=a[i]=b[i]=0;
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	cnt=0;Dfs(1);dfs(1);
	if(!c){col[1]=1;pnt(1);prt();return;}
	for(int i=2;i<=n;++i) if(!a[i]&&b[i]==c){
		col[i]=col[fa[i]]=2;pnt(i);pnt(fa[i]);prt();
		return;
	}
	if(c==1) col[U]=col[V]=2,pnt(U),pnt(V),prt();
	else printf("NO\n");
}
int main(){
	for(scanf("%d",&T);T--;cnt=c=0) slv();
	return 0;
}