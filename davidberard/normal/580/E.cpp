#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll pow1 = 101;
//const ll pow1 = 1;
const ll pow2 = 1789;

ll powpfx1[N];
ll poww1[N];

static unsigned fast_mod(uint64_t x, unsigned m = mod1) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}

void setup() {
    powpfx1[0] = 1;
    poww1[0] = 1;
    for (int i=1; i<N; ++i) {
        poww1[i] = fast_mod(poww1[i-1]*pow1);
        powpfx1[i] = fast_mod(powpfx1[i-1]+poww1[i]);
    }
}

struct segtree {
    vector<ll> t;
    vector<ll> d;
    ll *powpfx;
    ll *poww;
    ll mod;
    int n, h;
    segtree() {}
    segtree(int sz, ll *pp, ll *pw, ll m) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<ll>(n<<1, 0);
        d = vector<ll>(n<<1, -1);
        powpfx = pp;
        poww = pw;
        mod = m;
    }
    int seg_size(int x) {
        return 1<<(h - 31 + __builtin_clz(x));
    }
    void apply(int x, int dig) {
        d[x] = dig;
        t[x] = fast_mod(powpfx[seg_size(x)-1]*dig);
        //cerr << "! " << x << " " << t[x] << endl;
    }
    void push(int x) {
        if (d[x] != -1) {
            apply(x<<1, d[x]);
            apply(x<<1|1, d[x]);
            d[x] = -1;
        }
    }
    void pull(int x) {
        t[x] = fast_mod(t[x<<1] + t[x<<1|1]*poww[seg_size(x)/2]);
    }
    void update(int l, int r, int dig, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv || rv<=l) return;
        if (l<=lv && rv<=r) {
            apply(x, dig);
            return;
        }
        push(x);
        int mv = (lv+rv)/2;
        update(l, r, dig, x*2, lv, mv);
        update(l, r, dig, x*2+1, mv, rv);
        pull(x);
    }
    ll query(int l, int r, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        //cerr << " : " << l << " " << r << endl;
        if (r<=lv || rv<=l) return 0;
        if (l<=lv && rv<=r) {
            ll ans = fast_mod(poww[lv-l]*t[x]);
            //cerr << " Q " << x << " " << ans << endl;
            return ans;
        }
        push(x);
        int mv = (lv+rv)/2;
        ll ans = 0;
        ans += query(l, r, x*2, lv, mv);
        ans += query(l, r, x*2+1, mv, rv);
        //cerr <<  "Q " << x << " -> " << ans%mod << endl;
        return fast_mod(ans);
    }
};

int n, m, k;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> m >> k;
    segtree st(n+1, powpfx1, poww1, mod1);
    string s;
    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        st.update(i, i+1, s[i]);
    }
    for (int i=0; i<m+k; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            string t;
            cin >> l >> r >> t;
            st.update(l-1, r, t[0]);
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            if (d >= (r-l+1)) {
                cout << "YES\n";
            } else {
                ll h1 = st.query(l-1, r-d);
                ll h2 = st.query(l-1+d, r);
                //cerr << "! " << h1 << " " << h2 << endl;
                cout << (h1 == h2 ? "YES" : "NO") << "\n";
            }
        }
    }
    return 0;
}