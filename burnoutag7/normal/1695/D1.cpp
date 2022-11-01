#include<bits/stdc++.h>
using namespace std;

int n,f[200005];
vector<int> g[200005];

void dfs(int x,int p){
    f[x]=0;
    int c=0;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        f[x]+=f[y];
        c+=!f[y];
    }
    f[x]+=c-!!c;
}

void mian(){
    for(int i=1;i<=n;i++)g[i].clear();
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)if(g[i].size()>2){
        dfs(i,-1);
        cout<<f[i]<<'\n';
        return;
    }
    cout<<(n!=1)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}