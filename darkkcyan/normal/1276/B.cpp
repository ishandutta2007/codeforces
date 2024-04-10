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

struct DSU {
    vector<int> p;
    int cnt;
    DSU(int n) : p(n + 1), cnt(n) {
        rep1(i, n) p[i] = i;
    }

    int find_set(int u) {
        return u == p[u] ? u : p[u] = find_set(p[u]); 
    }

    void join(int u, int v) {
        if (rand() & 1) swap(u, v);
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        --cnt;
        p[u] = v;
    }
};

#define maxn 201010
int n, m, a, b;
vector<int> gr[maxn];

bool is_cut_point(int s) {
    DSU dsu(n);
    rep1(u, n) {
        if (u == s) continue;
        for (auto v: gr[u]) {
            if (v == s) continue;
            dsu.join(u, v);
        }
    }
    return dsu.cnt > 1;
}

bool vis_by_a[maxn];
bool vis_by_b[maxn];
void dfs(int u, int stop, bool* vis) {
    vis[u] = 1;
    if (u == stop) return ;

    for (auto v: gr[u]) {
        if (vis[v]) continue;
        dfs(v, stop, vis);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> m >> a >> b;
        rep1(i, n) gr[i].clear();
        rep(i, m) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        if (!is_cut_point(a) or !is_cut_point(b)) {
            cout << "0\n";
            continue;
        }
        rep1(i, n) {
            vis_by_a[i] = vis_by_b[i] = 0;
        }
        dfs(b, a, vis_by_b);
        dfs(a, b, vis_by_a);
        int cnt_a = 0, cnt_b = 0;
        rep1(i, n) {
            if (vis_by_a[i] and vis_by_b[i]) continue;
            if (vis_by_a[i]) cnt_a++;
            if (vis_by_b[i]) cnt_b++;
        }
        cout << 1ll * cnt_a * cnt_b << '\n';
    }

    return 0;
}