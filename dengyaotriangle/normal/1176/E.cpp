#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,m;
vector<int> adj[maxn];
int sel[maxn];

void dfs(int u){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(sel[v]==-1){
            sel[v]=!sel[u];
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            sel[i]=-1;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sel[1]=1;
        dfs(1);
        int c1=0;
        for(int i=1;i<=n;i++) if(sel[i]==1) c1++;
        if(c1<=(n/2)){
            cout<<c1<<'\n';
            for(int i=1;i<=n;i++) if(sel[i]==1) cout<<i<<' ';
            cout<<'\n';
        }else{
            cout<<n-c1<<'\n';
            for(int i=1;i<=n;i++) if(sel[i]==0) cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}