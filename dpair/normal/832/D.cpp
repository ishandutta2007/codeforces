//
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
const double pi = 3.141592653589793238462643383279;
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) {return x < y ? x : y;}
template <typename T>
inline T mx(const T x, const T y) {return x > y ? x : y;}
template <typename T>
inline bool chmin(T &x, const T y) {return (x > y) && ((x = y), 1);}
template <typename T>
inline bool chmax(T &x, const T y) {return (x < y) && ((x = y), 1);}
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) {return mx(x, mx(args...));}
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) {return mn(x, mn(args...));}
}
using namespace MyMinMax;
namespace IO{
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha(){return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS ++;}
template <typename T = int>
inline T read(){
    T x = 0;int fu = 1;
    char c = getcha();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getcha();
    }
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
    x *= fu;return x;
}
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getcha();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getcha();
    }
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
    x *= fu;
}
template <typename T>
inline void read(T *bg, T *ed){while(bg != ed) read(*bg ++);}
inline void read(char &ch){
    ch = getcha();
    while(ch <= 32) ch = getcha();
}
inline void read(char *s){
    char ch = getcha();
    while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void sread(char *s){
    char ch = getcha();
    while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pread(char *&s){
    char ch = getcha();
    while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void spread(char *&s){
    char ch = getcha();
    while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){read(x);read(args...);}
char out[DPAIRSIZ], *Out = out;
#define flush() fwrite(out, 1, Out - out, stdout)
inline void putcha(char x) {*Out++ = x;if(Out - out >= (DPAIRSIZ)) flush(), Out = out;}
template <typename T>
inline void fprint(T x){
    if(x < 0) putcha(45), x = -x;
    if(x > 9) fprint(x / 10);
    putcha(x % 10 + 48);
}
inline void print(){putcha(10);}
template <typename T>
inline void print(T x){fprint(x);putcha(10);}
inline void print(char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
inline void put(char *ch){while(*ch != '\0') putcha(*(ch ++));}
inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
template <typename T, typename ...Args>
inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
template <typename ...Args>
inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
template <typename ...Args>
inline void print(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
template <typename T, typename ...Args>
inline void printl(T x, Args ...args){fprint(x);putcha(10);printl(args...);}
template <typename ...Args>
inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);printl(args...);}
template <typename ...Args>
inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);printl(args...);}
template <typename T>
inline void sprint(T x){fprint(x);putcha(32);}
template <typename T, typename ...Args>
inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
template <typename T>
inline void sprint(T *bg, T *ed){while(bg != ed) sprint(*bg ++);}
template <typename T>
inline void print(T *bg, T *ed){while(bg != ed) sprint(*bg ++);putcha(10);}
template <typename T>
inline void printl(T *bg, T *ed){while(bg != ed) print(*bg ++);}
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

int n, m, fa[MAXN], tp[MAXN];

int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
inline void link(int u, int v){add(u, v);add(v, u);}

int sz[MAXN], son[MAXN], dep[MAXN];

void dfs1(int x, int pre) {
    fa[x] = pre; sz[x] = 1; dep[x] = dep[pre] + 1;
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dfs1(e[i], x); sz[x] += sz[e[i]];
        if(sz[son[x]] < sz[e[i]]) son[x] = e[i];
    }
}

int id[MAXN], tot, re;

void dfs2(int x, int tt) {
    tp[x] = tt; id[x] = ++ tot;
    if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

int t[MAXN << 2], tag[MAXN << 2];
inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
inline void update(int rt, int l, int r, int x) {
    t[rt] += (r - l + 1) * x;
    tag[rt] += x;
}
inline void pushdown(int rt, int l, int r) {
    if(tag[rt]) {
        int mid = (l + r) >> 1;
        update(LSON, tag[rt]);
        update(RSON, tag[rt]);
        tag[rt] = 0;
    }
}

void modify(int rt, int l, int r, int x, int y, int z) {
    if(x <= l && r <= y) return update(rt, l, r, z);
    pushdown(rt, l, r); int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}

int query(int rt, int l, int r, int x, int y) {
    if(x <= l && r <= y) return t[rt];
    pushdown(rt, l, r); int mid = (l + r) >> 1, ret = 0;
    if(x <= mid) ret = query(LSON, x, y);
    if(y > mid) ret += query(RSON, x, y);
    return ret;
}

inline void Modify(int u, int v, int w) {
    while(tp[u] ^ tp[v]) {
        if(dep[tp[u]] < dep[tp[v]]) std :: swap(u, v);
        modify(1, 1, n, id[tp[u]], id[u], w);
        u = fa[tp[u]];
    }
    if(id[u] > id[v]) std :: swap(u, v);
    return modify(1, 1, n, id[u], id[v], w);
}

inline int Query(int u, int v) {
    int ret = 0; while(tp[u] ^ tp[v]) {
        if(dep[tp[u]] < dep[tp[v]]) std :: swap(u, v);
        ret += query(1, 1, n, id[tp[u]], id[u]);
        u = fa[tp[u]];
    }
    if(id[u] > id[v]) std :: swap(u, v);
    return query(1, 1, n, id[u], id[v]) + ret;
}

inline int calc(int u, int v, int w) {
    Modify(u, v, 1); int ret = mx(Query(u, w), Query(v, w));
    Modify(u, v, -1); Modify(v, w, 1); chmax(ret, Query(u, w));
    Modify(v, w, -1); return ret;
}

signed main(){
    read(n, m); rep(i, 2, n) link(read(), i);
    dfs1(1, 0); dfs2(1, 1);
    while(m --) print(calc(read(), read(), read()));
}