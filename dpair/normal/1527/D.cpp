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

const int MAXN = 2e5 + 5;

int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
inline void link(int u, int v){add(u, v);add(v, u);}

LL ans[MAXN]; int sz[MAXN], dep[MAXN], son[MAXN], fa[MAXN];

void dfs(int x, int pre) {
    sz[x] = 1; son[x] = 0; dep[x] = dep[pre] + 1; fa[x] = pre;
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dfs(e[i], x); sz[x] += sz[e[i]];
        if(sz[son[x]] < sz[e[i]]) son[x] = e[i];
    }
}
int tp[MAXN];

void dfs2(int x, int tt) {
    tp[x] = tt; if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}

inline int LCA(int x, int y) {
    // debug("x = %d, y = %d\n", x, y);
    while(tp[x] ^ tp[y]) {
        // debug("in x = %d, y = %d\n", x, y);
        if(dep[tp[x]] < dep[tp[y]]) std::swap(x, y);
        x = fa[tp[x]];
    }
    // debug("out x = %d, y = %d\n", x, y);
    if(dep[x] > dep[y]) return y;
    else return x;
}

int anc[21][MAXN], n;

inline void init() { 
    rep(i, 1, n) anc[0][i] = fa[i];
    rep(j, 1, 20) rep(i, 1, n) anc[j][i] = anc[j - 1][anc[j - 1][i]];
}

inline int find(int x, int y) {
    const int d = dep[y];
    per(i, 20, 0) if(dep[anc[i][x]] > d) x = anc[i][x];
    return x;
}

inline int dis(int x, int y) {return dep[x] + dep[y] - (dep[LCA(x, y)] << 1); }

inline void work() {
    read(n); memset(head + 1, 0, sizeof(int) * n); cnt = 0; rep(i, 2, n) link(read() + 1, read() + 1);
    ans[0] = 1ll * n * (n - 1) >> 1; ans[1] = ans[0]; dfs(1, 0); for (int i = head[1];i;i = nxt[i]) {ans[1] -= (1ll * sz[e[i]] * (sz[e[i]] - 1) >> 1); }
    dfs2(1, 1); init(); int len = 0, p1 = 1, p2 = 1;
    rep(i, 2, n) {
        const int d1 = dis(i, p1), d2 = dis(i, p2);
        // debug("i = %d, d1 = %d, p1 = %d, d2 = %d, p2 = %d, len = %d\n", i, d1, p1, d2, p2, len);
        // debug("dep[i] = %d, dep[p1] = %d, dep[p2] = %d, |%d %d|\n", dep[i], dep[p1], dep[p2], LCA(i, p1), LCA(i, p2));
        if(d1 + len == d2) p1 = i, len = d2;
        elif(d2 + len == d1) p2 = i, len = d1;
        elif(d1 + d2 == len) {ans[i] = ans[i - 1]; continue;}
        else { rep(j, i, n) ans[j] = 0; break;}
        const int lca = LCA(p1, p2);
        if(lca ^ p1 && lca ^ p2) ans[i] = 1ll * sz[p1] * sz[p2];
        elif(lca == p1) ans[i] = 1ll * (n - sz[find(p2, p1)]) * sz[p2];
        else ans[i] = 1ll * (n - sz[find(p1, p2)]) * sz[p1];
        // debug("i = %d\n", i);
    }
    rep(i, 0, n - 1) ans[i] -= ans[i + 1];
    print(ans, ans + n + 1);
}

signed main(){
    int T = read();
    while(T --) work();
}