#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 101010
#define maxlgn 18
#define inf ((llong)1e16)
int n, m, k, q;
vector<pair<int, llong>> origin_gr[maxn];
map<pair<int, int>, llong> cen_edges;
vector<pair<int, llong>> cen_gr[maxn];

int dsu[maxn];
int find_set(int u) { return u == dsu[u] ? u : dsu[u] = find_set(dsu[u]); }
void join(int u, int v) {
    if (rand() & 1) swap(u, v);
    dsu[find_set(u)] = find_set(v);
}

pair<int, int> ordered(int u, int v) {
    if (u > v) swap(u, v);
    return {u, v};
}

struct node_info {
    int u, src;
    llong dis;
    node_info(int u_ = 0, int s = 0, llong d = 0): u(u_), src(s), dis(d) {}
};

node_info infos[maxn];

bool operator<(const node_info& lhs, const node_info& rhs) {
    return lhs.dis > rhs.dis;
}

int parent[maxlgn][maxn], depth[maxn] = {0};
llong lift_table[maxlgn][maxn];
void build_bin_lift_table(int u, int p, llong p_dis = 0) {
    parent[0][u] = p;
    depth[u] = depth[p] + 1;
    lift_table[0][u] = p_dis;
    // clog << u << ' ' << p << ' ' << p_dis << endl;
    rep(i, maxlgn - 1) {
        parent[i + 1][u] = parent[i][parent[i][u]];
        lift_table[i + 1][u] = max(lift_table[i][u], lift_table[i][parent[i][u]]);
    }
    for (auto [v, dis]: cen_gr[u]) {
        if (v == p) continue;
        build_bin_lift_table(v, u, dis);
    }
}

llong query(int u, int v) {
    llong ans = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 0, d = depth[u] - depth[v]; d > 0; d >>= 1, ++i) 
        if (d & 1) {
            ans = max(ans, lift_table[i][u]);
            u = parent[i][u];
        }

    if (u == v) return ans;
    for (int i = maxlgn; i--; ) {
        if (parent[i][u] == parent[i][v]) continue;
        ans = max({ans, lift_table[i][u], lift_table[i][v]});
        u = parent[i][u];
        v = parent[i][v];
    }

    ans = max({ans, lift_table[0][u], lift_table[0][v]});
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> q;
    rep(i, m) {
        int u, v, c; cin >> u >> v >> c;
        origin_gr[u].emplace_back(v, c);
        origin_gr[v].emplace_back(u, c);
    }

    priority_queue<node_info> pq;
    for (int i = k + 1; i <= n; ++i) {
        infos[i] = node_info(i, -1, inf);
    }

    rep1(i, k) {
        infos[i] = node_info(i, i, 0);
        pq.push(infos[i]);
    }

    while (len(pq)) {
        int u = pq.top().u, src = pq.top().src;
        llong d = pq.top().dis;
        pq.pop();
        if (d > infos[u].dis) continue;
        infos[u].src = src;
        // clog << "info " << u << ' ' << src << ' ' << d << endl;
        for (auto [v, length]: origin_gr[u]) {
            if (infos[v].src != -1) {
                int su = src, sv = infos[v].src;
                if (su == sv) continue;
                llong old = cen_edges.count(ordered(su, sv)) ? cen_edges[ordered(su, sv)] : inf;
                cen_edges[ordered(su, sv)] = min(old, infos[v].dis + d + length);
                // clog << "upd " << su << ' ' << sv << ' ' << u << ' ' << v<< endl;
                continue;
            }
            llong nd = length + d;
            if (nd >= infos[v].dis) continue;
            infos[v].dis = nd;
            pq.push(node_info(v, src, nd));
        }
    }

    vector<pair<pair<int, int>, llong>> edges(cen_edges.begin(), cen_edges.end());
    // for (auto [nodes, dis]: edges) {
        // clog << nodes.xx << ' ' << nodes.yy << ' ' << dis << endl;
    // }
    sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, llong>& u, const pair<pair<int, int>, llong>& v) {
            return u.yy < v.yy; 
    });

    rep1(i, k) {
        dsu[i] = i;
    }

    for (auto [nodes, dis]: edges) {
        auto [u, v] = nodes;
        if (find_set(u) == find_set(v)) continue;
        join(u, v);
        cen_gr[u].emplace_back(v, dis);
        cen_gr[v].emplace_back(u, dis);
    }

    build_bin_lift_table(1, 1, 0);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << query(u, v) << '\n';
    }

    return 0;
}