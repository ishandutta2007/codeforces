#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int o=2e6+10;
int n,q,H[o],Cnt,fa[o],d[o],h[o],cnt,dfn[o],low[o],tot,st[o],st2[o],tp,tp2,scc[o],sccn,l[o],r[o],t[o];
bool vis[o];char s[o];queue<int> Q;
struct Edge{int v,p;}E[o],e[o*10];
inline void Ad(int U,int V){E[++Cnt].v=V;E[Cnt].p=H[U];H[U]=Cnt;}
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	d[nw]=d[fa[nw]]+1;
	for(int i=H[nw];i;i=E[i].p) if(E[i].v-fa[nw]) fa[E[i].v]=nw,dfs(E[i].v);
}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(low[nw]==dfn[nw]) for(++sccn;st[tp+1]^nw;vis[st[tp--]]=0) scc[st[tp]]=sccn;
}
inline int calc(int x,char c,int val){
	if(!l[x]){l[x]=c;return x*2-1;}
	if(l[x]==c) return x*2-1;
	if(!r[x]){r[x]=c;return x*2;}
	if(r[x]==c) return x*2;
	return val;
}
int main(){
	scanf("%d%d",&n,&q);tot=2*n;
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),Ad(u,v),Ad(v,u);
	dfs(1);
	for(int u,v,x,y;q--;){
		scanf("%d%d%s",&u,&v,s+1);
		x=++tot;y=++tot;tp=tp2=0;
		if(d[u]<d[v]) swap(u,v);
		for(;d[u]>d[v];u=fa[u]) st[++tp]=u;
		for(;u^v;u=fa[u],v=fa[v]) st[++tp]=u,st2[++tp2]=v;
		st[++tp]=u;
		for(int i=tp2;i;--i) st[++tp]=st2[i];
		for(int i=1,j;i<=tp;++i){
			ad(x,j=calc(st[i],s[i],y));
			if(j^y) ad(st[i]*4-1-j,y);
			ad(y,j=calc(st[i],s[tp-i+1],x));
			if(j^x) ad(st[i]*4-1-j,x);
		}
	}
	cnt=0;
	for(int i=1;i<=tot;++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<tot;i+=2) if(scc[i]==scc[i+1]){printf("NO");return 0;}
	printf("YES\n");cnt=Cnt=0;
	for(int i=1;i<=sccn;++i) d[i]=H[i]=0;
	for(int i=1;i<=tot;++i) for(int j=h[i];j;j=e[j].p)
		if(scc[i]^scc[e[j].v]) Ad(scc[i],scc[e[j].v]),++d[scc[e[j].v]];
	for(int i=1;i<=sccn;++i) if(!d[i]) Q.push(i),t[i]=++cnt;
	for(;!Q.empty();Q.pop()) for(int i=H[Q.front()];i;i=E[i].p)
		if(!--d[E[i].v]) t[E[i].v]=++cnt,Q.push(E[i].v);
	for(int i=1,j;i<=n;++i) j=(t[scc[2*i-1]]<t[scc[2*i]]?r[i]:l[i]),putchar(j?j:'a');
	return 0;
}