#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll inf=1e18;
const int N=2e5+5;
int n,m,s,ans;
vector<pii>g[N];
ll dis[N];
vector<int>rg[N],tr[N];
int dp[N],fa[N][20];
void dij(){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	fill(dis+1,dis+n+1,inf),dis[s]=0,pq.push({0,s});
	while(!pq.empty()){
		auto [w,u]=pq.top();pq.pop();
		if(dis[u]<w)continue;
		for(auto [v,z]:g[u]){
			ll W=w+z;
			if(W<dis[v])dis[v]=W,pq.push({W,v});
		}
	}
	for(int i=1;i<=n;i++)if(dis[i]<inf)
		for(auto [j,z]:g[i])if(dis[j]==dis[i]+z)
			rg[j].push_back(i);
}
int lca(int u,int v){
	if(v<0)return u;
	if(dp[u]>dp[v])swap(u,v);
	for(int i=19;~i;i--)if((dp[v]-dp[u])&(1<<i))v=fa[v][i];
	if(u==v)return u;
	for(int i=19;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
bool cmp(int i,int j){return dis[i]<dis[j];}
int getsz(int x){
	int a=1;for(auto y:tr[x])a+=getsz(y);
	if(x!=s)ans=max(ans,a);return a;
}
void sol(){
	vector<int>ord;
	for(int i=1;i<=n;i++)if(s!=i&&dis[i]<inf)ord.push_back(i);
	sort(ord.begin(),ord.end(),cmp);
	for(auto x:ord){
		int t=-1;for(auto y:rg[x])t=lca(y,t);
		tr[t].push_back(x),fa[x][0]=t,dp[x]=dp[t]+1;
		for(int j=1;j<20;j++)fa[x][j]=fa[fa[x][j-1]][j-1];
	}
	getsz(s),printf("%d",ans);
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	while(m--){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w}),g[v].push_back({u,w});
	}
	dij();
	sol();
}