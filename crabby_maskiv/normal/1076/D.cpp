#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
int n,m,k;
priority_queue<pair<ll,int> ,vector<pair<ll,int> > ,greater<pair<ll,int> > > q;
ll dis[N];
struct edge{
	int v,id;ll w;
	edge(int v,ll w,int id):v(v),w(w),id(id){}
};
vector<edge> g[N],_g[N];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		pair<ll,int> p=q.top();q.pop();
		int u=p.second;ll d=p.first;
		if(d!=dis[u]) continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;ll w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
bool vis[N];
int cnt=0;
void dfs(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].v,id=g[u][i].id;
		ll w=g[u][i].w;
		if(vis[v]) continue;
		if(dis[u]+w>dis[v]) continue;
		cout<<id<<" ";
		cnt++;
		if(cnt==k) exit(0);
		vis[v]=1;
		dfs(v);
	}
}
int main(){
	int i,j;
	cin>>n>>m>>k;
	k=min(k,n-1);
	for(i=1;i<=m;i++){
		int x,y;ll z;cin>>x>>y>>z;
		g[x].push_back(edge(y,z,i));
		g[y].push_back(edge(x,z,i));
	}
	dijkstra();
	cout<<k<<endl;
	if(k==0) return 0;
	vis[1]=1;
	dfs(1);
	return 0;
}