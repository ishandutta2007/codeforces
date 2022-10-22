#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int o=1e5;const long long inf=1e18;
int n,m,a[o],S,T,h[o],cnt=1,lst[o],ids[o],idt[o];bool vis[o];long long phi[o],dis[o];queue<int> Q;priority_queue<pair<long long,int> > q;
struct Edge{int v,p,c,f;}e[o];
inline void ad(int U,int V,int C,int F){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;e[cnt].f=F;}
inline void add(int ST,int ED,int CA,int FY){ad(ST,ED,CA,FY);ad(ED,ST,0,-FY);}
inline void spfa(){
	for(int i=S;i<=T;++i) dis[i]=-inf;
	for(vis[S]=1,dis[S]=0,Q.push(S);!Q.empty();vis[Q.front()]=0,Q.pop()) for(int i=h[Q.front()];i;i=e[i].p)
		if(e[i].c&&dis[e[i].v]<dis[Q.front()]+e[i].f){dis[e[i].v]=dis[Q.front()]+e[i].f;if(!vis[e[i].v]) vis[e[i].v]=1,Q.push(e[i].v);}
}
inline void dijkstra(){
	for(q.push(make_pair(dis[S]=0,S));!q.empty();){
		int t=q.top().second;q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].p) if(e[i].c&&dis[e[i].v]<dis[t]+e[i].f+phi[t]-phi[e[i].v])
			lst[e[i].v]=i,q.push(make_pair(dis[e[i].v]=dis[t]+e[i].f+phi[t]-phi[e[i].v],e[i].v));
	}
}
int main(){
	scanf("%d%d",&n,&m);S=0;T=n+1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),add(S,i,1,0),ids[i]=cnt-1,add(i,T,1,0),idt[i]=cnt-1;
	for(int u,v;m--;) scanf("%d%d",&u,&v),add(u,v,n,a[u]-a[v]);
	for(spfa();dis[T]+phi[T]>0;){
		for(int i=S;i<=T;vis[i++]=0) phi[i]+=dis[i],dis[i]=-inf;
		dijkstra();
		for(int i=T;i^S;i=e[lst[i]^1].v) --e[lst[i]].c,++e[lst[i]^1].c;
	}
	for(int i=1;i<=n;++i) printf("%lld ",a[i]+dis[i]+phi[i]);
	return 0;
}