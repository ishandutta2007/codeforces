#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ld = long double;
using ll = long long;

template <const int MAXV, const int MAXE, class unit, const bool SCALING> struct DinicMaxFlow {
    unit INF, EPS; DinicMaxFlow(unit INF, unit EPS) : INF(INF), EPS(EPS) {}
    struct Edge {
        int from, to; unit origCap, cap, maxCap; int rev; char isRev; Edge() {}
        Edge(int from, int to, unit cap, unit maxCap, char isRev) :
        from(from), to(to), origCap(cap), cap(cap), maxCap(maxCap), isRev(isRev) {}
    };
    int E, cur[MAXV], level[MAXV], q[MAXV], st[MAXV], deg[MAXV], ord[MAXE * 2], ind[MAXE * 2];
    bool cut[MAXV]; Edge e[MAXE * 2]; unit maxFlow, minCut, maxCap;
    void addEdge(int v, int w, unit vw, unit wv = 0) {
        e[E++] = Edge(v, w, vw, max(vw, wv), 0); e[E++] = Edge(w, v, wv, max(vw, wv), 1);
        e[E - 2].rev = E - 1; e[E - 1].rev = E - 2; deg[v]++; deg[w]++; maxCap = max(maxCap, max(vw, wv));
    }
    bool bfs(int V, int s, int t, unit lim, char r) {
        fill(level, level + V, -1); level[s] = 0; int front = 0, back = 0; q[back++] = s;
        while (front < back && level[t] == -1) {
            int v = q[front++];
            for (int i = st[v]; i < st[v] + deg[v] && e[i].maxCap > lim && e[i].isRev <= r; i++) {
                if (level[e[i].to] == -1 && e[i].cap > EPS) {
                    level[e[i].to] = level[v] + 1; q[back++] = e[i].to;
                    if (level[t] != -1) return true;
                }
            }
        }
        return level[t] != -1;
    }
    unit dfs(int v, int t, unit flow, unit lim, char r) {
        if (v == t || flow <= EPS) return flow;
        unit ret = 0;
        for (int &i = cur[v]; i < st[v] + deg[v] && e[i].maxCap > lim && e[i].isRev <= r; i++) {
            if (e[i].cap > EPS && level[e[i].to] == level[v] + 1) {
                unit res = dfs(e[i].to, t, min(flow, e[i].cap), lim, r);
                if (res > EPS) {
                    e[i].cap -= res; e[e[i].rev].cap += res; flow -= res; ret += res;
                    if (flow <= EPS) break;
                }
            }
        }
        return ret;
    }
    void init(int V = MAXV) { E = 0; maxCap = 0; fill(cut, cut + V, false); fill(deg, deg + V, 0); }
    unit getFlow(int V, int s, int t) {
        maxFlow = 0; iota(ord, ord + E, 0);
        stable_sort(ord, ord + E, [&] (const int &a, const int &b) {
            if (e[a].from != e[b].from) return e[a].from < e[b].from;
            if (e[a].isRev != e[b].isRev) return e[a].isRev < e[b].isRev;
            return e[a].maxCap > e[b].maxCap;
        });
        for (int i = 0; i < E; i++) ind[ord[i]] = i;
        for (int i = 0; i < E; i++) e[i].rev = ind[e[i].rev];
        stable_sort(e, e + E, [&] (const Edge &a, const Edge &b) {
            if (a.from != b.from) return a.from < b.from;
            if (a.isRev != b.isRev) return a.isRev < b.isRev;
            return a.maxCap > b.maxCap;
        });
        for (int v = 0, curSum = 0; v < V; v++) { st[v] = curSum; curSum += deg[v]; }
        for (char r = 1 - int(SCALING); r <= 1; r++) for (unit lim = SCALING ? maxCap : EPS; ; lim /= 2) {
                while (bfs(V, s, t, lim, r)) { copy(st, st + V, cur); maxFlow += dfs(s, t, INF, lim, r); }
                if (lim <= EPS) break;
            }
        return maxFlow;
    }
    void inferMinCutDfs(int v) {
        cut[v] = true;
        for (int i = st[v]; i < st[v] + deg[v]; i++) if (e[i].cap > EPS && !cut[e[i].to]) inferMinCutDfs(e[i].to);
    }
    unit inferMinCut(int V, int s) {
        inferMinCutDfs(s); minCut = 0;
        for (int v = 0; v < V; v++) if (cut[v]) for (int i = st[v]; i < st[v] + deg[v]; i++) if (!cut[e[i].to]) minCut += e[i].origCap;
        return minCut;
    }
};

int n, m, x, a[505], b[505], c[505];
const ld eps = 1e-13;

int main(){
    scan(n, m, x);
    for(int i = 0; i < m; i++){
        scan(a[i], b[i], c[i]);
    }
    
    ld l = eps, mid, r = 1e9;
    while(l+eps < r){
        mid = (l+r)/2;
    
        DinicMaxFlow<52, 502, ll, 1> mf(LLONG_MAX, 0);
        mf.init();
        
        for(int i = 0; i < m; i++){
            ll v = 1e9;
            if(mid)
                v = c[i]/mid;
            mf.addEdge(a[i], b[i], v);
//            g.addEdge(a[i], b[i], v);
//            print(a[i], b[i], (ll)(c[i]/mid));
        }
        
//        ll tot = g.DinicMaxflow(1, n);
        ll tot = mf.getFlow(n+1, 1, n);
//        cout<<mid<<' '<<tot<<endl;
        
        if(tot < x)
            r = mid-eps;
        else
            l = mid;
    }
    
    printf("%.12LF\n", l*x);
    
    return 0;
}