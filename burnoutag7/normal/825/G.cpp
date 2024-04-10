#include<bits/stdc++.h>
using namespace std;

int n,q,root,mn,fa[1000005],val[1000005];
vector<int> g[1000005];
bool vis[1000005];

void dfs(int x,int p){
    fa[x]=p;
    val[x]=x;
    if(p!=-1)val[x]=min(val[x],val[p]);
    for(int &y:g[x])if(y!=p)dfs(y,x);
}

void upd(int x){
    while(!vis[x]){
        mn=min(mn,x);
        vis[x]=1;
        x=fa[x];
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    q--;
    cin>>root>>root;
    root=root%n+1;
    dfs(root,-1);
    mn=root;
    vis[root]=1;
    while(q--){
        int t,x;
        static int last;
        cin>>t>>x;
        x=(x+last)%n+1;
        if(t==1)upd(x);
        else cout<<(last=min(mn,val[x]))<<'\n';
    }

    return 0;
}