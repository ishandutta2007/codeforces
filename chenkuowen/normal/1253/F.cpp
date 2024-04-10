#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e5;
struct Graph{
	struct Edge{ int to,nxt; ll k; };
	vector<int> head; vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1); 
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y,ll k){
		edge.push_back((Edge){y,head[x],k});
		head[x]=edge.size()-1;
	}
	inline void add2(int x,int y,ll k){ add(x,y,k),add(y,x,k); }
}G;
namespace T{
	int fa[23][N],dep[N];
	ll mx[23][N];
	void dfs(int x,int pre){
		dep[x]=dep[pre]+1;
		for(int l=1;l<=20;++l){
			fa[l][x]=fa[l-1][fa[l-1][x]];
			mx[l][x]=max(mx[l-1][x],mx[l-1][fa[l-1][x]]); 
		}
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(y!=pre){
				fa[0][y]=x;
				mx[0][y]=G.edge[j].k;
				dfs(y,x);
			}
		}
	}
	void init(){
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
		memset(mx,0,sizeof(mx));
		dfs(1,0);
	}
	ll query(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		ll ret=0;
		for(int l=20;l>=0;--l)
			if(dep[fa[l][x]]>=dep[y])
				ret=max(ret,mx[l][x]),x=fa[l][x];
		for(int l=20;l>=0;--l)
			if(fa[l][x]!=fa[l][y]){
				ret=max({ret,mx[l][x],mx[l][y]});
				x=fa[l][x],y=fa[l][y];
			}
		if(x!=y){
			ret=max({ret,mx[0][x],mx[0][y]});
			x=fa[0][x]; y=fa[0][y];
		}
		return ret;
	}
}
struct DSF{
	vector<int> fa;
	DSF(){}
	DSF(int n){
		fa=vector<int>(n+1);
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
};
struct E{ int x,y; ll k; };
bool cmpE(E x,E y){ return x.k<y.k; }
pair<ll,int> dis[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dij(pair<ll,int> dis[],vector<pair<int,int> > s,int n){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=1;i<=n;++i) dis[i]=make_pair((ll)2e18,0);
	for(auto x:s){
		dis[x.first]=make_pair(0,x.second);
		q.push(make_pair(0,x.first));
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
//	for(int i=1;i<=n;++i) printf("(%lld %d)",dis[i].first,dis[i].second);

}
int main(){
	int n,m,k,q; scanf("%d%d%d%d",&n,&m,&k,&q);
	G=Graph(n,m);
	for(int i=1;i<=m;++i){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		G.add2(u,v,w);
	}
	vector<pair<int,int> > s;
	for(int i=1;i<=k;++i) s.push_back(make_pair(i,i));
	dij(dis,s,n);
	vector<E> e;
	for(int x=1;x<=n;++x){
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(dis[x].second>0&&dis[x].second<dis[y].second){
				e.push_back((E){dis[x].second,dis[y].second,dis[x].first+dis[y].first+G.edge[j].k});
			}
		}
	}
	sort(e.begin(),e.end(),cmpE);
	DSF dsf(k);
	G=Graph(k,k);
	for(auto d:e){
		int x=dsf.fs(d.x),y=dsf.fs(d.y);
		if(x==y) continue;
		dsf.merge(x,y);
//		printf("[%d %d %lld]",d.x,d.y,d.k);
		G.add2(d.x,d.y,d.k);
	}
	T::init();
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		printf("%lld\n",T::query(x,y));
	}
	return 0;
}