#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e6;
int T,n,m,h[o],cnt,u[o],v[o],st[o],tp,fa[o],d[o];bool vis[o],tr[o];
struct Edge{int v,p,id;}e[o];
inline void ad(int U,int V,int ID){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].id=ID;}
void dfs(int nw){
	vis[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v]) tr[fa[e[i].v]=e[i].id]=1,d[e[i].v]=d[nw]+1,dfs(e[i].v);
}
int main(){
	for(scanf("%d",&T);T--;cnt=0,putchar('\n')){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) h[i]=vis[i]=0;
		for(int i=1;i<=m;++i) scanf("%d%d",&u[i],&v[i]),ad(u[i],v[i],i),ad(v[i],u[i],i),tr[i]=0;
		dfs(1);
		if(m==n+2){
			tp=0;
			for(int i=1;i<=m;++i) if(!tr[i]) st[++tp]=u[i],st[++tp]=v[i];
			sort(st+1,st+tp+1);tp=unique(st+1,st+tp+1)-st-1;
			if(tp==3) for(int i=1;i<=m;++i) if(!tr[i]){tr[i]=1;if(d[u[i]]<d[v[i]]) u[i]=v[i];tr[fa[u[i]]]=0;break;}
		}
		for(int i=1;i<=m;++i) putchar(tr[i]+48);
	}
	return 0;
}