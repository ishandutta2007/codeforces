#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
set<int> st;
set<int> G[N];
struct edge{
	int u,v,w;
	inline bool operator <(const edge &b)const{
		return w<b.w;
	}
}e[N];
int fa[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
inline bool merge(int u,int v){
	u=rt(u),v=rt(v);
	if(u==v) return 0;
	fa[u]=v;
	return 1;
}
inline bool bfs(int S){
	queue<int> q;q.push(S);
	st.erase(S);
	while(!q.empty()){
		int u=q.front();q.pop();
		merge(u,S);
		for(auto it=st.begin();it!=st.end();){
			if(G[u].find(*it)!=G[u].end()){
				it++;
				continue;
			}
			q.push(*it);
			st.erase(it++);
		}
	}
}
vector<pair<int,int> > g[N];
int anc[N][20],h[N],d[N];
void dfs(int u){
	for(int i=1;i<20;i++) anc[u][i]=anc[anc[u][i-1]][i-1];
	h[u]=h[anc[u][0]]+1;
	for(auto e:g[u]){
		int v=e.first,w=e.second;
		if(v==anc[u][0]) continue;
		d[v]=d[u]+w;
		anc[v][0]=u;
		dfs(v);
	}
}
inline int lca(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(h[anc[x][i]]>=h[y])
			x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	int W=0;
	for(i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		W^=e[i].w;
		G[e[i].u].insert(e[i].v);
		G[e[i].v].insert(e[i].u);
	}
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++) fa[i]=i;
	ll ans=0;
	for(i=1;i<=m;i++)
		if(merge(e[i].u,e[i].v)) ans+=e[i].w;
	for(i=1;i<=n;i++) fa[i]=i,st.insert(i);
	for(i=1;i<=n;i++){
		if(st.find(i)!=st.end()) bfs(i);
	}
	int c=0;
	for(i=1;i<=n;i++){
		if(fa[i]==i) c++;
		else{
			g[rt(i)].push_back({i,1});
			g[i].push_back({rt(i),1});
		}
	}
	ll answ=0;
	for(i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			answ+=e[i].w;
			g[e[i].u].push_back({e[i].v,0});
			g[e[i].v].push_back({e[i].u,0});
		}
	}
	dfs(1);
	for(i=1;i<=m;i++){
		int w=d[e[i].u]+d[e[i].v]-2*d[lca(e[i].u,e[i].v)];
		if(w) W=min(W,e[i].w);
	}
	if(n-(ll(n-1)*n/2-m)<c) cout<<min(answ,ans);
	else cout<<min(ans,answ+W);
	return 0;
}