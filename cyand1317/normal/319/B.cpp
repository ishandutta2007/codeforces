#include <cstdio>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
static const int MAXN = 1e5 + 4;

int n;
int p[MAXN];

namespace sgt {
    // Range maximum query, single value assignment
    static const int MAXN = ::MAXN * 2;

    int sz = 0;
    struct node { int l, r, lch, rch, max; } t[MAXN];

    inline int build(int L, int R) {
        int idx = sz++;
        t[idx].l = L, t[idx].r = R;
        t[idx].max = -1;
        if (L == R) {
            t[idx].lch = t[idx].rch = -1;
        } else {
            int M = (L + R) >> 1;
            t[idx].lch = build(L, M);
            t[idx].rch = build(M + 1, R);
        }
        return idx;
    }
    inline void rebuild(int L, int R) { sz = 0; build(L, R); }

    int QL, QR;
    inline int query(int idx) {
        if (t[idx].l >= QL && t[idx].r <= QR) return t[idx].max;
        int ans = -1;
        if (t[t[idx].lch].r >= QL) ans = std::max(ans, query(t[idx].lch));
        if (t[t[idx].rch].l <= QR) ans = std::max(ans, query(t[idx].rch));
        return ans;
    }
    inline int query(int L, int R) { if (L > R) return -1; QL = L, QR = R; return query(0); }
    inline void modify(int idx) {
        if (t[idx].lch == -1) { t[idx].max = QR; return; }
        if (t[t[idx].lch].r >= QL) modify(t[idx].lch); else modify(t[idx].rch);
        t[idx].max = std::max(t[t[idx].lch].max, t[t[idx].rch].max);
    }
    inline void modify(int P, int V) { QL = P, QR = V; modify(0); }
}

int par[MAXN];
std::list<int> *e[MAXN];
std::set<int, std::greater<int>> nonleaves;

inline void shrink(int u, int v)
{
    if (e[u]->size() > e[v]->size()) {
        for (auto i = e[v]->rbegin(); i != e[v]->rend(); ++i)
            e[u]->push_front(*i);
        e[v]->clear();
        delete e[v];
    } else {
        for (auto i = e[u]->begin(); i != e[u]->end(); ++i)
            e[v]->push_back(*i);
        e[u]->clear();
        delete e[u];
        e[u] = e[v];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];

    par[0] = -1;
    sgt::rebuild(0, n - 1);
    for (int i = 1; i < n; ++i) {
        sgt::modify(p[i - 1], i - 1);
        par[i] = sgt::query(p[i] + 1, n - 1);
    }

    for (int i = 0; i < n; ++i) {
        e[i] = new std::list<int>();
        if (par[i] != -1) e[par[i]]->push_back(i);
    }
    for (int i = 0; i < n; ++i) if (!e[i]->empty()) nonleaves.insert(i);

    int ans = 0;
    while (!nonleaves.empty()) {
        static std::vector<int> rm;
        for (int u : nonleaves) {
            int v = e[u]->front(); e[u]->pop_front();
            if (!e[v]->empty()) shrink(u, v);
            rm.push_back(v);
            if (e[u]->empty()) rm.push_back(u);
        }
        for (int u : rm) nonleaves.erase(u);
        rm.clear();
        ++ans;
    }

    printf("%d\n", ans);
    return 0;
}