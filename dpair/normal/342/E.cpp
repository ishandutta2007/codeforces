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
int n, m, head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }

struct Tree {
    int dfn[MAXN << 1], tot = 0, dep[MAXN], t[20][MAXN << 1], lg[MAXN << 1];
    void dfs(int x, int pre) {
        dep[x] = dep[pre] + 1; t[0][dfn[x] = ++ tot] = x;
        for (int i = head[x];i;i = nxt[i]) {
            if(e[i] == pre) continue;
            dfs(e[i], x); t[0][++ tot] = x;
        }
    }
    inline void init() {
        dfs(1, 0); lg[0] = -1; rep(i, 1, tot) lg[i] = lg[i >> 1] + 1; 
        rep(j, 1, lg[tot]) rep(i, 1, tot - (1 << j) + 1) t[j][i] = (dep[t[j - 1][i]] < dep[t[j - 1][i + (1 << (j - 1))]])? t[j - 1][i] : t[j - 1][i + (1 << (j - 1))];
    }
    inline int dis(const int x, const int y) {
        int l = dfn[x], r = dfn[y]; if(l > r) std::swap(l, r);
        const int k = lg[r - l + 1]; return dep[x] + dep[y] - (mn(dep[t[k][l]], dep[t[k][r - (1 << k) + 1]]) << 1);
    }
}tr;

struct DFT {
    int root = 0, sz[MAXN], SZ[MAXN], fa[MAXN], dis[MAXN], dep[MAXN]; bool vis[MAXN];
    void getsz(int x, int pre) {
        sz[x] = 1; for (int i = head[x];i;i = nxt[i]) {
            if(vis[e[i]] || e[i] == pre) continue;
            getsz(e[i], x); sz[x] += sz[e[i]];
        }
    }
    void getroot(int x, int pre, const int siz) {
        SZ[x] = siz - sz[x]; for (int i = head[x];i;i = nxt[i]) {
            if(vis[e[i]] || e[i] == pre) continue;
            getroot(e[i], x, siz); chmax(SZ[x], sz[e[i]]);
        } if(SZ[x] < SZ[root]) root = x;
    }
    void dfz(int x, int pre) { fa[x] = pre; vis[x] = 1;
        for (int i = head[x];i;i = nxt[i]) {
            if(vis[e[i]]) continue;
            root = 0; getsz(e[i], x); getroot(e[i], x, sz[e[i]]); dfz(root, x);
        }
    }
    inline void init() { SZ[0] = INF; memset(dis, 31, sizeof(dis)); getsz(1, 0); getroot(1, 0, n); dfz(root, 0); memset(vis, 0, sizeof(vis)); }
    inline void ins(const int x) { if(!vis[x]) { vis[x] = 1; int u = x; while(u) { chmin(dis[u], tr.dis(u, x)); u = fa[u]; } } }
    inline int ask(const int x) { if(vis[x]) { return 0; } int u = x, ret = INF; while(u) { chmin(ret, tr.dis(x, u) + dis[u]); u = fa[u]; } return ret; }
}t;

signed main(){
    read(n, m); rep(i, 2, n) link(read(), read());
    tr.init(); t.init(); t.ins(1); while(m --) { int opt, x; read(opt, x); opt == 1 ? t.ins(x) : print(t.ask(x)); }
}
// 