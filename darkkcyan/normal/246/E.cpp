#include <bits/stdc++.h>
using namespace std;

const int maxn = 101010;

struct Query {
    int k, id;
};

int n, m;
string name[maxn];
vector<int> gr[maxn];
vector<Query> qr[maxn];

int d[maxn], subcnt[maxn];
void dfs1(int u, int p) {
    d[u] = d[p] + 1;
    subcnt[u] = 1;
    for (auto& v: gr[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subcnt[u] += subcnt[v];
        if (gr[u][0] == p or subcnt[gr[u][0]] < subcnt[v])
            swap(gr[u][0], v);
    }
}

map<string, int> cnt[maxn];
void upd(int u, int p, int delta) {
    auto& it = cnt[d[u]][name[u]];
    it += delta;
    if (it == 0) cnt[d[u]].erase(name[u]);
    for (auto v: gr[u]) {
        if (v == p) continue;
        upd(v, u, delta);
    }
} 

int ans[maxn];
void cal_ans(int u, int p) {
    for (auto v: gr[u]) {
        if (v == gr[u][0]) continue;
        cal_ans(v, u);
        upd(v, u, -1);
    }
    if (gr[u].size()) cal_ans(gr[u][0], u);
    cnt[d[u]][name[u]] ++;
    for (auto v: gr[u]) {
        if (v == gr[u][0] or v == p) continue;
        upd(v, u, 1);
    }
    for (auto [k, id]: qr[u]) {
        k += d[u];
        if (k >= maxn) continue;
        ans[id] = (int)cnt[k].size();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> name[i];
        int p;
        cin >> p;
        gr[p].push_back(i);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, k;
        cin >> u >> k;
        qr[u].push_back({k, i});
    }
    dfs1(0, 0);
    cal_ans(0, 0);
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
    
    return 0;
}