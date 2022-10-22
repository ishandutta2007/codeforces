#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int o=2e6+10,inf=1e9;
int n,K,a[o],h[o],cnt=1,S,T,phi[o],dis[o],lst[o],ans,id[o],s[o];vector<pair<int,int> > vec[o];
bool vis[o];queue<int> Q;priority_queue<pair<int,int> > q;
struct Edge{int v,p,c,f;}e[o];
inline void ad(int U,int V,int C,int F){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;e[cnt].f=F;}
inline void add(int ST,int ED,int CA,int FY){ad(ST,ED,CA,FY);ad(ED,ST,0,-FY);}
inline void spfa(){
	for(int i=S;i<=T;++i) dis[i]=-inf;
	for(Q.push(S),dis[S]=0,vis[S]=1;!Q.empty();vis[Q.front()]=0,Q.pop())
		for(int i=h[Q.front()];i;i=e[i].p) if(e[i].c&&dis[e[i].v]<dis[Q.front()]+e[i].f)
			{dis[e[i].v]=dis[Q.front()]+e[i].f;if(!vis[e[i].v]) vis[e[i].v]=1,Q.push(e[i].v);}
}
inline bool dijkstra(){
	for(int i=S;i<=T;dis[i++]=-inf) phi[i]+=dis[i],lst[i]=vis[i]=0;
	for(q.push(make_pair(dis[S]=0,S));!q.empty();){
		int t=q.top().second;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].p) if(e[i].c&&dis[e[i].v]<dis[t]+e[i].f+phi[t]-phi[e[i].v])
			q.push(make_pair(dis[e[i].v]=dis[t]+e[i].f+phi[t]-phi[e[i].v],e[i].v)),lst[e[i].v]=i;
	}
	return lst[T];
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<(1<<n);++i) scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);++i) if(__builtin_popcount(i)&1) for(int j=0;j<n;++j) ++s[a[i]+a[i^(1<<j)]];
	for(int i=0;i<o;++i) vec[i].reserve(s[i]);
	for(int i=0;i<(1<<n);++i) if(__builtin_popcount(i)&1)
		for(int j=0;j<n;++j) vec[a[i]+a[i^(1<<j)]].push_back(make_pair(i,i^(1<<j)));
	for(int i=o,t=(2*n-1)*(K-1)+1;i--&&t;) for(int j=vec[i].size(),x,y;j--&&t;--t){
		if(!id[x=vec[i][j].first]) id[x]=++T;
		if(!id[y=vec[i][j].second]) id[y]=++T;
		add(id[x],id[y],1,0);
	}
	++T;
	for(int i=0;i<(1<<n);++i) if(id[i])
		if(__builtin_popcount(i)&1) add(S,id[i],1,a[i]);else add(id[i],T,1,a[i]);
	for(spfa();K--&&dijkstra();ans+=dis[T]+phi[T])
		for(int i=T;i;i=e[lst[i]^1].v) --e[lst[i]].c,++e[lst[i]^1].c;
	printf("%d",ans);
	return 0;
}