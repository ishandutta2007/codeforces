/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n, m;
int a[1 << 18], pos[1 << 18];
vector<int> nei[1 << 18];
int bg[1 << 18], en[1 << 18];
vector<int> ord;
int N[20][1 << 19];

void inline dfs(int now) {
    bg[now] = SZ(ord);
    ord.pub(now);
    loop(i, SZ(nei[now])) {
        int to = nei[now][i];
        dfs(to);
        ord.pub(now);
    }
    en[now] = SZ(ord);
}

// Get the LCA of u and v in O(1)
int inline lca(int u, int v) {
    if(bg[u] > bg[v]) swap(u, v);
    int dis = 31 - __builtin_clz(bg[v] - bg[u]);
    return min(N[dis][bg[u]], N[dis][bg[v] - (1 << dis) + 1]);
}

// Check whether x is on path (u, v)
bool inline On(int u, int v, int x) {
    int w = lca(u, v);
    return bg[x] >= bg[w] && en[x] <= en[w] && (
        (bg[u] >= bg[x] && en[u] <= en[x]) ||
        (bg[v] >= bg[x] && en[v] <= en[x])
    );
}

pair<int, int> dt[1 << 20];

// Check whether a and b both on path (u, v)
bool inline can(int u, int v, int a, int b) {
    return On(u, v, a) && On(u, v, b);
}

// Merge two segments a and b
pair<int, int> inline merge(pair<int, int> a, pair<int, int> b) {
    if(!~a.first || !~b.first) return mak(-1, -1);
    if(!a.first) return b;
    int c = a.first, d = a.second, e = b.first, f = b.second;
    if(can(c, d, e, f)) return mak(c, d);
    if(can(c, e, d, f)) return mak(c, e);
    if(can(c, f, d, e)) return mak(c, f);
    if(can(d, e, c, f)) return mak(d, e);
    if(can(d, f, c, e)) return mak(d, f);
    if(can(e, f, c, d)) return mak(e, f);
    return mak(-1, -1);
}

void inline pu(int now) {
    dt[now] = merge(dt[now << 1], dt[now << 1 | 1]);
}

void inline init(int now = 1, int nl = 1, int nr = n) {
    if(nl == nr) return void(dt[now] = mak(pos[nl], pos[nl]));
    int m = (nl + nr) >> 1;
    init(now << 1, nl, m);
    init(now << 1 | 1, m + 1, nr);
    pu(now);
}

void inline change(int to, int x, int now = 1, int nl = 1, int nr = n) {
    if(nl == nr) return void(dt[now] = mak(x, x));
    int m = (nl + nr) >> 1;
    m >= to ? change(to, x, now << 1, nl, m)
        : change(to, x, now << 1 | 1, m + 1, nr);
    pu(now);
}

int inline find(pair<int, int> cur = mak(0, 0), int now = 1, int nl = 1, int nr = n) {
    if(nl == 1 && ~dt[now].first) return nr;
    if(nl == nr) return nl - 1;
    int m = (nl + nr) >> 1;
    pair<int, int> ml = merge(cur, dt[now << 1]);
    if(!~ml.first) return find(cur, now << 1, nl, m);
    else return find(ml, now << 1 | 1, m + 1, nr);
}

int main() {
    scanf("%d", &n);
    cont(i, n) scanf("%d", a + i), ++a[i], pos[a[i]] = i;
    circ(i, 2, n) {
        int fa; scanf("%d", &fa);
        nei[fa].pub(i);
    }
    dfs(1); m = SZ(ord);
    loop(i, m) N[0][i] = ord[i];
    loop(i, 19) loop(j, m) {
        if(j + (1 << i) < m) N[i + 1][j] = min(N[i][j], N[i][j + (1 << i)]);
        else N[i + 1][j] = N[i][j];
    }
    init();
    int q; scanf("%d", &q);
    while(q--) {
        int t; scanf("%d", &t);
        if(t == 2) {
            printf("%d\n", find());
        } else {
            int u, v; scanf("%d%d", &u, &v);
            int au = a[u], av = a[v];
            change(au, v); change(av, u);
            swap(a[u], a[v]); swap(pos[au], pos[av]);
        }
    }
    return 0;
}
/**
 * 
 *    dfs dfs  LCA
 *      u v1, v2, ..., vk u  dfs  Su (u, Sv1, u, Sv2, u, ..., u, Svk, u)
 *     u  u  S1  pu N(p, i)  S1  p  2^i 
 *     LCA  u  vpu < pv i  pv - pu > 2^i min(N(pu, i), N(pv - 2^i + 1, i)) O(1)
 *        i  31 - __builtin_clz(pv - pu)
 *    [l, r]  -1
 *    [x, x]  x 
 *   pushup  -1
 *    -1  O(q log n)
 */