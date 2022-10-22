#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
vector<pair<int,ll> > g[N];
ll dis[45][N];
vector<pair<int,int> > _;
ll k[45];
int cnt,len;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dijkstra(int id,int u){
	dis[id][u]=0;
	q.push({0,u});
	while(!q.empty()){
		pair<ll,int> p=q.top();q.pop();
		int u=p.second;ll d=p.first;
		if(d!=dis[id][u]) continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;ll w=g[u][i].second;
			if(dis[id][u]+w<dis[id][v]){
				dis[id][v]=dis[id][u]+w;
				q.push(make_pair(dis[id][v],v));
			}
		}
	}
}
int fa[N][18],dfn[N],h[N];
ll dep[N];
void dfs(int u){
	dfn[u]=++cnt;
	h[u]=h[fa[u][0]]+1;
	int i;
	for(i=1;i<18;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(i=0;i<g[u].size();i++){
		int v=g[u][i].first;ll w=g[u][i].second;
		if(v==fa[u][0]) continue;
		else if(dfn[v]){
			if(u<v){
				_.push_back(make_pair(u,v));
				k[++len]=w;
				len++;				
			}
			continue;
		}
		dep[v]=dep[u]+w;
		fa[v][0]=u;
		dfs(v);
	}
}
int lca(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	int i;
	for(i=17;i>=0;i--){
		if(h[fa[x][i]]>=h[y])
			x=fa[x][i];
	}
	if(x==y) return x;
	for(i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++){
		int x,y;ll z;cin>>x>>y>>z;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	dfs(1);
	memset(dis,0x3f,sizeof(dis));
	len=0;
	for(i=0;i<_.size();i++){
		dijkstra(++len,_[i].first);
		dijkstra(++len,_[i].second);
	}
	int T;cin>>T;
	while(T--){
		int x,y;cin>>x>>y;
		ll ans=dep[x]+dep[y]-2*dep[lca(x,y)];
		for(i=1;i<=len;i+=2)
			ans=min(ans,min(dis[i][x]+dis[i+1][y],dis[i][y]+dis[i+1][x])+k[i]);
		cout<<ans<<endl;
	}
    return 0;
}