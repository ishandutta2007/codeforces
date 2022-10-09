#include <bits/stdc++.h>
using namespace std;

#define maxn 101010
#define llong long long 
int n, m;
map<int, llong> gr[maxn];
int par[maxn];
llong dis[maxn];

int main() {
    cin >> n >> m;
    for (int i = m; i--; ) {
        int u, v; llong w;
        cin >> u >> v >> w;
        if (!gr[u].count(v) or gr[u][v] > w)
            gr[u][v] = gr[v][u] = w;
    }
    
    set<pair<llong, int>> se;
    for (int i = 0; i ++ < n; ) {
        dis[i] = LLONG_MAX;
        se.insert({dis[i], i});
    }
    auto upd = [&](int u, llong new_dis) {
        if (new_dis >= dis[u]) return false;
        if (!se.count({dis[u], u})) return false;
        se.erase({dis[u], u});
        dis[u] = new_dis;
        se.insert({dis[u], u});
        return true;
    };
    
    upd(n, 0);
    par[n] = -1;
    while (se.size()) {
        int u = se.begin()->second;
        if (dis[u]== LLONG_MAX) break;
        se.erase(se.begin());
        for (auto [v, td]: gr[u]) {
            llong nd = dis[u] + td;
            if (upd(v,  nd)) par[v] = u;
        }
    }
    if (dis[1] == LLONG_MAX) cout << -1;
    else {
        for (int i = 1; i != -1; i = par[i]) cout << i << ' ';
    }
}