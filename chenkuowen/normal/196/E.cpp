#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
typedef long long ll;
struct Graph{
	struct Edge{ int to,nxt,k; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y,int k){
		edge.push_back((Edge){y,head[x],k});
		head[x]=edge.size()-1;
	}
}G;
struct DSF{
	vector<int> fa;
	DSF(int n=0){ 
		fa=vector<int>(n+1,0);
		for(int i=0;i<=n;++i) fa[i]=i;
	}
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		if(fs(x)==fs(y)) return;
		fa[fs(y)]=fs(x);
	}
}dsf;
pair<ll,int> dis[N];
struct E{ int x,y; ll w; };
bool cmpE(E x,E y){ return x.w<y.w; }
int main(){
	int n,m; scanf("%d%d",&n,&m);
	G=Graph(n,m+m);
	for(int i=1;i<=m;++i){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		G.add(x,y,w); G.add(y,x,w);
	}
	for(int i=1;i<=n;++i) dis[i]=make_pair((ll)2e18,0);
	int k; scanf("%d",&k);
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >  q;
	for(int i=1;i<=k;++i){
		int x; scanf("%d",&x);
		dis[x]=make_pair(0,i);
		q.push(make_pair(dis[x].first,x));
	}
	while(!q.empty()){
		int x=q.top().second; ll k=q.top().first; q.pop();
		if(k!=dis[x].first) continue;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(dis[x].first+G.edge[j].k<dis[y].first){
				dis[y].first=dis[x].first+G.edge[j].k;
				dis[y].second=dis[x].second;
				q.push(make_pair(dis[y].first,y));
			}
		}
	}
	dsf=DSF(k);
	vector<E> e;
	for(int x=1;x<=n;++x){
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(x<y&&dis[x].second>0&&dis[y].second>0){
				e.push_back((E){dis[x].second,dis[y].second,dis[x].first+dis[y].first+G.edge[j].k});
			}
		}
	}
	sort(e.begin(),e.end(),cmpE);
	ll ans=dis[1].first;
	for(auto d:e){
		int x=dsf.fs(d.x),y=dsf.fs(d.y);
		if(x==y) continue;
		dsf.merge(x,y);
		ans+=d.w;
	}
	printf("%lld\n",ans);
	return 0;
}