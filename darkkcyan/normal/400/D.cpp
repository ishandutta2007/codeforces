#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, m, k;
vi group, c;
ve<vi> gr;
ve<bool> vis;

vi pp;
ve<map<int, int> > cnt;
int findp(int u) {
    if (u == pp[u]) return u;
    return pp[u] = findp(pp[u]);
}

void join(int u, int v) {
    u = findp(u), v = findp(v);
    if (u == v) return;
    if (sz(cnt[u]) > sz(cnt[v])) swap(u, v);
    pp[u] = v;
    for (map<int, int>::iterator it = cnt[u].bb; it != cnt[u].ee; ++it)
        cnt[v][it->xx] += it->yy;
    cnt[u].clear();
}

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    cin >> n >> m >> k;
    c.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        for (int f = 0; f < c[i]; ++f) group.push_back(i);
    }

    gr.resize(k, vi(k, inf(int)));
    pp.resize(n);
    cnt.resize(n);
    for (int i = 0; i < n; ++i) pp[i] = i, cnt[i][group[i]] = 1;


    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c; --u, --v;
        if (c == 0) join(u, v);
        u = group[u], v = group[v];
        if (c != 0 or u != v)
            gr[u][v] = gr[v][u] = min(gr[u][v], c);
    }

    vis.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        int u = findp(i);
        if (vis[u]) continue;
        vis[u] = true;
        for (map<int, int>::iterator it = cnt[u].bb; it != cnt[u].ee; ++it) {
            if (c[it->xx] != it->yy) cout << "No", exit(0);
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < k; ++i) gr[i][i] = 0;

    for (int mid = 0; mid < k; ++mid)
    for (int l = 0; l < k; ++ l)
    for (int r = 0; r < k; ++ r) {
        if (gr[l][mid] == inf(int) or gr[mid][r] == inf(int)) continue;
        gr[l][r] = min(gr[l][r], gr[l][mid] + gr[mid][r]);
    }

    for (int i = 0; i < k; ++i) {
        for (int f = 0; f < k; ++f)
            cout << (gr[i][f] == inf(int) ? -1 : gr[i][f]) << ' ';
        cout << '\n';
    }

    return 0;
}