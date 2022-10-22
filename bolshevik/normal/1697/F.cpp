#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int o=1e6;
int T,n,m,k,h[o],cnt,dfn[o],low[o],st[o],tp,scc[o],sccn,H[o],d[o],topo[o];bool vis[o];queue<int> q;
struct Edge{int v,p;}e[o*30],E[o*30];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline void Ad(int U,int V){E[++cnt].v=V;E[cnt].p=H[U];H[U]=cnt;}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(dfn[nw]==low[nw]) for(++sccn,st[tp+1]=0;st[tp+1]^nw;vis[st[tp--]]=0) scc[st[tp]]=sccn;
}
inline void slv(){
	scanf("%d%d%d",&n,&m,&k);++k;
	for(int i=1;i<=2*n*k;++i) h[i]=dfn[i]=H[i]=d[i]=0;
	for(int i=1;i<=n;++i) for(int j=1;j<k;++j) ad((i-1)*k+j+1,(i-1)*k+j),ad((i-1)*k+j+n*k,(i-1)*k+j+1+n*k);
	for(int i=1;i<n;++i) for(int j=1;j<=k;++j) ad((i-1)*k+j,i*k+j),ad(i*k+j+n*k,(i-1)*k+j+n*k);
	for(int opt,i,j,x;m--;){
		scanf("%d%d",&opt,&i);
		if(opt==1) scanf("%d",&x),ad((i-1)*k+x,(i-1)*k+x+1),ad((i-1)*k+x+1+n*k,(i-1)*k+x+n*k);
		else if(opt==2){
			scanf("%d%d",&j,&x);
			for(int t=1;t<=x&&t<=k;++t) if(x-t+1<=k) ad((i-1)*k+t,(j-1)*k+x-t+1+n*k),ad((j-1)*k+t,(i-1)*k+x-t+1+n*k);
		}
		else{
			scanf("%d%d",&j,&x);
			for(int t=1;t<=x&&t<=k;++t) if(x-t+1<=k) ad((j-1)*k+x-t+1+n*k,(i-1)*k+t),ad((i-1)*k+x-t+1+n*k,(j-1)*k+t);
		}
	}
	for(int i=1;i<=n;++i) ad((i-1)*k+k,(i-1)*k+k+n*k),ad((i-1)*k+1+n*k,(i-1)*k+1);
	for(int i=1;i<=2*n*k;++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n*k;++i) if(scc[i]==scc[i+n*k]){printf("-1");return;}
	cnt=0;
	for(int i=1;i<=2*n*k;++i) for(int j=h[i];j;j=e[j].p) if(scc[i]^scc[e[j].v]) Ad(scc[i],scc[e[j].v]),++d[scc[e[j].v]];
	for(int i=1;i<=sccn;++i) if(!d[i]) q.push(i);
	for(cnt=0;!q.empty();topo[q.front()]=++cnt,q.pop()) for(int i=H[q.front()];i;i=E[i].p) if(!--d[E[i].v]) q.push(E[i].v);
	for(int i=1,a;i<=n;++i,printf("%d ",a)) for(a=1;a+1<k&&topo[scc[(i-1)*k+a+1]]>topo[scc[(i-1)*k+a+1+n*k]];++a);
}
int main(){
	for(scanf("%d",&T);T--;cnt=sccn=0,putchar('\n')) slv();
	return 0;
}