//
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
#define gup(x) return puts(#x), 0
const double pi = 3.141592653589793238462643383279;
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) {return x < y ? x : y;}
template <typename T>
inline T mx(const T x, const T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, const T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, const T y) {(x < y) && (x = y);}
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
    T x = 0;
    char c = getcha();
    while(c > 57 || c < 48) c = getcha();
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
    return x;
}
template <typename T>
inline void read(T &x){
    x = 0;
    char c = getcha();
    while(c > 57 || c < 48) c = getcha();
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
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

int n, q;
LL w;
const int MAXN = 1e5 + 5;
int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1];
LL val[MAXN << 1];
void add(int u, int v, LL w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
}
void link(int u, int v, LL w){add(u, v, w);add(v, u, w);}

struct EDGE{
    int u, v;LL w;
}a[MAXN];

int dfn[MAXN], low[MAXN], tot;
int d[MAXN << 1], dis[MAXN << 1];
LL dep[MAXN];
void dfs(int x, int pre){
    dfn[x] = ++ tot;d[tot] = x;dis[x] = dis[pre] + 1;
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + val[i];
        dfs(e[i], x);d[++ tot] = x;
    }
    low[x] = tot;
}

struct NODE{
    LL V, M, LM, MR, LMR;
    NODE(LL V = 0, LL M = 0, LL LM = 0, LL MR = 0, LL LMR = 0) : V(V), M(M), LM(LM), MR(MR), LMR(LMR) {}
    inline NODE operator+ (const NODE &b) const{return NODE(mx(V, b.V), mx(M, b.M), mx(LM, b.LM, V + b.M), mx(MR, b.MR, M + b.V), mx(LMR, b.LMR, LM + b.V, V + b.MR));}
}t[MAXN << 3];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
void build(int rt, int l, int r){
    if(l == r){
        const int pos = d[l];
        return t[rt] = NODE(dep[pos], - dep[pos] << 1, - dep[pos], - dep[pos], 0), void();
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
LL tag[MAXN << 3];
inline void update(int rt, LL z){
    t[rt].V += z;t[rt].M -= z << 1;
    t[rt].LM -= z;t[rt].MR -= z;tag[rt] += z;
}
inline void pushdown(int rt){
    if(tag[rt]){
        update(rt << 1, tag[rt]);
        update(rt << 1 | 1, tag[rt]);
        tag[rt] = 0;
    }
}
void modify(int rt, int l, int r, const int x, const int y, const LL z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
signed main(){
    read(n, q, w);
    rep(i, 0, n - 2){
        read(a[i].u, a[i].v, a[i].w);
        link(a[i].u, a[i].v, a[i].w);
    }
    dfs(1, 0);build(1, 1, tot);
    LL lans = 0;
    while(q --){
        int D = (read < LL > () + lans) % (n - 1);
        LL E = (read < LL > () + lans) % w;
        int u = a[D].u, v = a[D].v;
        if(dis[u] < dis[v])  u ^= v ^= u ^= v;
        modify(1, 1, tot, dfn[u], low[u], E - a[D].w);
        a[D].w = E;
        print(lans = t[1].LMR);
    }
}