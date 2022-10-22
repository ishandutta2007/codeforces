#include <bits\stdc++.h>

using namespace std;
using ll=long long int;

#define S second
#define F first

const int N=2e5+10;

set<ll> adj[N];

vector<ll> ans;

bool flag[N];

void dfs(int v, int par){
    ////for(int i : adj[2]) cout << "&&&&&&&& " << i << endl;
    flag[v]=true;
    set<ll> A;
    for(auto i : adj[v]) A.insert(i);
    for(auto u : A){
        if(!flag[u]){
            //if(u==0) cout << "HERE " << v << endl;
            dfs(u,v);
        }
    }
    //for(int i : adj[2]) cout << "&&&&&&&& " << i << endl;
    //cout << "$$$ " << v << ' ' << par << endl;
    if(par!=-1) adj[v].erase(par);
    while(adj[v].size()>1){
        //cout << "$$$ " << v << ' ' << par << " p" << endl;
        ans.push_back(*adj[v].begin());
        adj[*adj[v].begin()].erase(v);
        adj[v].erase(adj[v].begin());
        ans.push_back(v);
        ans.push_back(*adj[v].begin());
        adj[*adj[v].begin()].erase(v);
        adj[v].erase(adj[v].begin());
    }
    if(adj[v].size() && par!=-1){
        //cout << "$$$ " <<  v << ' ' << par << " k" << endl;
        //if(v==3 && par==2) cout << (adj[3].find(4)!=adj[3].end()) << endl;
        ans.push_back(par);
        adj[par].erase(v);
        ans.push_back(v);
        ans.push_back(*adj[v].begin());
        adj[*adj[v].begin()].erase(v);
        adj[v].erase(adj[v].begin());
    }else if(par>0) adj[v].insert(par);
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    //for(int i : adj[2]) cout << "&&&&&&&& " << i << endl;
    for(int i=1; i<=n; i++){
        if(!flag[i]) dfs(i,-1);
    }
    if(ans.empty()) return cout << 0,0;
    cout << ans.size()/3 << endl;
    for(int i=0; i<ans.size()-2; i+=3){
        cout << ans[i] << ' ' << ans[i+1] << ' ' << ans[i+2] << endl;
    }
    return 0;
}