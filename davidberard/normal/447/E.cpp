#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1e9+9;
const int N = 1<<19;

#ifdef LOCAL
#define nl endl
#else
#define nl '\n'
#endif

ll f[N];
ll pre[N];

void setup() {
    f[1] = 1;
    pre[1] = 1;
    for (int i=2; i<N; ++i) {
        f[i] = f[i-1]+f[i-2];
        if (f[i] >= MOD) f[i] -= MOD;

        pre[i] = pre[i-1]+f[i];
        if (pre[i] >= MOD) pre[i] -= MOD;
    }
}

struct lazy {
    ll prev, first;
    lazy() :prev(0), first(0) {}
    lazy(int z, int x) :prev(z), first(x) {}
    lazy &operator += (const lazy& o) {
        prev += o.prev;
        first += o.first;
        if (prev >= MOD) prev -= MOD;
        if (first >= MOD) first -= MOD;
        return *this;
    }
    bool empty() const {
        return prev == 0 && first == 0;
    }
    lazy split(int k) const {
        if (k == 0) return *this;
        return lazy((f[k]*first + f[k-1]*prev)%MOD, (f[k+1]*first + f[k]*prev)%MOD);
    }
    ll eval(int len) {
        return (pre[len]*first + pre[len-1]*prev)%MOD;
    }
    void clear() {
        first = prev = 0;
    }
};

struct segtree {
    vector<ll> t;
    vector<lazy> d;
    int n, h;
    segtree() {}
    segtree(const vector<int>& a) {
        h = 32 - __builtin_clz((int) a.size());
        n = 1<<h;
        t = vector<ll>(n<<1, 0);
        d = vector<lazy>(n<<1);
        
        for (int i=0; i<a.size(); ++i) {
            t[i+n] = a[i];
        }
        int sz = 2;
        for (int i=n-1; i; --i) {
            pull(i, sz);
            if (__builtin_popcount(i) == 1) sz *= 2;
        }
    }
    void pull(int x, int sz) {
        t[x] = t[x<<1]+t[x<<1|1]+d[x].eval(sz);
        t[x] %= MOD;
    }
    void apply(int x, lazy v, int sz) {
        t[x] += v.eval(sz);
        d[x] += v;
    }
    void push(int x, int sz) {
        if (!d[x].empty()) {
            apply(x<<1  , d[x], sz/2);
            apply(x<<1|1, d[x].split(sz/2), sz/2);
            d[x].clear();
        }
    }
    void update(int l, int r, lazy v, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv||rv<=l) return;
        if (l<=lv && rv<=r) {
            apply(x, v.split(lv-l), rv-lv);
            return;
        }
        int m = (lv+rv)/2;
        push(x, rv-lv);
        update(l, r, v, x*2, lv, m);
        update(l, r, v, x*2+1, m, rv);
        pull(x, rv-lv);
    }
    ll query(int l, int r, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv||rv<=l) return 0;
        if (l<=lv && rv<=r) {
            return t[x];
        }
        int m = (lv+rv)/2;
        push(x, rv-lv);
        ll ans = 0;
        ans += query(l, r, x*2, lv, m);
        ans += query(l, r, x*2+1, m, rv);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    vector<int> init(1);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        init.push_back(x);
    }

    segtree st(init);

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            st.update(l, r+1, lazy(0, 1));
        } else if (t == 2) {
            cout << st.query(l, r+1)%MOD << nl;
        }

    }


    return 0;
}