#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
const int o=2e5+10;const long long inf=1e18;
int n,m,K,h[o],cnt,tp;long long dis[o];bool vis[o];priority_queue<pair<long long,int> > q;pair<int,long long> st[o];
struct Edge{int v,p,w;}e[o];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
inline void dijkstra(){
	for(int i=1;i<=n;vis[i++]=0) if(dis[i]<inf) q.push(make_pair(-dis[i],i));
	for(int t;!q.empty();){
		t=q.top().second;q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].p) if(dis[e[i].v]>dis[t]+e[i].w)
			q.push(make_pair(-(dis[e[i].v]=dis[t]+e[i].w),e[i].v));
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,u,v,w;i<=m;++i) scanf("%d%d%d",&u,&v,&w),ad(u,v,w),ad(v,u,w);
	for(int i=2;i<=n;++i) dis[i]=inf;
	for(dijkstra();K--;dijkstra()){
		tp=0;
		for(int i=n;i;--i) if(dis[i]<inf){
			for(;tp>1&&(st[tp-1].second-st[tp].second)*(-2*i-st[tp].first)<=(st[tp].second-
			(i*1ll*i+dis[i]))*(st[tp].first-st[tp-1].first);--tp);
			st[++tp]=make_pair(-2*i,i*1ll*i+dis[i]);
		}
		for(int i=1,j=tp;i<=n;dis[i]=i*1ll*i+i*1ll*st[j].first+st[j].second,++i)
			for(;j>1&&i*1ll*st[j].first+st[j].second>i*1ll*st[j-1].first+st[j-1].second;--j);
	}
	for(int i=1;i<=n;++i) printf("%lld ",dis[i]);
	return 0;
}