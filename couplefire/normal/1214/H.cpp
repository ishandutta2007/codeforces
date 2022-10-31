#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, k, par[N], dist[N], dep[N], ans[N];
bool onPath[N];
vector<int> adj[N], path;

void dfs(int v, int p){
    par[v] = p;
    for(auto u : adj[v])
        if(u != p) 
            dist[u] = dist[v]+1, dfs(u, v);
}

int genDepth(int v, int p){
    int res = dep[v];
    for(auto u : adj[v])
        if(u != p && !onPath[u])
            dep[u] = dep[v]+1, res = max(res, genDepth(u, v));
    return res;
}

void getAns(int v, int p, int add){
    for(auto u : adj[v])
        if(u != p && !onPath[u])
            ans[u] = ((ans[v]+add)%k+k)%k, getAns(u, v, add);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    {
        dfs(0, -1);
        int v = max_element(dist, dist+n)-dist;
        memset(dist, 0, sizeof dist);
        dfs(v, -1);
        int u = max_element(dist, dist+n)-dist;
        while(u != -1)
            path.push_back(u), onPath[u] = 1, u = par[u];
    }
    m = path.size();
    for(int i = 0; i<m; i++){
        int v = path[i];
        int mxdep = genDepth(v, -1);
        if(mxdep != 0 && m >= k && mxdep+i+1 >= k && mxdep+m-i >= k && k != 2)
            cout << "No" << endl, exit(0);
    }
    cout << "Yes" << endl;
    for(int i = 0; i<m; i++){
        ans[path[i]] = i%k;
        if(i < m/2) getAns(path[i], -1, -1);
        else getAns(path[i], -1, 1);
    }
    for(int i = 0; i<n; i++)
        cout << ans[i]+1 << " ";
    cout << endl;
}