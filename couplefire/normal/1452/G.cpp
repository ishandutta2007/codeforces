#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, k;
vector<int> adj[MAXN];
vector<int> bob, stuff;
int siz[MAXN], vis[MAXN], dist[MAXN], ans[MAXN], mxdep;

void bfs(){
    memset(dist, 63, sizeof dist);
    queue<int> q;
    for(auto x : bob) dist[x] = 0, q.push(x);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(dist[v]+1 < dist[u]) dist[u] = dist[v]+1, q.push(u);
        }
    }
}

void dfs(int v, int p){
    siz[v] = 1;
    for(auto u : adj[v]){
        if(vis[u] || u == p) continue;
        dfs(u, v);
        siz[v] += siz[u];
    }
}

int centroid(int v){
    dfs(v, -1);
    int num = siz[v], p = -1;
    do{
        int nxt = -1;
        for(auto u : adj[v]){
            if(u == p || vis[u]) continue;
            if(2*siz[u] > num) nxt = u;
        }
        p = v, v = nxt;
    } while(~v);
    return p;
}

int getdepth(int v, int p, int d){
    int cur = d;
    for(auto u : adj[v]){
        if(vis[u] || u == p) continue;
        cur = max(cur, getdepth(u, v, d+1));
    }
    return cur;
}

void precalc(int v, int p, int d){
    if(dist[v]-d-1 >= 0){
        int tmp = min(dist[v]-d-1, mxdep);
        while((int)stuff.size() <= tmp) stuff.push_back(0);
        stuff[tmp] = max(stuff[tmp], dist[v]);
    }
    for(auto u : adj[v]){
        if(vis[u] || u == p) continue;
        precalc(u, v, d+1);
    }
}

void calc(int v, int p, int d){
    if(d < (int)stuff.size()) ans[v] = max(ans[v], stuff[d]);
    for(auto u : adj[v]){
        if(vis[u] || u == p) continue;
        calc(u, v, d+1);
    }
}

void solve(int v){
    stuff.clear();
    int c = centroid(v);
    mxdep = getdepth(c, -1, 0);
    precalc(c, -1, 0);
    for(int i = (int)stuff.size()-2; i>=0; i--) stuff[i] = max(stuff[i], stuff[i+1]);
    calc(c, -1, 0);
    vis[c] = 1;
    for(auto u : adj[c]){
        if(vis[u]) continue;
        solve(u);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> k; bob.resize(k);
    for(int i = 0; i<k; i++) cin >> bob[i], --bob[i];
    bfs();
    solve(0);
    // cout << dist[0] << endl;
    for(int i = 0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
}