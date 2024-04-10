#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,m,H,a[o],h[o],cnt,dfn[o],low[o],scc[o],sz[o],d[o],sccn,ans=o;bool vis[o];stack<int> S;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;S.push(nw);vis[nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(dfn[nw]==low[nw]){
		for(++sccn;S.top()^nw;S.pop()) ++sz[scc[S.top()]=sccn];
		++sz[scc[nw]=sccn];S.pop();
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&H);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int u,v;m--;){
		scanf("%d%d",&u,&v);
		if((a[u]+1)%H==a[v]) ad(u,v);
		if((a[v]+1)%H==a[u]) ad(v,u);
	}
	cnt=0;
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;++i) for(int j=h[i];j;j=e[j].p)
		if(scc[i]^scc[e[j].v]) ++d[scc[i]];
	for(int i=1;i<=sccn;++i) if(!d[i]) ans=min(ans,sz[i]);
	printf("%d\n",ans);
	for(int i=1;i<=sccn;++i) if(!d[i]&&ans==sz[i]){
		for(int j=1;j<=n;++j) if(scc[j]==i) printf("%d ",j);
		break;
	}
	return 0;
}