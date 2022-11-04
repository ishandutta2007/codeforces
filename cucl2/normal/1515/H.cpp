#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

#define get(it, val) ((it) ? (it)->val : 0)
const int maxn = 1 << 18, maxm = (1 << 20) - 1;

typedef struct Node {
    Node *l, *r;
    int sz, msk0, msk1;
    int tag, lg;

    /* Push XOR tag */
    void inline push(int val) {
        tag ^= val;
        if (lg && ((val >> (lg - 1)) & 1)) swap(l, r);
        tie(msk0, msk1) = mak(
            (msk0 & ~val) | (msk1 & val),
            (msk1 & ~val) | (msk0 & val)
        );
    }

    /* Pushdown tag */
    void inline pd() {
        if (!tag) return;
        if (l) l->push(tag);
        if (r) r->push(tag);
        tag = 0;
    }

    /* Pushup */
    void inline pu() {
        sz = get(l, sz) + get(r, sz);
        msk0 = get(l, msk0) | get(r, msk0);
        msk1 = get(l, msk1) | get(r, msk1);
    }
} *node;

/* Memory Pool */
namespace MemoryPool {
    Node p[10000005];
    int s;
    /* Allocate a new node */
    node inline newnode() { return p + s++; }
}
using MemoryPool::newnode;

void insert(int x, node &now, int lg = 20) {
    if (!now) now = newnode(), now->lg = lg;
    if (!lg) {
        now->sz = 1;
        now->msk0 = x ^ maxm;
        now->msk1 = x;
        return;
    }
    now->pd();
    if (!((x >> (lg - 1)) & 1)) insert(x, now->l, lg - 1);
    else insert(x, now->r, lg - 1);
    now->pu();
}

void split(node &u, node &v, int l, int r, node now, int nl = 0, int nr = maxm, int lg = 20) {
    if (nl > r || nr < l || !now) return (void)(v = 0); 
    if (nl >= l && nr <= r) return (void)(u = 0, v = now);
    now->pd(); u = now;
    v = newnode(); v->lg = lg;
    int m = (nl + nr) >> 1;
    split(u->l, v->l, l, r, now->l, nl, m, lg - 1);
    split(u->r, v->r, l, r, now->r, m + 1, nr, lg - 1);
    u->pu(); v->pu();
}

node merge(node u, node v, int lg = 20) {
    if (!u || !v) return u ? u : v;
    if (!lg) return u;
    u->pd(); v->pd();
    u->l = merge(u->l, v->l, lg - 1);
    u->r = merge(u->r, v->r, lg - 1);
    u->pu(); return u;
}

void updor(node u, int x, int lg = 20) {
    if (!u) return;
    if (!(x & u->msk0 & u->msk1)) {
        u->push(x & u->msk0);
        return;
    }
    u->pd();
    if ((x >> (lg - 1)) & 1) {
        if (u->l) u->l->push(1 << (lg - 1));
        u->r = merge(u->l, u->r, lg - 1);
        u->l = 0;
    }
    updor(u->l, x, lg - 1);
    updor(u->r, x, lg - 1);
    u->pu();
}

int inline getcnt(int l, int r, node now, int nl = 0, int nr = maxm) {
    if (nl > r || nr < l || !now) return 0;
    if (nl >= l && nr <= r) return now->sz;
    int m = (nl + nr) >> 1; now->pd();
    return getcnt(l, r, now->l, nl, m) + getcnt(l, r, now->r, m + 1, nr);
}

int n, q;
node root;

int main() {
    scanf("%d%d", &n, &q);
    cont(i, n) {
        int a; scanf("%d", &a);
        insert(a, root);
    }
    while (q--) {
        int mode; scanf("%d", &mode);
        int l, r, x; scanf("%d%d", &l, &r);
        if (mode <= 3) {
            scanf("%d", &x);
            node outer, inner;
            split(outer, inner, l, r, root);
            if (!inner) continue;
            if (mode == 1) inner->push(maxm), updor(inner, maxm ^ x), inner->push(maxm);
            else if (mode == 2) updor(inner, x);
            else inner->push(x);
            root = merge(outer, inner);
        } else {
            printf("%d\n", getcnt(l, r, root));
        }
    }
    return 0;
}