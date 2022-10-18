#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;

int n,m;
vector<pair<int,long long> > adj[maxn];
long long dis[maxn];

void dijkstra(){
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    q.push(make_pair(0,n+1));
    memset(dis,-1,sizeof(dis));
    while(!q.empty()){
        int u=q.top().second;
        long long w=q.top().first;
        q.pop();
        if(dis[u]!=-1)continue;
        dis[u]=w;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            long long w=adj[u][i].second+dis[u];
            if(dis[v]==-1){
                q.push(make_pair(w,v));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w<<1));
        adj[v].push_back(make_pair(u,w<<1));
    }
    for(int i=1;i<=n;i++){
        long long s;
        cin>>s;
        adj[n+1].push_back(make_pair(i,s));
    }
    dijkstra();
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
    return 0;
}