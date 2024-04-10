#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

bool g[maxn];
vector<int> adj[maxn];
int n,m;
int x[maxn],p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++) p[x[i]]=i;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[p[u]].push_back(p[v]);
    }
    g[n]=1;
    int ans=1;
    for(int i=n-1;i>=1;i--){
        int cnt=0;
        for(int j=0;j<adj[i].size();j++){
            int v=adj[i][j];
            if(g[v]) cnt++;
        }
        if(cnt<ans){
            g[i]=1;
            ans++;
        }
    }
    cout<<n-ans;
    return 0;
}