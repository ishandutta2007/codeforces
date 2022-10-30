#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int n, l, q;
vector<pair<int, int>> adj[MAXN];
int depth[MAXN];

int timer;
int tin[MAXN], tout[MAXN];
vector<vector<int>> up;

void dfs(int v, int p, int d = 0)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : adj[v]) {
        if (u .first!= p){
            
            dfs(u.first, v, d+1);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int getAncestor(int v, int num){
    for(int i = l; i>=0; --i){
        if(num >= (1<<i)){
            num -= (1<<i);
            v = up[v][i];
        }
    }
    return v;
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess() {
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(0, 0);
}

long long dp[MAXN];
long long bestParent[MAXN];
long long prefixWeight[MAXN];
long long prefixParent[MAXN];
int parentWeight[MAXN];
int arr[MAXN];
long long newdp[MAXN];

void solveDP(int v, int p){
    for(auto u : adj[v]){
        if(u.first == p) continue;
        parentWeight[u.first] = u.second;
        solveDP(u.first, v);
    }
    dp[v] = arr[v];
    for(auto u : adj[v]){
        dp[v] += max(0ll, dp[u.first]-u.second*2);
    }
    for(auto u : adj[v]){
        bestParent[u.first] = dp[v] - max(0ll,dp[u.first]-u.second*2);
    }
}

void getPrefix(int v, int p, long long curWeight, long long curParent){
    prefixWeight[v] = curWeight;
    if(v != 0) curParent += bestParent[v];
    prefixParent[v] = curParent;
    for(auto u : adj[v]){
        if(u.first == p) continue;
        getPrefix(u.first, v, curWeight+u.second, curParent);
    }
}

void reRoot(int v, int p){
    if(v == 0) newdp[v] = dp[v];
    else{
        newdp[v] += arr[v];
        for(auto u : adj[v]){
            if(u.first == p) continue;
            newdp[v] += max(0ll, dp[u.first]-u.second*2);
        }
    }
    for(auto u : adj[v]){
        if(u.first == p) continue;
        newdp[u.first] = max(0ll, newdp[v] - max(0ll, dp[u.first]-u.second*2)-u.second*2);
        reRoot(u.first, v);
    }
}

void solve(int a, int b){
    int LCA = lca(a, b);
    int dista = depth[a]-depth[LCA];
    int distb = depth[b]-depth[LCA];
    long long ans = 0;
    if(dista != 0) ans += prefixParent[a]-prefixParent[getAncestor(a, dista-1)];
    if(distb != 0) ans += prefixParent[b]-prefixParent[getAncestor(b, distb-1)];
    if(dista != 0) ans += dp[a];
    if(distb != 0) ans += dp[b];
    ans -= prefixWeight[a]-prefixWeight[LCA];
    ans -= prefixWeight[b]-prefixWeight[LCA];
    ans += newdp[LCA];
    if(dista != 0){
        int v = getAncestor(a, dista-1);
        int w = parentWeight[v];
        ans -= max(0ll, dp[v]-2*w);
    }
    if(distb != 0){
        int v = getAncestor(b, distb-1);
        int w = parentWeight[v];
        ans -= max(0ll, dp[v]-2*w);
    }
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
         --a; --b;
         int w; cin >> w;
         adj[a].push_back({b, w});
         adj[b].push_back({a, w});
    }
    preprocess();
    solveDP(0, -1);
    getPrefix(0, -1, 0, 0);
    reRoot(0, -1);
    // cout << newdp[7-1] << endl;
    while(q--){
        int a, b; cin >> a >> b;
        --a; --b;
        solve(a, b);
    }
}