#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxl=20;
struct edg{
	int u,v;
	long long w;
};

int n,m;
vector<pair<int,long long> > adj[maxn],bdj[maxn];
int p[maxn];
vector<edg> ext;
int dep[maxn],fa[maxn][maxl];
long long dis[maxn][maxl];
long long fdis[maxl+4][2][maxn];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
 
void dijkstra(int u,long long* dis){
	memset(dis,-1,sizeof(fdis[0][0]));
	while(!q.empty())q.pop();
	q.push(make_pair(0,u));
	while(!q.empty()){
		int u=q.top().second;
		long long w=q.top().first;
		q.pop();
		if(dis[u]!=-1)continue;
		dis[u]=w;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			long long w1=adj[u][i].second+w;
			if(dis[v]==-1){
				q.push(make_pair(w1,v));
			}
		}
	}	
} 
int grt(int u){
	if(u==p[u])return u;
	return p[u]=grt(p[u]);
}

void dfs(int u){
	for(int i=0;i<bdj[u].size();i++){
		int v=bdj[u][i].first;
		long long w=bdj[u][i].second;
		if(!dep[v]){
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			dis[v][0]=w;
			dfs(v);
		}
	}
}

long long gdis(int u,int v){
	long long ans=0;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=maxl-1;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]){
			ans+=dis[u][i]; 
			u=fa[u][i];
		}
	}
	if(u==v)return ans;
	for(int i=maxl-1;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			ans+=dis[u][i]+dis[v][i];
			u=fa[u][i];v=fa[v][i];
		}
	}
	return ans+dis[u][0]+dis[v][0];
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
		if(grt(u)!=grt(v)){
			p[grt(u)]=grt(v);
			bdj[u].push_back(make_pair(v,w));
			bdj[v].push_back(make_pair(u,w));
		}else{
			edg nw;nw.u=u;nw.v=v;nw.w=w;
			ext.push_back(nw);
		}
	}
	dep[1]=1;
	dfs(1);
	for(int i=1;i<maxl;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			dis[j][i]=dis[j][i-1]+dis[fa[j][i-1]][i-1];
		}
	}
	for(int i=0;i<ext.size();i++){
		dijkstra(ext[i].u,fdis[i][0]);
		dijkstra(ext[i].v,fdis[i][1]);
	}
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=gdis(u,v);
		for(int i=0;i<ext.size();i++){
			ans=min(ans,fdis[i][0][u]+fdis[i][1][v]+ext[i].w);
			ans=min(ans,fdis[i][0][v]+fdis[i][1][u]+ext[i].w);
		}
		cout<<ans<<'\n';
	}
	return 0;
}