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

int n;
int u[1 << 19], v[1 << 19];
vector<pair<int, int> > nei[1 << 19];
int dep[1 << 19];

struct Segtree {
    int mn[1 << 20], mx[1 << 20], tag[1 << 20];
    void inline pu(int now) {
        mn[now] = min(mn[now << 1], mn[now << 1 | 1]);
        mx[now] = max(mx[now << 1], mx[now << 1 | 1]);
    }
    void inline rev(int now) {
        swap(mn[now], mx[now]);
        mn[now] = -mn[now]; mx[now] = -mx[now];
    }
    void inline pd(int now) {
        if(tag[now]) {
            tag[now << 1] ^= 1; tag[now << 1 | 1] ^= 1;
            rev(now << 1), rev(now << 1 | 1); tag[now] = 0;
        }
    }
    void init(int now = 1, int nl = 1, int nr = n) {
        if(nl == nr) return void(mn[now] = mx[now] = dep[nl]);
        int m = (nl + nr) >> 1;
        init(now << 1, nl, m);
        init(now << 1 | 1, m + 1, nr);
        pu(now);
    }
    void change(int l, int r, int now = 1, int nl = 1, int nr = n) {
        if(nl >= l && nr <= r) {
            tag[now] ^= 1;
            rev(now);
            return;
        }
        if(nl > r || nr < l) return;
        pd(now); int m = (nl + nr) >> 1;
        change(l, r, now << 1, nl, m);
        change(l, r, now << 1 | 1, m + 1, nr);
        pu(now);
    }
} s1, s2;

int dps = -1, dpi;
int b1[1 << 19], e1[1 << 19], b2[1 << 19], e2[1 << 19], tmc;

void dfs(int now, int lst = 0, int lvl = 0, int col = 0) {
    if(lvl > dps) {
        dps = lvl;
        dpi = now;
    }
    b2[now] = ++tmc;
    dep[tmc] = (col ? -1 : 1) * lvl;
    loop(i, SZ(nei[now])) {
        int to = nei[now][i].first;
        if(to == lst) continue;
        dfs(to, now, lvl + 1, col ^ nei[now][i].second);
    }
    e2[now] = tmc;
}

void inline change(int a) {
    int u = ::u[a], v = ::v[a];
    if(b1[u] > b1[v]) swap(u, v);
    s1.change(b1[v], e1[v]);
    if(b2[u] > b2[v]) swap(u, v);
    s2.change(b2[v], e2[v]);
}

int main() {
    scanf("%d", &n);
    cont(i, n - 1) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        nei[a].pub(mak(b, c)); u[i] = a;
        nei[b].pub(mak(a, c)); v[i] = b;
    }
    int r1, r2;
    dfs(1); r1 = dpi; tmc = 0; dps = -1; dfs(r1);
    memcpy(b1, b2, sizeof(b1)); memcpy(e1, e2, sizeof(e1));
    s1.init(); r2 = dpi; tmc = 0; dfs(r2); s2.init();
    int m; scanf("%d", &m);
    while(m--) {
        int a; scanf("%d", &a); change(a);
        printf("%d\n", max(s1.mx[1], s2.mx[1]));
    }
    return 0;
}

/**
 * 
 *   
 *     
 *       
 *       
 *         
 *         
 *     
 *   
 *    -1  0
 *   
 *    O(q log n)
 */