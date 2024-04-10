// Author: Tran Quang Loc (darkkcyan)
// Problem: https://codeforces.com/problemset/problem/342/E
#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

template<class Graph, int node_start_id = 1>
struct centroid_decomposer {
    int n;
    const Graph& gr;
    vector<bool> mark;
    vector<int> child_cnt;

    centroid_decomposer(int n_, const Graph& gr_)
        : n(n_ + node_start_id), gr(gr_), mark(n), child_cnt(n) {}

    int dfs_count_child(int u, int p) {
        child_cnt[u] = 1;
        for (auto v: gr[u]) if (v != p and !mark[v])
            child_cnt[u] += dfs_count_child(v, u);
        return child_cnt[u];
    }

    // possible modification: return a pair which contain a new centroid and
    // the size of its region (the `total` variable)
    int find_centroid(int u, int p = -1, int total = -1) {
        assert(u != -1);
        if (p == -1) total = dfs_count_child(u, u);
        pair<int, int> big_child(total - child_cnt[u], -1);
        for (auto v: gr[u]) if (!mark[v] and v != p)
            big_child = max(big_child, {child_cnt[v], v});
        if (big_child.first > total / 2) 
            return find_centroid(big_child.second, u, total);
        mark[u] = 1;
        return u;
    }

    // possible modification: return adjacency list instead of parent list
    vector<int> build_centroid_tree(int s = node_start_id) {
        s = find_centroid(s);
        vector<int> cen_parent(n, -1);
        queue<int> qu;
        for (qu.push(s), cen_parent[s] = s; qu.size(); qu.pop()) {
            int u = qu.front();
            for (auto v: gr[u]) {
                if (mark[v]) continue;
                int cv = find_centroid(v);
                cen_parent[cv] = u;
                qu.push(cv);
            }
        }
        return cen_parent;
    }
};

#define clog if (0) cout

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
#define maxlogn 18
#define inf (maxn + 100)
int n;
vector<int> gr[maxn];
int depth[maxn], lift[maxlogn][maxn];
void dfs(int u, int p) {
    lift[0][u] = p;
    depth[u] = depth[p] + 1;
    rep(i, maxlogn - 1)
        lift[i + 1][u] = lift[i][lift[i][u]];
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int dist(int u, int v) {
    int ans = 0;
    if (depth[u] < depth[v]) swap(u, v);
    ans += depth[u] - depth[v];
    for (int d = ans, i = 0; d > 0; d >>= 1, ++i) 
        if (d & 1) u = lift[i][u];
    if (u == v) return ans;
    for (int i = maxlogn; i--; ) {
        if (lift[i][u] == lift[i][v]) continue;
        ans += 1 << (i + 1);
        u = lift[i][u];
        v = lift[i][v];
    }
    ans += 2;
    return ans;
}

vector<int> cen_parent;
pair<int, int> cen_closest[maxn];
void upd(int u, int node) {
    clog << __func__ << endl;
    cen_closest[u] = min(cen_closest[u], {dist(u, node), node});
    clog << u << ' ' << cen_closest[u].xx << ' ' << dist(u, node) << endl;
    if (cen_parent[u] != u) upd(cen_parent[u], node);
}

int get_closest(int u) {
    clog << __func__ << endl;
    clog << u << endl;
    pair<int, int> ans(inf, -1);
    for (int c = u; ; c = cen_parent[c]) {
        int v = cen_closest[c].yy;
        clog << c << ' ' << v << endl;
        if (v != -1)
            ans = min(ans, {dist(u, v), v});
        if (c == cen_parent[c]) break;
    }
    return ans.xx;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; 
    cin >> n >> q;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, 1);
    cen_parent = centroid_decomposer(n, gr).build_centroid_tree();
    rep1(i, n) cen_closest[i] = {inf, -1};
    upd(1, 1);
    while (q--) {
        int type, u; cin >> type >> u;
        if (type == 1) upd(u, u);
        else cout << get_closest(u)<< '\n';
    }

    return 0;
}