#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MOD 1000000007
long long n, l;
long long dpsum[MAXN] = {0}, dpsquare[MAXN] = {0}, totalsquare[MAXN] = {0}, totalsum[MAXN] = {0}, dpsize[MAXN] = {0};
map<pair<long long, long long>, long long> edgesquare, edgesum, edgesize;
vector<pair<long long, long long>> adj[MAXN];
long long parent[MAXN];

void dfs1(long long v = 0, long long p = -1){
    parent[v] = p;
    for(auto u : adj[v]) if(u.first != p) dfs1(u.first, v);
    dpsize[v] = 1;
    for(auto u : adj[v]){
        dpsize[v] += dpsize[u.first];
        dpsize[v] %= MOD;
        dpsum[v] += dpsum[u.first]+dpsize[u.first]*u.second;
        dpsum[v] %= MOD;
        dpsquare[v] += dpsquare[u.first]+2*(u.second*dpsum[u.first]%MOD)+(u.second*u.second%MOD)*(dpsize[u.first])%MOD;
        dpsquare[v] %= MOD;
        edgesquare[{v, u.first}] = dpsquare[u.first];
        edgesum[{v, u.first}] = dpsum[u.first];
        edgesize[{v, u.first}] = dpsize[u.first];
    }
}

void reroot(long long v = 0, long long p = -1, long long w = 0){
    if(p == -1){
        totalsquare[v] = dpsquare[v];
        totalsum[v] = dpsum[v];
        for(auto u : adj[v]) reroot(u.first, v, u.second);
        return;
    }

    edgesize[{v, p}] = n-edgesize[{p, v}];
    edgesum[{v, p}] = totalsum[p]-dpsize[v]*w-dpsum[v];
    edgesum[{v, p}] %= MOD;
    totalsum[v] = edgesum[{v, p}]+edgesize[{v, p}]*w+dpsum[v];
    totalsum[v] %= MOD;
    edgesquare[{v, p}] = totalsquare[p]-dpsquare[v]-(w*w%MOD)*dpsize[v]%MOD-2*w*dpsum[v]%MOD;
    edgesquare[{v, p}] %= MOD;
    totalsquare[v] = edgesquare[{v, p}]+dpsquare[v]+(w*w%MOD)*edgesize[{v, p}]%MOD+2*(w*edgesum[{v, p}]%MOD);
    totalsquare[v] %= MOD;
    for(auto u : adj[v]) if(u.first != p) reroot(u.first, v, u.second);

}

long long dp[MAXN] = {0};

long long timer;
long long tin[MAXN], tout[MAXN];
vector<vector<long long>> up;

void dfs(long long v, long long p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (long long i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : adj[v]) {
        if (u .first!= p){
            dp[u.first] = dp[v]+u.second;
            dp[u.first] %= MOD;
            dfs(u.first, v);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(long long u, long long v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

long long lca(long long u, long long v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (long long i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess() {
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<long long>(l + 1));
    dfs(0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(long long i = 0; i<n-1; i++){
        long long a, b, c; cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    preprocess();
    dfs1(); reroot();
    long long q; cin >> q;
    while(q--){
        long long a, b; cin >> a >> b;
        --a; --b;
        if(lca(a, b) != b){
            cout << ((-totalsquare[a]+2*dpsquare[b]+2*dpsize[b]*((dp[a]+dp[b]-2*dp[lca(a, b)])*(dp[a]+dp[b]-2*dp[lca(a, b)])%MOD)+4*((dp[a]+dp[b]-2*dp[lca(a, b)])*dpsum[b]%MOD))%MOD+MOD)%MOD << endl;
        }
        else{
            if(b == 0){
                cout << (totalsquare[a]+MOD)%MOD << endl;
            }
            else{
                long long dist = dp[a]-dp[parent[b]];
                cout << ((totalsquare[a]-2*edgesquare[{b, parent[b]}]%MOD-2*edgesize[{b, parent[b]}]*(dist*dist%MOD)-4*dist*edgesum[{b, parent[b]}]%MOD)%MOD+MOD)%MOD << endl;
            }
        }
    }
}