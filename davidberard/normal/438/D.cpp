#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#ifdef LOCAL
#define nl endl
#else
#define nl '\n'
#endif

struct segtree {
    vector<ll> t, m;
    int h, n;
    segtree() {}
    segtree (const vector<ll>& init) {
        int sz = init.size();
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<ll>(n<<1, 0);
        m = vector<ll>(n<<1, 0);
        for (int i=0; i<sz; ++i) {
            t[i+n] = m[i+n] = init[i];
        }
        for (int i=n-1; i; --i) {
            pull(i);
        }
    }
    ll query(int l, int r) {
        ll ans = 0;
        for (l += n, r += n; l<r; l/=2, r/=2) {
            if (l%2) ans += t[l++];
            if (r%2) ans += t[--r];
        }
        return ans;
    }
    void pull(int x) {
        m[x] = max(m[x<<1], m[x<<1|1]);
        t[x] = t[x<<1]+t[x<<1|1];
    }
    void assign(int x, ll v) {
        x+=n;
        m[x] = t[x] = v;
        for (x/=2; x; x/=2) {
            pull(x);
        }
    }
    void mod(int l, int r, ll q, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv||rv<=l) return;
        if (m[x] < q) return;
        if (rv-lv == 1) {
            t[x] = m[x] = m[x]%q;
            return;
        }
        int m = (lv+rv)/2;
        mod(l, r, q, x*2, lv, m);
        mod(l, r, q, x*2+1, m, rv);
        pull(x);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> init(1);
    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        init.push_back(x);
    }
    segtree st(init);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r+1) << nl;
        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            st.mod(l, r+1, x);
        } else if (t == 3) {
            int k, x;
            cin >> k >> x;
            st.assign(k, x);
        }
    }

    return 0;
}