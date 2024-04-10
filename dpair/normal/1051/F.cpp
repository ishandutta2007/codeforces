// 
#include <assert.h>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
#define elif else if
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) { return x < y ? x : y; }
template <typename T>
inline T mx(const T x, const T y) { return x > y ? x : y; }
template <typename T>
inline bool chmin(T &x, const T y) { return (x > y) && ((x = y), 1); }
template <typename T>
inline bool chmax(T &x, const T y) { return (x < y) && ((x = y), 1); }
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) { return mx(x, mx(args...)); }
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) { return mn(x, mn(args...)); }
}
using namespace MyMinMax;
namespace IO{
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha() { return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS ++; }

template <typename T = int>
inline T read() {
    T x = 0; char c = getcha();
    while(c <= 32) { c = getcha(); }
    while(c > 32) { x = x * 10 + c - 48; c = getcha(); }
    return x;
}
template <typename T>
inline void read(T &x) {
    x = 0; char c = getcha();
    while(c <= 32) { c = getcha(); }
    while(c > 32) { x = x * 10 + c - 48; c = getcha(); }
}

template <typename T>
inline void read(T *bg, T *ed) { while(bg != ed) read(*bg ++); }
inline void read(char &ch) { ch = getcha(); while(ch <= 32) ch = getcha(); }
inline void read(char *s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void getl(char *s) {
    char ch = getcha(); while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pread(char *&s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pgetl(char *&s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}

template <typename T, typename ...Args>
inline void read(T &x, Args &...args) { read(x); read(args...); }

char out[DPAIRSIZ], *Out = out;
#define flush() fwrite(out, 1, Out - out, stdout)
inline void putcha(char x) { *Out++ = x; if(Out - out >= (DPAIRSIZ)) flush(), Out = out; }
template <typename T>
inline void fprint(T x){
    if(x > 9) fprint(x / 10);
    putcha(x % 10 + 48);
}
inline void print(){ putcha(10); }
template <typename T>
inline void print(T x) { fprint(x); putcha(10); }
inline void print(char *ch) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); }
inline void put(char *ch) { while(*ch != '\0') putcha(*(ch ++)); }
inline void print(const char *ch) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); }
inline void put(const char *ch) { while(*ch != '\0') putcha(*(ch ++)); }
template <typename T, typename ...Args>
inline void print(T x, Args ...args) { fprint(x); putcha(32); print(args...); }
template <typename ...Args>
inline void print(const char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(32); print(args...); }
template <typename ...Args>
inline void print(char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(32); print(args...); }
template <typename T, typename ...Args>
inline void printl(T x, Args ...args) { fprint(x); putcha(10); printl(args...); }
template <typename ...Args>
inline void printl(const char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); printl(args...); }
template <typename ...Args>
inline void printl(char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); printl(args...); }
template <typename T>
inline void sprint(T x) { fprint(x); putcha(32); }
template <typename T, typename ...Args>
inline void sprint(T x, Args ...args) { fprint(x); putcha(32); sprint(args...); }
template <typename T>
inline void sprint(T *bg, T *ed) { while(bg != ed) sprint(*bg ++); }
template <typename T>
inline void print(T *bg, T *ed) { while(bg != ed) sprint(*bg ++); putcha(10); }
template <typename T>
inline void printl(T *bg, T *ed) { while(bg != ed) print(*bg ++); }
class AutoFlush{
    public:
        ~AutoFlush(){flush();}
}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

const int MAXN = 1e5 + 5;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt, val[MAXN << 1];
inline void add(int u, int v, int w) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; val[cnt] = w; }
inline void link(int u, int v, int w) { add(u, v, w); add(v, u, w); }

int n, m, fa[MAXN];
inline int find(int x) { return x == fa[x]? fa[x] : fa[x] = find(fa[x]); }

#include <vector> 
struct EDGE {
    int u, v, w;
    EDGE (int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};

std::vector < EDGE > vec;

int dep[MAXN], sz[MAXN], son[MAXN], tp[MAXN]; LL f[MAXN];
void dfs(int x, int pre) {
    dep[x] = dep[fa[x] = pre] + 1; sz[x] = 1;
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        f[e[i]] = f[x] + val[i];
        dfs(e[i], x); sz[x] += sz[e[i]];
        if(sz[e[i]] > sz[son[x]]) son[x] = e[i];
    }
}

void dfs2(int x, int tt) {
    tp[x] = tt; if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}

inline int lca(int x, int y) {
    while(tp[x] ^ tp[y]) {
        if(dep[tp[x]] < dep[tp[y]]) std::swap(x, y);
        x = fa[tp[x]];
    } return dep[x] < dep[y]? x : y;
}

int s[45], t; LL dis[45][MAXN];

#include <queue>
struct DPair { 
    int u; LL val;
    DPair (int u, LL val) : u(u), val(val) {}
    inline bool operator< (const DPair &tmp) const { return val > tmp.val; }
};
bool vis[MAXN];
inline void Dijkstra(LL *const d, const int u) {
    d[u] = 0; std::priority_queue < DPair > q;
    memset(vis, 0, sizeof(vis)); q.push(DPair(u, 0));
    while(!q.empty()) {
        const int x = q.top().u; q.pop();
        if(vis[x]) continue;
        vis[x] = 1; for (int i = head[x];i;i = nxt[i]) { if(d[e[i]] > d[x] + val[i]) { d[e[i]] = d[x] + val[i]; q.push(DPair(e[i], d[e[i]])); } }
    }
}

signed main() {
    read(n, m); rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int u, v, w; read(u, v, w);
        if(find(u) == find(v)) vec.push_back(EDGE(u, v, w));
        else fa[find(u)] = find(v), link(u, v, w);
    }

    dfs(1, 0); dfs2(1, 1);

    for (auto it : vec) {
        link(it.u, it.v, it.w);
        s[t ++] = it.u; s[t ++] = it.v;
    }

    std::sort(s, s + t); t = std::unique(s, s + t) - s;

    memset(dis, 31, sizeof(dis));
    REP(i, 0, t) Dijkstra(dis[i], s[i]);

    int q = read(); while(q --) {
        int u, v; read(u, v); LL ans = f[u] + f[v] - (f[lca(u, v)] << 1);
        REP(i, 0, t) chmin(ans, f[s[i]] + f[u] - (f[lca(u, s[i])] << 1) + dis[i][v]);
        print(ans);
    }
}
/*
woshishabi


dijkstra

*/