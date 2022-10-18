#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n,m;
vector<int> adj[maxn];
bool vis[maxn];

int dfs(int u){
    int c=1;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            c+=dfs(v);
        }
    }
    return c;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;    
    int ans=m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int q=dfs(i);
            ans-=(q-1);
        }
    }
    cout<<ans;
    return 0;
}