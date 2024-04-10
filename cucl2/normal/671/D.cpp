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

struct State {
    set<pair<ll, int> > *dt;
    ll off;
    State() {
        dt = new set<pair<ll, int> >;
        off = 0;
    }
    void inline merge(State tmp) {
        if(SZ(*dt) < SZ(*tmp.dt)) swap(dt, tmp.dt), swap(off, tmp.off);
        foreach(it, *tmp.dt) {
            dt->insert(mak(it->first + tmp.off - off, it->second));
        }
        tmp.dt->clear();
    }
    void inline clean(int val) {
        while(SZ(*dt) && dt->begin()->second >= val) {
            dt->erase(dt->begin());
        }
    }
};

int n, m;
vector<int> nei[1 << 19];
vector<pair<int, int> > up[1 << 19];
ll ans;
int dep[1 << 19];

State inline dfs(int now, int lst) {
    State st; dep[now] = dep[lst] + 1;
    loop(i, SZ(nei[now])) {
        int to = nei[now][i];
        if(to == lst) continue;
        st.merge(dfs(to, now));
    }
    loop(i, SZ(up[now])) {
        int to = up[now][i].first, cs = up[now][i].second;
        st.dt->insert(mak(cs - st.off, dep[to]));
    }
    st.clean(dep[now]);
    if(now == 1) return st;
    if(!SZ(*st.dt)) {
        puts("-1");
        exit(0);
    }
    ans += st.dt->begin()->first + st.off;
    st.off = -st.dt->begin()->first;
    return st;
}

int main() {
    scanf("%d%d", &n, &m);
    cont(i, n - 1) {
        int a, b; scanf("%d%d", &a, &b);
        nei[a].pub(b); nei[b].pub(a);
    }
    cont(i, m) {
        int x, y, c; scanf("%d%d%d", &x, &y, &c);
        up[x].pub(mak(y, c));
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}