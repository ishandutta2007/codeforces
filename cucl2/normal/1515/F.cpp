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

int n, m, x;
ll a[300005];
vector<pair<int, int> > egs;
map<pair<int, int>, int> id;
vector<pair<int, int> > nei[300005];
vector<int> ans;

struct UnionFind {
    int fa[300005];
    void inline init() {memset(fa, -1, sizeof(fa));}
    UnionFind() {init();}
    int inline root(int x) {return fa[x] < 0 ? x : fa[x] = root(fa[x]);}
    bool inline conn(int a, int b) {
        a = root(a); b = root(b);
        if(a == b) return 0;
        return fa[b] += fa[a], fa[a] = b, 1;
    }
} uf;

void presolve(int now) {
    if (uf.fa[uf.root(1)] == -n) return;
    while (SZ(nei[now])) {
        int u = now, v = nei[now].back().first, id = nei[now].back().second;
        u = uf.root(u); v = uf.root(v); nei[now].pob();
        if (u == v) continue;
        if (SZ(nei[u]) > SZ(nei[v])) swap(u, v);
        ans.pub(id);
        parse(it, nei[u]) nei[v].pub(it);
        nei[u].clear(); uf.conn(u, v);
        a[v] += a[u] - x;
        if (a[v] >= x) presolve(v);
        return;
    }
}

int main() {
    srand(time(0));
    scanf("%d%d%d", &n, &m, &x);
    cont(i, n) scanf("%lld", a + i);
    cont(i, m) {
        int u, v; scanf("%d%d", &u, &v);
        egs.emb(u, v); id[mak(u, v)] = i;
        nei[u].emb(v, i); nei[v].emb(u, i);
    }
    uf.init();
    cont(i, n) if (uf.root(i) == i && a[i] >= x) presolve(i);
    while (uf.fa[uf.root(1)] != -n) {
        random_shuffle(all(egs));
        int ne = 0;
        set<pair<int, int> > sp;
        loop(i, SZ(egs)) {
            int u = uf.root(egs[i].first), v = uf.root(egs[i].second);
            if (u == v) continue;
            if (sp.count(mak(u, v)) || sp.count(mak(v, u))) continue;
            sp.emplace(u, v);
            egs[ne++] = egs[i];
        }
        egs.resize(ne);
        bool ch = 0;
        parse(e, egs) {
            int u = uf.root(e.first), v = uf.root(e.second);
            if (u == v) continue;
            if (uf.fa[u] < uf.fa[v]) swap(u, v);
            if (a[u] + a[v] >= x) {
                uf.conn(u, v);
                a[v] += a[u] - x;
                ans.pub(id[e]); ch = 1;
            }
        }
        if (!ch) return puts("NO"), 0;
    }
    puts("YES");
    parse(i, ans) printf("%d\n", i);
    return 0;
}