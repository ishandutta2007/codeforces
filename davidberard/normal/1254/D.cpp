#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 150150;
const ll MOD = 998244353;

int sz[N];
int head[N];
int dep[N];
int par[N];
int in[N];
int out[N];
int big[N];
ll ops[N];
vector<int> adj[N];
int n, q;
int ss;

void dfs_sz(int u, int p) {
    in[u] = ss++;
    sz[u]++;
    par[u] = p;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
    out[u] = ss;
}

void dfs_hld(int u, int p, int h) {
    head[u] = h;
    //cerr << " head " << u << " " << head[u] << endl;
    pii best(-1, -1);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        best = max(pii(sz[v], v), best);
    }
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (v == best.second) {
            dfs_hld(v, u, h);
            big[u] = v;
        } else {
            dfs_hld(v, u, v);
        }
    }
}

struct segtree {
    vector<ll> d;
    int n, h;
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        d = vector<ll>(n<<1, 0);
    }
    void add(int l, int r, ll v) {
        for (l += n, r += n; l < r; l/=2, r/=2) {
            if (l%2) {
                d[l] = (d[l]+v)%MOD;
                ++l;
            }
            if (r%2) {
                --r;
                d[r] = (d[r]+v)%MOD;
            }
        }
    }
    ll query(int i) {
        ll ans = 0;
        for (i += n; i; i/=2) {
            ans += d[i];
        }
        return ans%MOD;
    }
};

segtree st(N);

void query_one(int u, int d) {
    st.add(0, n, (ll)d*(sz[u])%MOD);
    st.add(in[u], out[u], (MOD-(ll)d*sz[u]%MOD)%MOD);
    st.add(in[u], in[u]+1, (ll)d*n%MOD);
    ops[u] = (ops[u]+d)%MOD;
    if (big[u]) {
        st.add(in[big[u]], out[big[u]], (ll)d*(n-sz[big[u]])%MOD);
    }
}

ll query_two(int u) {
    ll ans = st.query(in[u]);
    int h = head[u];
    while(h != 1) {
        int p = par[h];
        ans = (ans+(ll)ops[p]*(n-sz[h]))%MOD;
        h = head[p];
    }
    return ans;
}

ll modpow(ll b, ll p) {
    ll ans = 1;
    for (int i=0; i<32; ++i) {
        if ((p>>i)&1) {
            ans = ans*b%MOD;
        }
        b = b*b%MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_sz(1, -1);
    dfs_hld(1, -1, 1);
    assert(ss == n);

    ll inv = modpow(n, MOD-2);

    for (int i=0; i<q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, d;
            cin >> u >> d;
            query_one(u, d);
        } else {
            int u;
            cin >> u;
            //cerr << " .. " << query_two(u) << endl;
            cout << query_two(u)*inv%MOD << "\n";
        }
    }

    return 0;
}