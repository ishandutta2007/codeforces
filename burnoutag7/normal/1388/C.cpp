#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[100005];
int p[100005],h[100005],v[100005],sz[100005];

bool dfs(int x,int fa){
    v[x]=0;
    sz[x]=p[x];
    for(int &y:g[x])if(y!=fa){
        if(!dfs(y,x))return false;
        v[x]+=h[y];
        sz[x]+=sz[y];
    }
    if(h[x]>sz[x]||h[x]<-p[x]+v[x]||h[x]+p[x]-v[x]&1)return false;
    return true;
}

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if(dfs(1,-1))cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}