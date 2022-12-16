#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct segtree {
    vector<ll> t;
    vector<ll> d;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<ll>(n<<1, 0);
        d = vector<ll>(n<<1, 0);
    }
    inline void apply(int x, ll v) {
        t[x] += v;
        d[x] += v;
    }
    inline void push(int x) {
        if(d[x]) {
            apply(x<<1, d[x]);
            apply(x<<1|1, d[x]);
            d[x] = 0;
        }
    }
    inline void pull(int x) {
        t[x] = max(t[x<<1],t[x<<1|1])+d[x];
    }
    void pushh(int x) {
        for (int i=h; i; --i) {
            push(x>>i);
        }
    }
    ll query(int l, int r) {
        pushh(l+n); pushh(r+n-1);
        ll ans = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) {
                ans = max(ans, t[l++]);
            }
            if (r%2) {
                ans = max(ans, t[--r]);
            }
        }
        return ans;
    }
    void add(int l, int r, ll v) {
        pushh(l+n);
        pushh(r+n-1);
        bool cl = 0, cr = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) pull(l-1);
            if (cr) pull(r);
            if (l%2) {
                apply(l++, v);
                cl = 1;
            }
            if (r%2) {
                apply(--r, v);
                cr = 1;
            }
        }
        for (--l; r; l/=2, r/=2) {
            if (cl) pull(l);
            if (cr && (!cl || l!=r)) pull(r);
        }
    }
};

const int N = 200200;

int n, m;
ll a[N];
ll dp[N];
vector<pii> at[N]; // l, r -ending at[r], pair (l, price)

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    for (int i=1; i<=m; ++i) {
        int l, r, p;
        cin >> l >> r >> p;
        at[r].emplace_back(l, p);
    }
    segtree st(n+1);
    //cerr << "! " << endl;

    for (int i=1; i<=n; ++i) {
        for (auto& pr : at[i]) {
            st.add(0, pr.first, pr.second);
        }
        st.add(0, i, -a[i]);
        dp[i] = max(dp[i-1], st.query(0, i));
        //cerr << " ?" << i << " " << dp[i] << endl;
        st.add(i, i+1, dp[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}