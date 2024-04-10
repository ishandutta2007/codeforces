#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Solution {
int n, q;                  // <==== n, q is here
#define maxn 201010

// treap implementation
///////////////////////
#define tsize(t) (t ? t->s : 0)
#define upsz(t) { if (t) t->s = tsize(t->l) + tsize(t->r) + 1; }
struct treap {
    int v, p, s;
    treap *l, *r;
    treap(int v, treap* l = 0, treap* r = 0, int p = rand())
    : v(v), p(p), l(l), r(r) {
        upsz(this);
    }
};

ostream& operator<<(ostream& cout, treap* t) {
    if (t) cout << t->l << ' ' << t->v << ' ' << t->r;
    return cout;
}

void split(treap* t, treap*& l, treap*& r, int v) {
    if (!t) l = r = 0;
    else if (t->v <= v) split(t->r, t->r, r, v), l = t;
    else split(t->l, l, t->l, v), r = t;
    upsz(l); upsz(r);
}

void merge(treap*& t, treap* l, treap* r) {
    if (!l or !r) t = l ? l : r;
    else if (l->p > r->p) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upsz(t);
}

void insert(treap*& t, treap* n) {
    if (!t) t = n;
    else if (t->p < n->p) split(t, n->l, n->r, n->v), t = n;
    else insert(t->v > n->v ? t->l : t->r, n);
    upsz(t);
}

void del(treap*& t, int v) {
    if (!t) return assert(false);
    if (t->v == v) {
        //clog << "before del " << t << endl;
        treap* x = t; merge(t, t->l, t->r); delete x;
        //clog << "after del " << t << endl;
    }
    else del(t->v >= v ? t->l : t->r, v);
    upsz(t);
}

int cntsml(treap* t, int v) {
    if (!t) return 0;
    if (t->v > v) return cntsml(t->l, v);
    else return cntsml(t->r, v) + tsize(t->l) + 1;
}

treap* buildrangetreap(int l, int r, vi& hp, int i) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    return new treap(mid,
        buildrangetreap(l, mid - 1, hp, i * 2 + 1),
        buildrangetreap(mid + 1, r, hp, i * 2 + 2),
        hp[i]
    );
}

// segment tree implementation 
treap* seg[2 * maxn];
int ma[2 * maxn], mi[2 * maxn];
void build() {
    memset(ma, 0, sizeof ma);
    memset(mi, 127, sizeof mi);
    for (int i = 1; i <= n; ++i) ma[i + n + 1] = mi[i + n + 1] = i;
    for (int i = 2 * n + 1; i > 0; i--) {
        if (i == n + 1) continue;
        static vi hp;
        hp.resize(2 * (ma[i] - mi[i] + 1));
        rep (i, sz(hp)) hp[i] = rand();
        make_heap(hp.begin(), hp.end());
        //for (auto i: hp) clog << i << ' ';
        //clog << endl;
        seg[i] = buildrangetreap(mi[i], ma[i], hp, 0);
        ma[i >> 1] = max(ma[i >> 1], ma[i]);
        mi[i >> 1] = min(mi[i >> 1], mi[i]);
    }
}

int cntsml(int l, int r, int v) {
    int ans = 0;
    for (l += n + 1, r += n + 1; l <= r; l >>= 1, r >>= 1) {
        //clog << l << ' ' << r << endl;
        if (l & 1 ) ans += cntsml(seg[l++], v);
        if (~r & 1) ans += cntsml(seg[r--], v);
    }
    return ans;
}

void swapplace(int u, int v) {
    if (u > v) swap(u, v);
    int x = seg[u += n + 1]->v, y = seg[v += n + 1]->v;
    for (;__builtin_clz(u) > __builtin_clz(v); v >>= 1) {
        //clog << v << ' ' << y << endl;
        //clog << seg[v] << endl;
        del(seg[v], y); insert(seg[v], new treap(x));
        //clog << seg[v] << endl;
    }
    for (; u != v and u > 0 and v > 0; u >>= 1, v >>= 1) {
        //clog << u << ' ' << v << ' ' << x << ' ' << y << endl;
        //clog << seg[u] << endl << seg[v] << endl;
        del(seg[u], x); insert(seg[u], new treap(y)); 
        del(seg[v], y); insert(seg[v], new treap(x));
    }
}

// main man
long doquery(int u, int v) {
    // 2 5 1 4 3  -> 5
    // 4 5 1 2 3  -> 6
    // move 2 -> +1, -1
    // move 4 -> -1, +1
    // swap 2, 4 -> +1
    if (u == v) return 0;
    if (u > v) swap(u, v);
    int x = seg[u + n + 1]->v, y = seg[v + n + 1]->v;
    //clog << "fine" << endl;
    long s1 = cntsml(u + 1, v - 1, x), s2 = cntsml(u + 1, v - 1, y);
    long len = v - 1 - (u + 1) + 1;
    long ans = (-s1 + (len - s1)) + (-(len - s2) + s2);
    if (x < y) ++ans;
    else --ans;
    //clog << u << ' ' << v << ' ' << x << ' ' << y << ' ' << s1 << ' ' << s2 << ' ' << ans << endl;
    swapplace(u, v);
    return ans;
}

int main() {
    srand(time(0));
    cin >> n >> q;
    build();
    long ans = 0;
    while (q--) {
        int u, v; cin >> u >> v;
        //clog << "query " << u << ' ' << v << endl;
        ans += doquery(u, v);
        cout << ans << '\n';
    }
    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    return Solution::main();
}