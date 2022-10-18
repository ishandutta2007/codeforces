//
//
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
int n, q;
int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1], val[MAXN << 1];
inline void add(int u, int v, int w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    val[cnt] = w;
    e[cnt] = v;
}
inline void link(int u, int v, int w){add(u, v, w);add(v, u, w);}

struct Solve{
    int dep[MAXN], dis[MAXN], md[MAXN];
    int tot, b[MAXN], bel[MAXN], c[MAXN], t[MAXN];
    int tp[MAXN], fa[MAXN][17], son[MAXN];
    void dfs(int x, int pre) {
        dep[x] = dep[fa[x][0] = pre] + 1; for (int i = 1;(1 << i) < dep[x];++ i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
        md[x] = dis[x]; for (int i = head[x];i;i = nxt[i]) {
            if(e[i] == pre) continue;
            dis[e[i]] = dis[x] + val[i];
            dfs(e[i], x); chmax(md[x], md[e[i]]) && (son[x] = e[i]);
        }
    }
    void dfs1(int x, int tt) {
        tp[x] = tt; if(son[x]) dfs1(son[x], tt);
        for (int i = head[x];i;i = nxt[i]) {
            if(e[i] == fa[x][0] || e[i] == son[x]) continue;
            dfs1(e[i], e[i]);
        }
    }
    inline void init(int rt) {
        dfs(rt, 0); dfs1(rt, rt);
        rep(i, 1, n) if(tp[i] == i) c[++ tot] = i;
        rep(i, 1, tot) {
            const int x = c[i];
            t[x] = md[x] - dis[fa[x][0]];
        } std :: sort(c + 1, c + tot + 1, [this](const int &x, const int &y){return t[x] > t[y]; });

        rep(i, 1, tot) {
            const int x = c[i]; b[i] = b[i - 1] + t[x];
            int u = x; while(u) {bel[u] = i; u = son[u]; }
        }
    }

    inline int query(int x, int y) {
        if(y >= tot) return b[tot];
        if(bel[x] <= y) return b[y];
        int u = x; per(i, 16, 0) if(bel[fa[u][i]] > y) u = fa[u][i];
        u = fa[u][0];
        return mx(b[y] + md[x] - md[u], b[y - 1] + md[x] - dis[u]);
    }
}t1, t2;

int dep[MAXN], root;
void dfs(int x, int pre) {
    if(dep[x] > dep[root]) root = x;
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + val[i];
        dfs(e[i], x);
    }
}

signed main(){
    read(n, q); REP(i, 1, n) {
        int u, v, w; read(u, v, w);
        link(u, v, w);
    } root = 1; dfs(1, 0); t1.init(root); dep[root] = 0; dfs(root, 0); t2.init(root);
    int lans = 0; while(q --) {
        int x = (read() + lans - 1) % n + 1;
        int y = (read() + lans - 1) % n + 1; y = (y << 1) - 1;
        print(lans = mx(t1.query(x, y), t2.query(x, y)));
    }
}