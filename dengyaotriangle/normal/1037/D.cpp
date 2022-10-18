#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    vector<vector<int> > adj(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    vector<int> dep(n+1),fa(n+1);
    function<void(int,int)> dfs=[&](int u,int f)->void{
        for(int v:adj[u]){
            if(v!=f){
                dep[v]=dep[u]+1;
                fa[v]=u;
                dfs(v,u);
            }
        }
    };
    dfs(1,0);
    vector<vector<int> > se;
    vector<bool> vis(n+1);
    for(int i=1;i<=n;i++){
        int u;cin>>u;
        if(vis[u]){cout<<"No";return 0;}
        vis[u]=1;
        if(dep[u]==(int)se.size()){
            se.push_back(vector<int>(1));
            se.back().back()=u;
        }else if(dep[u]+1==(int)se.size()){
            se.back().push_back(u);
        }else{cout<<"No";return 0;}
    }
    for(int i=1;i<(int)se.size();i++){
        vector<int> h;
        for(int u:se[i])h.push_back(fa[u]);
        h.erase(unique(h.begin(),h.end()),h.end());
        auto it=se[i-1].begin();
        for(auto v:h){
            while(it!=se[i-1].end()&&*it!=v)it++;
            if(*it!=v){cout<<"No";return 0;}
        }
    }
    cout<<"Yes";
    return 0;
}