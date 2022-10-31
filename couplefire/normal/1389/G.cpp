#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int n, m, k, curtime = 0;
vector<pair<int, int>> adj[MAXN];
int w[MAXN];
int c[MAXN];
bool bridge[MAXN];
bool visited[MAXN];
int tin[MAXN];
int low[MAXN];
bool speical[MAXN];
int curComp = 0;
long long compCost[MAXN];
int comp[MAXN];
vector<pair<int, int>> tree[MAXN];
long long dp[MAXN];
long long root[MAXN];
bool has_special[MAXN];
int cnt[MAXN];

void tarjan(int v, int p){
    visited[v] = 1;
    tin[v] = curtime++;
    low[v] = curtime;
    for(auto x : adj[v]){
        int u = x.first, i = x.second;
        if(u == p) continue;
        if(visited[u]){
            low[v] = min(low[v], tin[u]);
        }
        else{
            tarjan(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > tin[v]){
                bridge[i] = 1;
            }
        }
    }
}

void getComps(int v){
    visited[v] = 1;
    comp[v] = curComp;
    compCost[curComp] += c[v];
    for(auto x : adj[v]){
        int u = x.first;
        int i = x.second;
        if(bridge[i]){
            if(visited[u]){
                tree[comp[v]].push_back({comp[u], i});
                tree[comp[u]].push_back({comp[v], i});
            }
            continue;
        }
        if(visited[u]) continue;
        getComps(u);
    }
}

void init(){
    fill(tin, tin+MAXN, -1);
    fill(low, low+MAXN, -1);
    for(int i = 0; i<n; i++){
        if(!visited[i]) tarjan(i, -1);
    }
    fill(visited, visited+n, 0);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            getComps(i);
            curComp++;
        }
    }
}

void getCnt(int v, int p = -1){
    cnt[v] = has_special[v];
    for(auto x : tree[v]){
        int u = x.first, i = x.second;
        if(u == p) continue;
        getCnt(u, v);
        cnt[v] += cnt[u];
    }
}

void solve(int v, int p = -1){
    dp[v] = compCost[v];
    for(auto x : tree[v]){
        int u = x.first, i = x.second;
        if(u == p) continue;
        solve(u, v);
        if(cnt[u] && (k-cnt[u])) dp[v] += max(0ll, dp[u]-1ll*w[i]);
        else dp[v] += dp[u];
    }
}

void reRoot(int v, int p = -1, int i = -1){
    // cout << v << endl;
    if(v == 0){
        root[0] = dp[0];
    }
    else{
        long long trans;
        if(cnt[v] && (k-cnt[v])) trans = root[p]-max(0ll, dp[v]-1ll*w[i]);
        else trans = root[p] - dp[v];
        if((k-cnt[v]) && cnt[v]) root[v] += max(0ll, trans-1ll*w[i]);
        else root[v] += trans;
        root[v] += compCost[v];
        for(auto x:tree[v]){
            int u = x.first, j = x.second;
            if(u == p) continue;
            if(cnt[u] && (k-cnt[u])) root[v] += max(0ll, dp[u]-1ll*w[j]);
            else root[v] += dp[u];
        }
    }
    for(auto x : tree[v]){
        int u = x.first, j = x.second;
        if(u == p) continue;
        reRoot(u, v, j);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i<k; i++){
        int a; cin >> a; --a;
        speical[a] = 1;
    }
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }
    for(int i = 0; i<m; i++) cin >> w[i];
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    init();
    for(int i = 0; i<n; i++){
        has_special[comp[i]] |= speical[i];
    }
    k = 0;
    for(int i = 0; i<n; i++) k += has_special[i];
    // for(int i = 0; i<n; i++) cout << compCost[i] << " ";
    // cout << endl;
    // cout << dp[3] << endl;
    getCnt(0);
    solve(0);
    reRoot(0);
    // cout << dp[2] << endl;
    for(int i = 0; i<n; i++){
        cout << root[comp[i]] << endl;
    }
}