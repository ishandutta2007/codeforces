#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 2e5 + 5;
const int N = 2e5 + 5;
struct {
    vector<int> G[N];
    vector<pll> dt[N];
    int n, pa[N], layer[N], sz[N], done[N];
    ll dis[__lg(N) + 1][N];
    void init(int _n) {
        n = _n, layer[0] = -1;
        fill_n(pa + 1, n, 0), fill_n(done + 1, n, 0);
        for (int i = 1; i <= n; i++)
            G[i].clear();
    }
    void add_edge(int a, int b) {
        G[a].pb(b); G[b].pb(a);
    }
    void get_cent(int u, int f, int &mx, int &c, int num) {
        int mxsz = 0;
        sz[u] = 1;
        for (int e : G[u])
            if (!done[e] && e != f) {
                get_cent(e, u, mx, c, num);
                sz[u] += sz[e], mxsz = max(mxsz, sz[e]);
            }
        if (mx > max(mxsz, num - sz[u]))
            mx = max(mxsz, num - sz[u]), c = u;
    }
    void dfs(int u, int f, ll d, int org) {
        dis[layer[org]][u] = d;
        for (int e : G[u])
            if (!done[e] && e != f)
                dfs(e, u, d + 1, org);
    }
    int cut(int u, int f, int num) {
        int mx = 1e9, c = 0, lc;
        get_cent(u, f, mx, c, num);
        done[c] = 1, pa[c] = f, layer[c] = layer[f] + 1;
        for (int e : G[c])
            if (!done[e]) {
                if (sz[e] > sz[c])
                    lc = cut(e, c, num - sz[c]);
                else
                    lc = cut(e, c, sz[e]);
                dfs(e, c, 1, c);
            }
        return done[c] = 0, c;
    }
    void build() { cut(1, 0, n); }
    void add(int x, int val) {
        for (int a = x, ly = layer[a]; a; a = pa[a], --ly) {
            if (dis[ly][x] < val)
                dt[a].pb({val - dis[ly][x] - 1, val});
        }
    }
    void sort_vec() {
        for (int i = 1; i <= n; i++) {
            sort(ALL(dt[i]), greater<pll>());
            vector<pll> res;
            for (auto p : dt[i])
                if (!res.size() || p.Y > res.back().Y)
                    res.pb(p);
            dt[i] = res;
            reverse(ALL(dt[i]));
        }
    }
    int qr(int x) {
        int ans = 0;
        for (int a = x, ly = layer[a]; a; a = pa[a], --ly) {
            auto it = lower_bound(ALL(dt[a]), pll(dis[ly][x], -1));
            if (it != dt[a].end())
                ans = max(ans, (int)it->Y);
        }
        return ans;
    }
} cent_dec;

vector<int> v[MAXn];
int dis[MAXn], dp[MAXn];



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cent_dec.init(n);
    for (int i = 1, a, b; i < n; i++)
        cin >> a >> b, v[a].pb(b), v[b].pb(a), cent_dec.add_edge(a, b);
    for (int i = 1; i <= n; i++)
        dis[i] = -1;
    queue<int> q;
    int nk;
    cin >> nk;
    for (int i = 1, t; i <= nk; i++)
        cin >> t, q.push(t), dis[t] = 0;
    while (SZ(q)) {
        int t = q.front(); q.pop();
        for (auto k : v[t])
            if (dis[k] == -1)
                dis[k] = dis[t] + 1, q.push(k);
    }
    cent_dec.build();
    for (int i = 1; i <= n; i++)
        cent_dec.add(i, dis[i]);
    cent_dec.sort_vec();
    for (int i = 1; i <= n; i++)
        cout << cent_dec.qr(i) << " \n"[i == n];        
}