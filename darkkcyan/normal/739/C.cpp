#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

#define sgn(x) ((x) < 0 ? -1 : (x) > 0)

int n;
ve<long> a;
vi seg, ml, mr;

struct node {
    int ll, rr, id;
    node(int l, int r, int i):ll(l), rr(r), id(i) {}

    node left() { return node(ll, (rr + ll) / 2, id * 2); }
    node right() { return node((rr + ll) / 2 + 1, rr, id * 2 + 1); }

    int size() { return rr - ll + 1; }

    void downdate() {
        node l = left(), r = right();
        ml[id] = ml[l.id], mr[id] = mr[r.id];
        seg[id] = max(seg[l.id], seg[r.id]);
        if (a[l.rr] == 0 or a[r.ll] == 0) return;
        if (sgn(a[l.rr]) < sgn(a[r.ll])) return;
        seg[id] = max(seg[id], mr[l.id] + ml[r.id]);
        if (ml[l.id] == l.size()) ml[id] += ml[r.id];
        if (mr[r.id] == r.size()) mr[id] += mr[l.id];
    }

    void build() {
        if (ll > rr) return;
        if (ll == rr) {
            seg[id] = ml[id] = mr[id] = !!a[ll];
            return ;
        }
        left().build();
        right().build();
        downdate();
    }

    void update(int i, long v) {
        if (ll > rr or i < ll or i > rr) return ;
        if (ll == rr) {
            a[ll] += v;
            seg[id] = ml[id] = mr[id] = !!a[ll];
            return;
        }
        left().update(i, v);
        right().update(i, v);
        downdate();
    }
};

node root() { return node(1, n - 1, 1); }

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    a.resize(n + 1);
    int last; scanf("%d", &last);
    for (int i = 1; i < n; ++i) {
        int t; scanf("%d", &t);
        a[i] = t - last;
        last = t;
    }

    seg.resize(n * 4); ml = mr = seg;

    root().build();
    int m; scanf("%d", &m);
    while (m--) {
        int l, r, v; scanf("%d%d%d", &l, &r, &v);
        --l, --r;
        root().update(l, v);
        root().update(r + 1, -v);
        printf("%d\n", seg[1] + 1);
    }

    return 0;
}