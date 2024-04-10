#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, l = 18;
vector<int> g[N];
vector<pair<int, int>> gc[N];
int timer = 0;
int tin[N], tout[N];
int up[N][19];
int h[N], tr[N], ans[N];
const int  INF = 1 << 30;
using ll = long long;
using Tp = tuple<int, int, int>;
using pp = pair<Tp, int>;
Tp dd[N];
 
void dfs(int v, int p) {
    if (p == v) h[v] = 0;
    else h[v] = h[p] + 1;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for (auto& u : g[v]) if (u != p) dfs(u, v);
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
 
int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) dd[i] = Tp(INF, INF, INF);
    dfs(1, 1);
    int q; cin >> q;
    auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };
    while(q--) {
        int k, m; cin >> k >> m;
        vector<int> vir(k), spd(k);
        for (int i = 0; i < k; ++i) cin >> vir[i] >> spd[i];
        vector<int> imp(m);
        for (int i = 0; i < m; ++i) cin >> imp[i];
 
        // compress tree
        vector<int> mrg = vir;
        mrg.insert(mrg.end(), imp.begin(), imp.end());
        sort(mrg.begin(), mrg.end(), cmp);
        mrg.erase(unique(mrg.begin(), mrg.end()), mrg.end());
 
        int x = mrg.size();
        for (int i = 0; i < x - 1; ++i) {
            mrg.emplace_back(lca(mrg[i], mrg[i + 1]));
        }
        sort(mrg.begin(), mrg.end(), cmp);
        mrg.erase(unique(mrg.begin(), mrg.end()), mrg.end());
 
        x = mrg.size();
        //restore edge
        vector<int> st { mrg.front() };
        for (int i = 1; i < x; ++i) {
            while (!st.empty() && !is_ancestor(st.back(), mrg[i])) st.pop_back();
            auto a = st.back(); auto b = mrg[i];
            auto l = dist(a, b);
            gc[a].emplace_back(b, l);
            gc[b].emplace_back(a, l);
            st.emplace_back(mrg[i]);
        }
 
        priority_queue<pp, vector<pp>, greater<pp>> qu;
 
        for(int i = 0; i < k; i++){
            auto t = Tp(0, i, 0);
            dd[vir[i]] = t;
            qu.emplace(move(t), vir[i]);
        }
        while(!qu.empty()) {
            auto [nxt, city]  = qu.top(); qu.pop();
            if (dd[city] !=  nxt) continue;
            auto &[rnd, idx, len] = nxt;
            for (auto &v : gc[city]) {
                auto nxt_dist = len + v.second;
                auto t = Tp((nxt_dist + spd[idx] - 1) / spd[idx], idx, nxt_dist);
                if (dd[v.first] > t) {
                    dd[v.first] = t;
                    qu.emplace(move(t), v.first);
 
                }
            }
        }
        for (auto &v : imp) {
            cout << get<1>(dd[v]) + 1  << ' ';
        }
        cout << '\n';
        for (auto &a : mrg) {
            dd[a] = Tp(INF, INF, INF);
            gc[a].clear();
        }
 
 
    }
}