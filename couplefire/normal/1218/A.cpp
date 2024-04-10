#include <bits/stdc++.h>
using namespace std;

const int N = 15005;

int n, m, ans, stuff[N], bruh[N], siz[N], dp[2][2*N], psum[2*N];
vector<int> adj[N], cyc;
bool inCyc[N], vis[N];
stack<int> st;

void find_cyc(int v, int p){
    if(cyc.size()) return;
    if(vis[v]){
        while(st.top() != v)
            cyc.push_back(st.top()), inCyc[st.top()] = 1, st.pop();
        cyc.push_back(v); inCyc[v] = 1;
        return;
    }
    vis[v] = 1; st.push(v);
    for(auto u : adj[v])
        if(u != p) find_cyc(u, v);
    if(cyc.size()) return;
    st.pop();
}

void dfs1(int v, int p){
    siz[v] = 1;
    for(auto u : adj[v])
        if(u != p && !inCyc[u]){
            dfs1(u, v);
            siz[v] += siz[u];
            stuff[v] += stuff[u];
        }
    stuff[v] += siz[v];
}

void dfs2(int v, int p){
    bruh[v] = n; int tot = 0;
    for(auto u : adj[v])
        if(u != p && !inCyc[u]){
            dfs2(u, v); tot += stuff[u];
        }
    for(auto u : adj[v])
        if(u != p && !inCyc[u]){
            bruh[v] = max(bruh[v], n-siz[u]+bruh[u]-stuff[u]+tot);
        }
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    find_cyc(0, -1); m = cyc.size();
    for(int v : cyc)
        dfs1(v, -1), dfs2(v, -1);
    for(int i = 0; i<m; i++)
        cyc.push_back(cyc[i]);
    psum[0] = siz[cyc[0]];
    for(int i = 1; i<2*m; i++)
        psum[i] = psum[i-1]+siz[cyc[i]];
    for(int i = 0; i<2*m; i++)
        dp[1][i] = bruh[cyc[i]];
    auto get = [&](int i, int j) -> int {
        if(i == 0) return psum[j];
        return psum[j]-psum[i-1];
    };
    for(int len = 2; len<=m; len++){
        int f = len&1;
        memset(dp[f], 0, sizeof dp[f]);
        for(int i = 0; i<2*m-len+1; i++){
            int j = i+len-1;
            dp[f][i] = max(dp[f^1][i]+stuff[cyc[j]], dp[f^1][i+1]+stuff[cyc[i]])+n-get(i, j);
        }
    }
    for(int i = 0; i<m; i++)
        ans = max(ans, dp[m&1][i]);
    cout << ans << endl;
}