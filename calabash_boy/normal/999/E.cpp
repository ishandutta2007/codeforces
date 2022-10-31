#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int ans=0;
vector<int> e[maxn], G[maxn];
int vis[maxn];
int n, m, s;
int dfn[maxn], low[maxn], No[maxn], scc, clk;
stack<int> st;
int deg[maxn];
void dfs1(int u) {
    vis[u] = 1;
    for(int v:G[u]) {
        if(vis[v])continue;
        dfs1(v);
    }
}
void tarjan(int u) {
    st.push(u);
    dfn[u] = low[u] = ++clk;
    for (auto &v: e[u]) {
        if (vis[u])continue;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!No[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc++;
        while (true){
            int x = st.top();
            st.pop();
            No[x]=scc;
            if(x==u){
                break;
            }
        }
    }
}
void solve() {
    dfs1(s);
    for(int i = 1; i <= n; ++i) {
        if (vis[i])continue;
        for (int v: G[i]) {
            if(vis[v])continue;
            e[i].push_back(v);
        }
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]&&!dfn[i])
            tarjan(i);
    }
    for(int i=1;i<=n;++i) {
        if(vis[i])continue;
        for(int v:e[i]) {
            if(vis[v])continue;
            if(No[i] != No[v]) {
                deg[No[v]]++;
            }
        }
    }
    for(int i=1;i<=scc;++i)
        if(deg[i]==0)ans++;
    
    cout<<ans<<endl;
}
void input(){
    cin >>n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    solve();
    return 0;
}