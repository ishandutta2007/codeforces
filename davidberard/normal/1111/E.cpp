#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
const int LG = 17;
const ll MOD = 1e9+7;

int par[N][LG];
int in[N], out[N];
int et=0;
vector<int> adj[N];
int h[N];
int g[N];
ll dp[303][N];
int n, q;
int k, m, r;

void dfs(int u, int p, int d) {
    par[u][0] = p;
    h[u] = d;
    in[u] = et++;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
    out[u] = et++;
}

void setup() {
    for (int l=0; l<LG-1; ++l) {
        for (int i=1; i<=n; ++i) {
            par[i][l+1] = par[par[i][l]][l];
        }
    }
}

int geth(int x, int h) {
    for (int i=0; h; i++, h/=2) {
        if (h&1) {
            x = par[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (h[x] > h[y]) swap(x, y);
    y = geth(y, h[y]-h[x]);

    for (int l=LG-1; l>=0; --l) {
        if (par[x][l] != par[y][l]) {
            x = par[x][l];
            y = par[y][l];
        }
    }
    if (x != y) {
        x = par[x][0];
        y = par[y][0];
        assert(x == y);
    }
    return x;
}

struct segtree {
    vector<int> t;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, 0);
    }
    void assign(int x, int v) {
        x+=n;
        t[x] = v;
        for(x/=2; x; x/=2) {
            t[x] = t[x<<1]+t[x<<1|1];
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) ans += t[l++];
            if (r%2) ans += t[--r];
        }
        return ans;
    }
};

segtree st;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    setup();
    st = segtree(n*2+10);

    dp[0][0] = 1;
    
    while (q--) {
        cin >> k >> m >> r;
        vector<pii> vv;
        for (int i=1; i<=k; ++i)  {
            int b;
            cin >> b;
            int anc = lca(r, b);
            vv.emplace_back(h[r] + h[b] - 2*h[anc], b);
            st.assign(in[b], 1);
            st.assign(out[b], -1);
        }
        sort(vv.begin(), vv.end());
        for (int i=0; i<k; ++i) {
            int b = vv[i].second;
            int anc = lca(r, b);
            g[i+1] = st.query(in[anc]+1, in[r]+1) + st.query(in[anc], in[b]);
        }
        for (int i=0; i<k; ++i) {
            int b = vv[i].second;
            st.assign(in[b], 0);
            st.assign(out[b], 0);
        }

        ll ans = 0;
        for (int j=1; j<=m; ++j) {
            for (int i=1; i<=k; ++i) {
                dp[j][i] = dp[j-1][i-1] + dp[j][i-1]*(j-g[i]);
                dp[j][i] %= MOD;
            }
            ans += dp[j][k];
        }
        ans %= MOD;
        cout << ans << "\n";
    }

    return 0;
}