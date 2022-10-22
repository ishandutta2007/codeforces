#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, M, K, Q;
vector<pair<signed, int> > v[100010];
vector<pair<signed, int> > p[100010];
struct dsu_ {
    static const int dim = 100010;
    vector<int> p, dd;
    dsu_() {
        p = vector<int>(dim);
        iota(p.begin(), p.end(), 0);
        dd = vector<int>(dim, 1);
    }
    int par(int pos) {
        return p[pos] = p[pos] == pos ? pos : par(p[pos]);
    }
    bool same(int a, int b) {
        return par(a) == par(b);
    }
    void unite(int a, int b) {
        a = par(a);
        b = par(b);
        if (a == b) return;
        if (dd[a] < dd[b]) swap(a, b);
        p[b] = a;
        dd[a] += dd[b];
    }
} dsu;

pair<signed, int> par[20][100010];
signed prof[100010];
void dfs(int pos, int prec, int d, int pp) {
    par[0][pos] = {prec, d};
    prof[pos] = pp;
    for (auto [x, y] : p[pos]) {
        if (x == prec) continue;
        dfs(x, pos, y, pp + 1);
    }
}
int query(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);
    int q = 19;
    int ans = 0;
    while (prof[a] > prof[b]) {
        auto [p, d] = par[q][a];
        if (prof[p] >= prof[b]) {
            a = p;
            ans = max(ans, d);
        }
        q--;
    }
    if (a == b) return ans;
    q = 19;
    while (q >= 0) {
        auto [p, d] = par[q][a];
        auto [p1, d1] = par[q][b];
        if (p != p1) {
            a = p;
            b = p1;
            ans = max(ans, d);
            ans = max(ans, d1);
        }
        q--;
    }
    ans = max(ans, par[0][a].se);
    ans = max(ans, par[0][b].se);
    return ans;
}
vector<pair<int, signed> > vis[100010];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > q;
    for (int i = 1; i <= K; i++) q.push({0, i, i});
    vector<array<int, 3> > archi;
    while (!q.empty()) {
        auto [d, pos, start] = q.top();
        q.pop();
        // cout << d << " " << pos << " " << start << endl;
        if (vis[pos].size()) {
            sort(vis[pos].begin(), vis[pos].end());
            for (auto [dd, o] : vis[pos]) {
                archi.pb({dd + d, o, start});
                // if (dsu.same(o, start)) continue;
                // dsu.unite(o, start);
                // p[o].pb({start, d + dd});
                // p[start].pb({o, d + dd});
                // cout << "arco: " << o << " " << start << " " << d + dd << endl;
            }
            vis[pos].pb({d, start});
            sort(vis[pos].begin(), vis[pos].end());
            vis[pos].resize(1);
            continue;
        }
        vis[pos].pb({d, start});
        /*if (pos <= K && start != pos) {
            dsu.unite(pos, start);
            p[pos].pb({start, d});
            p[start].pb({pos, d});
            cout << "arco: " << pos << " " << start << " " << d << endl;
        }*/
        for (auto [a, b] : v[pos]) {
            q.push({d + b, a, start});
        }
    }
    sort(archi.begin(), archi.end());
    for (auto [d, a, b] : archi) {
        if (dsu.same(a, b)) continue;
        dsu.unite(a, b);
        p[a].pb({b, d});
        p[b].pb({a, d});
    }
    dfs(1, 0, 0, 1);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j <= K; j++) {
            par[i][j] = {par[i - 1][par[i - 1][j].fi].fi, max(par[i - 1][par[i - 1][j].fi].se, par[i - 1][j].se)};
        }
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << '\n';
        // cout << "ok" << endl;
    }
}