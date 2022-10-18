#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,m;
vector<int> adj[maxn];
int lbl[maxn];
bool ti=0;
int t[maxn];

void dfs(int u){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(lbl[v]==-1){
            lbl[v]=!lbl[u];
            dfs(v);
        }else if(lbl[v]==lbl[u]){
            ti=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        t[i]=u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(lbl,-1,sizeof(lbl));
    lbl[1]=1;
    dfs(1);
    if(ti){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for(int i=1;i<=m;i++) cout<<lbl[t[i]];
    return 0;
}