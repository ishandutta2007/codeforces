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
const int MOD = 1e9 + 7;

int n, a[MAXN];
int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
inline void link(int u, int v){add(u, v);add(v, u);}

int sz[MAXN], SZ[MAXN], root;
bool vis[MAXN];

void getsz(int x, int pre) {
    sz[x] = 1; 
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre || vis[e[i]]) continue;
        getsz(e[i], x); sz[x] += sz[e[i]];
    }
}

void getroot(int x, int pre, const int siz) {
    SZ[x] = siz - sz[x];
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre || vis[e[i]]) continue;
        getroot(e[i], x, siz); chmax(SZ[x], sz[e[i]]);
    }
    if(SZ[x] < SZ[root]) root = x;
}

int ans = 0;

inline void Add(int &x, const int y) {((x += y) >= MOD) && (x -= MOD);}
inline void Sub(int &x, const int y) {((x -= y) < 0) && (x += MOD);}
inline int addd(const int x, const int y) {return (x + y) >= MOD? (x + y - MOD) : (x + y);}

int dep[MAXN], f[MAXN], c[2], cc[2], t[2];

void dfs(int x, int pre) {
    f[x] = a[x]; Sub(f[x], f[pre]);
    if(dep[x] & 1) Add(ans, addd(f[x], f[x]));
    ++ cc[dep[x] & 1]; Add(t[dep[x] & 1], f[x]);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre || vis[e[i]]) continue;
        dfs(e[i], x); 
    }
}

void Dfs(int x, int pre) {
    dep[x] = dep[pre] + 1; ++ cc[dep[x] & 1];
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre || vis[e[i]]) continue;
        Dfs(e[i], x);
    }
}

inline void calc(int x) {
    c[0] = c[1] = 0;
    dep[x] = 1; f[x] = a[x];
    for (int i = head[x];i;i = nxt[i]) {
        if(vis[e[i]]) continue;
        cc[0] = cc[1] = 0;
        Dfs(e[i], x); Add(ans, ((2ll * cc[0] * c[0] - 2ll * cc[1] * c[1]) % MOD + MOD) % MOD * a[x] % MOD);
        c[0] += cc[0]; c[1] += cc[1];
    }
    for (int i = head[x];i;i = nxt[i]) {
        if(vis[e[i]]) continue;
        cc[0] = cc[1] = t[0] = t[1] = 0; dfs(e[i], x);
        Add(ans, (2ll * t[0] * (c[0] - cc[0]) + 2ll * t[1] * (c[1] - cc[1])) % MOD);
    }
}

void dfz(int x) {
    calc(x); vis[x] = 1; 
    for (int i = head[x];i;i = nxt[i]) {
        if(vis[e[i]]) continue;
        root = 0; getsz(e[i], x);
        getroot(e[i], x, sz[e[i]]);
        dfz(root);
    }
}

signed main(){ SZ[0] = INF;
    read(n); read(a + 1, a + n + 1);
    rep(i, 1, n) {
        if(a[i] < 0) a[i] += MOD;
        Add(ans, a[i]);
    }
    rep(i, 2, n) link(read(), read());
    getsz(1, 0); getroot(1, 0, n); dfz(root);
    print(ans);
}
/*


*/