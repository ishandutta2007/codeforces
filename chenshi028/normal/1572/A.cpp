#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,h[o],cnt,ans,f[o],dfn[o],low[o],sccn,st[o],tp;bool flg,vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	f[nw]=1;
	for(int i=h[nw];i;i=e[i].p){
		if(!f[e[i].v]) dfs(e[i].v);
		f[nw]=max(f[nw],f[e[i].v]+(e[i].v<nw));
	}
}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(dfn[nw]==low[nw]) for(++sccn,st[tp+1]=0;st[tp+1]^nw;vis[st[tp--]]=0);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),cnt=sccn=0){
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;++i) h[i]=f[i]=dfn[i]=0;
		for(int i=1,k,a;i<=n;++i) for(scanf("%d",&k);k--;ad(a,i)) scanf("%d",&a);
		for(int i=1;i<=n;++i) if(!f[i]) dfs(i);
		for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
		if(sccn<n) ans=-1;
		else for(int i=1;i<=n;++i) ans=max(ans,f[i]);
	}
	return 0;
}