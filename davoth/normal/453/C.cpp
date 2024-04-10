#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int n,m,X[N];
bool mark[N],cnt[N];
vector<int> adj[N],path;
void dfs(int v, int par) {
    mark[v]=true;
    cnt[v]=!cnt[v];
    path.push_back(v);
    for(int u : adj[v]){
        if(mark[u]) continue;
        dfs(u,v);
    }
    if(cnt[v]!=X[v]){
        if(par==0) path.pop_back();
        else{
            path.push_back(par);
            path.push_back(v);
        }
        cnt[par]=!cnt[par];
        cnt[v]=!cnt[v];
    }
    path.push_back(par);
    cnt[par]=!cnt[par];
}

int main() {
    fast_io;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int lst=-1;
    for(int i=1; i<=n; i++){
        cin >> X[i];
        if(X[i] && lst==-1) lst=i;
    }
    if(lst==-1) return cout << 0,0;
    dfs(lst,0);
    if(path.size() && path[path.size()-1]==0) path.pop_back();
    for(int i=1; i<=n; i++) if(X[i]!=cnt[i]) return cout<<-1,0;
    cout << path.size() << '\n';
    for(int i : path) cout << i << ' ';
    return 0;
}