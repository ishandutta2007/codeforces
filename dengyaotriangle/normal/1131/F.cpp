#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=300005;

int n;
vector<int> adj[maxn];
int p[maxn];

int grt(int u){
    if(p[u]==u)return u;
    return p[u]=grt(p[u]);
}
void dfs(int u){
    if(u<=n)cout<<u<<' ';
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n+n;i++)p[i]=i;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        int a=grt(u),b=grt(v);
        p[a]=n+i;
        p[b]=n+i;
        adj[n+i].push_back(a);
        adj[n+i].push_back(b);
    }    
    dfs(n+n-1);
    return 0;
}