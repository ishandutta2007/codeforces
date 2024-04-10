#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=100005;
 
int n,m,k;
int s[maxn];
int idg[maxn];
vector<pair<pair<int,int>,long long> > adj[maxn];
long long dis[maxn];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int vis[maxn];
int ans;

void dijkstra(){
	q.push(make_pair(0,1));
	memset(dis,-1,sizeof(dis));
	while(!q.empty()){
		int u=q.top().second;
		long long w=q.top().first;
		q.pop();
		if(dis[u]!=-1)continue;
		dis[u]=w;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first.second;
			long long w1=adj[u][i].second+w;
			if(dis[v]==-1){
				q.push(make_pair(w1,v));
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int v=adj[i][j].first.second;
			long long w=adj[i][j].second;
			if(dis[i]+w==dis[v]){
				if(adj[i][j].first.first)vis[v]++;
				else idg[v]++;
			}else{
				if(adj[i][j].first.first){
					ans++;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(make_pair(0,v),w));
		adj[v].push_back(make_pair(make_pair(0,u),w));
	}
	for(int i=1;i<=k;i++){
		int w;
		cin>>s[i]>>w;
		adj[1].push_back(make_pair(make_pair(1,s[i]),w));
		adj[s[i]].push_back(make_pair(make_pair(0,1),w));
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(idg[i]){
			ans+=vis[i];
		}else ans+=max(0,vis[i]-1); 
	}
	cout<<ans;
	return 0;
}