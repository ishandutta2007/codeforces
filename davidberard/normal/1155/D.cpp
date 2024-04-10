#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct segtree {
    vector<ll> t, d;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<ll>(n<<1, 0);
        d = vector<ll>(n<<1, 0);
    }
    inline ll tsize(int i) {
        return 1;
    }
    void pulll(int i) {
        t[i] = max(t[i<<1],t[i<<1|1]);
        t[i] += d[i]*tsize(i);
    }
    void apply(int i, ll x) {
        d[i] += x;
        t[i] += x*tsize(i);
    }
    void pushh(int i) {
        if(d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
    void push(int x) {
        x+=n;
        for(int i=h; i>0; --i) {
            pushh(x>>i);
        }
    }
    ll query(int l, int r) { // max query
        push(l);
        push(r-1);
        ll ans = -INF;
        for(l += n, r += n; l<r; l/=2, r/=2) {
            if(l%2) ans = max(ans, t[l++]);
            if(r%2) ans = max(ans, t[--r]);
        }
        return ans;
    }
    void add(int l, int r, ll v) {
        bool cl = 0, cr = 0;
        push(l);
        push(r-1);
        for(l += n, r += n; l<r; l/=2, r/=2) {
            if(cl) {
                pulll(l-1);
            }
            if(cr) {
                pulll(r);
            }
            if(l%2) {
                apply(l++, v);
                cl = 1;
            }
            if(r%2) {
                apply(--r, v);
                cr = 1;
            }
        }
        for(--l; r>0; l/=2, r/=2) {
            if(cl) pulll(l);
            if(cr && (!cl || r != l)) pulll(r);
        }
    }
};

const int NMAX = 300300;
const int STEPS = 4;
ll n;
ll x;
ll a[NMAX];
ll dp[NMAX][STEPS];
ll mult[STEPS];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    mult[0] = 0;
    mult[1] = 1;
    mult[2] = x;
    mult[3] = 1;
    for(int i=1; i<STEPS; ++i) {
        segtree st(NMAX+1);
        for(int j=1; j<=n; ++j) {
            st.add(j, j+1, dp[j][i-1]);
        }
        for(int j=1; j<=n; ++j) {
            st.add(0, j, mult[i]*a[j]);
            dp[j][i] = st.query(0, j+1);
            //cerr << "!! " << j << " " << i << " = " << dp[j][i] << endl;
        }
    }
    ll best = 0;
    for(int i=1; i<=n; ++i) {
        best = max(dp[i][STEPS-1], best);
    }
    cout << best << endl;
    return 0;
}