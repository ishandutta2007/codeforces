#include <bits/stdc++.h>
using namespace std;

const int MOD = 119 << 23 | 1;

struct node_t {
    int prd;
    int val;
    node_t() {
        prd = val = 0;
    }
};

node_t operator + (node_t a, node_t b) {
    if (!a.prd) return b;
    if (!b.prd) return a;
    node_t c;
    c.prd = (long long) a.prd * b.prd % MOD;
    c.val = (long long) a.val * b.prd % MOD;
    c.val = (c.val + b.val) % MOD;
    return c;
}

int inv(int a) {
    int r = 1, t = a, k = MOD - 2;
    while (k) {
        if (k & 1) r = (long long) r * t % MOD;
        t = (long long) t * t % MOD;
        k >>= 1;
    }
    return r;
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i] = (long long) p[i] * inv(100) % MOD;
    vector<node_t> st(n << 2);
    auto upd = [&] (int p, node_t val) {
        for (st[p += n] = val; 1 < p; ) p >>= 1, st[p] = st[p << 1] + st[p << 1 | 1];
    };
    auto query = [&] (int l, int r) {
        node_t lres, rres;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                lres = lres + st[l++];
            }
            if (r & 1) {
                rres = st[--r] + rres;
            }
        }
        return (lres + rres).val;
    };
    for (int i = 0; i < n; i++) {
        node_t c;
        c.val = c.prd = inv(p[i]);
        upd(i, c);
    }
    set<int> ss;
    ss.insert(0);
    int res = query(0, n - 1);
    for (int i = 0; i < q; i++) {
        string op; int u; cin >> u; u--;
        auto it = ss.lower_bound(u);
        if (it == ss.end() || *it != u) {
            it = ss.insert(u).first;
            int lo = *(--it);
            it++;
            int hi = n;
            if (++it != ss.end()) {
                hi = *it;
            }
            res -= query(lo, hi - 1);
            res += MOD;
            res %= MOD;
            res += query(lo, u - 1);
            res %= MOD;
            res += query(u, hi - 1);
            res %= MOD;
        }
        else {
            int lo = *(--it);
            it++;
            int hi = n;
            if (++it != ss.end()) {
                hi = *it;
            }
            res += query(lo, hi - 1);
            res %= MOD;
            res -= query(lo, u - 1);
            res += MOD;
            res %= MOD;
            res -= query(u, hi - 1);
            res += MOD;
            res %= MOD;
            ss.erase(u);
        }
        cout << res << "\n";
    }
    return 0;
}