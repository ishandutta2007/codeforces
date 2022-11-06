#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
const int mod = 1e9 + 7;

void add(int &u, int v) {
    u += v;
    if(u >= mod) u -= mod;
}

int fpow(int x, int y) {
    int risan = 1;
    for(; y > 0; y >>= 1, x = 1LL * x * x % mod) {
        if(y & 1) risan = 1LL * risan * x % mod;
    }
    return risan;
}

int n, t;
int in[N];
int inv[N];
int out[N];
int child[N];
int depth[N];
vector < int > g[N];
pair < int, int > a[N];

long long ans, way, d[N], e[N];


void dfs_prepare(int v, int p) {
    depth[v] = depth[p] + 1;
    in[v] = ++t;
    inv[t] = v;
    child[v] = 1;
    for(int s : g[v]) {
        g[s].erase(find(g[s].begin(), g[s].end(), v));
        dfs_prepare(s, v);
        child[v] += child[s];
    }
    sort(g[v].begin(), g[v].end(), [&](int x, int y){
        return child[x] > child[y];
    });
    out[v] = t;
}

#define mid ((l + r) >> 1)

int T[N << 2];
int S[N << 2];
int lazy[N << 3];
int visit[N << 3];
int lazy_S[N << 3];

void rebuild(int x, int l, int r) {
    visit[x] = 0;
    T[x] = lazy[x] = lazy[x << 1] = lazy[x << 1 | 1] = 0;
    S[x] = lazy_S[x] = lazy_S[x << 1] = lazy_S[x << 1 | 1] = 0;
    if(l == r) return;
    if(visit[x << 1]) rebuild(x << 1, l, mid);
    if(visit[x << 1 | 1]) rebuild(x << 1 | 1, mid + 1, r);
}

void push(int x, int l, int r) {
    add(T[x], 1LL * lazy[x] * (r - l + 1) % mod);
    add(S[x], 1LL * lazy_S[x] * (r - l + 1) % mod);
    if(l != r){
        add(lazy[x << 1], lazy[x]);
        add(lazy[x << 1 | 1], lazy[x]);
        add(lazy_S[x << 1], lazy_S[x]);
        add(lazy_S[x << 1 | 1], lazy_S[x]);
    }
    lazy[x] = 0;
    lazy_S[x] = 0;
}

void update(int x, int l, int r, int u, int v, int valx, int valy) {
    visit[x] = 1;
    push(x, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
        lazy[x] = valx;
        lazy_S[x] = valy;
        return push(x, l, r);
    }
    update(x << 1, l, mid, u, v, valx, valy);
    update(x << 1 | 1, mid + 1, r, u, v, valx, valy);
    T[x] = (T[x << 1] + T[x << 1 | 1]);
    if(T[x] >= mod) T[x] -= mod;
    S[x] = (S[x << 1] + S[x << 1 | 1]);
    if(S[x] >= mod) S[x] -= mod;
}

pair < int, int > query(int x, int l, int r, int u, int v) {
    push(x, l, r);
    if(l > v || r < u) return make_pair(0, 0);
    if(l >= u && r <= v) return make_pair(T[x], S[x]);
    auto p = query(x << 1, l, mid, u, v);
    auto q = query(x << 1 | 1, mid + 1, r, u, v);
    p.first += q.first;
    p.second += q.second;
    if(p.first >= mod) p.first -= mod;
    if(p.second >= mod) p.second -= mod;
    return p;
}

int calc(int l, int r, int h, int hp) {
    auto p = query(1, 1, N - 1, l, r);
    return (1LL * h * p.second - 2LL * hp * p.second + p.first + 1LL * mod * mod) % mod;
}

void dfs_solve(int v, bool keep) {
    for(int i = 1; i < g[v].size(); ++i) {
        dfs_solve(g[v][i], 0);
    }

    if(g[v].size()) dfs_solve(g[v][0], 1);

    ans += 1LL * calc(a[v].first, a[v].second, depth[v], depth[v]) * d[v] % mod;
    ans %= mod;
    update(1, 1, N - 1, a[v].first, a[v].second, e[v] * depth[v] % mod, e[v]);

    for(int i = 1; i < g[v].size(); ++i) {
        int s = g[v][i];
        for(int id = in[s]; id <= out[s]; ++id) {
            int u = inv[id];
            ans += 1LL * d[u] * calc(a[u].first, a[u].second, depth[u], depth[v]) % mod;
            ans %= mod;
        }
        for(int id = in[s]; id <= out[s]; ++id) {
            int u = inv[id];
            update(1, 1, N - 1, a[u].first, a[u].second, e[u] * depth[u] % mod, e[u]);
        }
    }
    if(!keep) rebuild(1, 1, N - 1);

}

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp", "r")) freopen("1.inp", "r", stdin);

    cin >> n;
    way = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        way *= (a[i].second - a[i].first + 1);
        way %= mod;
    }

    for(int i = 1; i <= n; ++i) {
        d[i] = fpow(a[i].second - a[i].first + 1, mod - 2);
        e[i] = way * d[i] % mod;
    }

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = (1LL * rand() * rand() + rand()) % n + 1;

    dfs_prepare(root, 0);
    dfs_solve(root, 1);

    cout << ans << endl;

    return 0;
}