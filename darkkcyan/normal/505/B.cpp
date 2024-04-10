#include <bits/stdc++.h>

using namespace std;

#define fn "main"
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
#define vi ve<int>
#define ii pair<int, int>

struct dsu {
    vi pp;
    void resize(int n) { pp.resize(n); while (n--) pp[n] = n; }
    int findp(int u) { return pp[u] = (pp[u] == u) ? u : findp(pp[u]); }
    void join(int u, int v) { pp[findp(u)] = findp(v); }
};

int n, m;
vector<dsu> ss;
void read() {
    scanf("%d%d", &n, &m);
    dsu t; t.resize(n);
    ss.assign(m, t);
    for (int i = 0; i < m; ++i) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        --u, --v, --c;
        ss[c].join(u, v);
    }
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        --u, --v;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += ss[i].findp(u) == ss[i].findp(v);
        }
        printf("%d\n", ans);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    solve();

    return 0;
}