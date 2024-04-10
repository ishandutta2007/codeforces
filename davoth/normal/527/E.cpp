#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int n,m;
vector<pair<int,int> > adj[N],ans;
bool flag[2*N],c=0;
void dfs(int v) {
    while(!adj[v].empty()){
        auto p=adj[v].back();
        int u=p.F,id=p.S;
        adj[v].pop_back();
        if(flag[id]) continue;
        flag[id]=true;
        dfs(u);
        if(c) ans.emplace_back(v,u),c=!c;
        else ans.emplace_back(u,v),c=!c;
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int v,u;
        cin >> v >> u;
        adj[v].emplace_back(u,i);
        adj[u].emplace_back(v,i);
    }
    vector<int> odds;
    for(int i=1; i<=n; i++){
        if(adj[i].size()&1) odds.push_back(i);
    }
    for(int i=0; i<odds.size(); i+=2){
        int v=odds[i],u=odds[i+1];
        adj[v].emplace_back(u,m);
        adj[u].emplace_back(v,m++);
    }
    if(m&1){
        adj[1].emplace_back(1,m);
        adj[1].emplace_back(1,m);
    }
    for(int i=1; i<=n; i++) if(!adj[i].empty()) dfs(i);
    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.F << ' ' << p.S << '\n';
    return 0;
}