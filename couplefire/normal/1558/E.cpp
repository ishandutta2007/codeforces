#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9+7;

int n, m, arr[N], brr[N], par[N];
vector<int> adj[N], path;
bool vis1[N], vis2[N];

void reset(){
    for(int i = 0; i<n; ++i)
        vis1[i] = 0, vis2[i] = 0, adj[i].clear();
    path.clear();
}

bool dfs(int v, int p, bool f, int curpw){
    vis2[v] = 1, par[v] = p;
    if(!f){
        for(auto u : adj[v]){
            if(u==p || vis2[u]) continue;
            if(vis1[u]){if(dfs(u, v, 0, curpw)) return 1;}
            else if(curpw>arr[u]){if(dfs(u, v, 1, min(INF, curpw+brr[u]))) return 1;}
        }
        return 0;
    }
    for(auto u : adj[v]){
        if(u==p) continue;
        if(vis1[u]){
            int x = v;
            while(!vis1[x]) path.push_back(x), vis1[x] = 1, x = par[x];
            return 1;
        }
        if(vis2[u]){
            int x = v, y = u;
            while(!vis1[x]) path.push_back(x), vis1[x] = 1, x = par[x];
            while(!vis1[y]) path.push_back(y), vis1[y] = 1, y = par[y];
            return 1;
        }
        if(curpw>arr[u]) if(dfs(u, v, 1, min(INF, curpw+brr[u]))) return 1;
    }
    return 0;
}

bool check(int val){
    vis1[0] = 1; int curpw = val;
    int cnt = 1;
    while(dfs(0, -1, 0, curpw)){
        for(auto x : path)
            curpw = min(INF, curpw+brr[x]), cnt++;
        for(int i = 0; i<n; ++i)
            vis2[i] = 0;
        path.clear();
    }
    for(int i = 0; i<n; ++i)
        vis1[i] = 0, vis2[i] = 0;
    path.clear();
    return cnt==n;
}

void solve(){
    cin >> n >> m; reset();
    for(int i = 1; i<n; ++i)
        cin >> arr[i];
    for(int i = 1; i<n; ++i)
        cin >> brr[i];
    for(int i = 0; i<m; ++i){
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int lo = 0, hi = INF;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}