#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,m;
vector<int> g[1005];
int dis[1005],fa[1005];
bool vis[1005];

void bfs(int src){
    queue<int> q;
    q.emplace(src);
    memset(dis,-1,sizeof(dis));
    dis[src]=fa[src]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=1;
        for(int y:g[x])if(y!=fa[x]){
            fa[y]=x;
            q.emplace(y);
            dis[y]=dis[x]+1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<pair<int,int>> rts;
    int ans=0;
    for(int i=1;i<=n;i++)if(!vis[i]){
        bfs(i);
        int end1=max_element(dis+1,dis+n+1)-dis;
        bfs(end1);
        int end2=max_element(dis+1,dis+n+1)-dis;
        vector<int> chain;
        chain.emplace_back(end2);
        while(chain.back()!=end1)chain.emplace_back(fa[chain.back()]);
        rts.emplace_back(chain.size()/2,chain[chain.size()/2]);
        ans=max(ans,(int)chain.size()-1);
    }
    sort(rts.begin(),rts.end());
    reverse(rts.begin(),rts.end());
    if(rts.size()>1){
        ans=max(ans,rts[0].first+1+rts[1].first);
    }
    if(rts.size()>2){
        ans=max(ans,rts[1].first+rts[2].first+2);
    }
    cout<<ans<<'\n';
    for(int i=1;i<rts.size();i++){
        cout<<rts[i].second<<' '<<rts[0].second<<'\n';
    }

    return 0;
}