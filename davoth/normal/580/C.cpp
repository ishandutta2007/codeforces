#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m,a[N],ans;
bool f[N];
vector<int> adj[N];
void dfs(int v, int x){
    f[v]=1;
    if(x>m) return;
    if(adj[v].size()==1 && v!=1) ans++;
    for(int u : adj[v]){
        if(f[u]) continue;
        if(a[u]) dfs(u,x+1);
        else dfs(u,0);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++){
        int v,u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1,a[1]);
    cout << ans << '\n';
    return 0;
}