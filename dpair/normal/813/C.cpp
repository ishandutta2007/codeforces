//  hehezhou    hehezhou  NOI  NOIp  ZK  ZK  ZK  NOIp  NOIp      mayiyang  mayiyang  hehezhou  NOI    NOI  ZK    NOI  ZK  hehezhou  mayiyang  hehezhou    mayiyang    hehezhou  mayiyang  mayiyang  NOIp  NOI  mayiyang  ZK 
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
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
inline void flush() { fwrite(out, 1, Out - out, stdout); }
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
const int MOD = 998244353, G = 3;
inline void Sub(int &x, const int y) {((x -= y) < 0) && (x += MOD);}
inline void Add(int &x, const int y) {((x += y) >= MOD) && (x -= MOD);}
inline int SUB(int x, const int y) {((x -= y) < 0) && (x += MOD); return x;}
inline int ADD(int x, const int y) {((x += y) >= MOD) && (x -= MOD); return x;}
inline int ksm(int x, int y) {
    int ret = 1; while(y) {
        if(y & 1) ret = 1ll * ret * x % MOD;
        y >>= 1; x = 1ll * x * x % MOD;
    } return ret;
}
/* My Code begins here */

const int MAXN = 2e5 + 5;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }

int n, p;

int fa[MAXN], dep[MAXN], tp[MAXN], son[MAXN], sz[MAXN];
void dfs(int x, int pre) {
    dep[x] = dep[fa[x] = pre] + (sz[x] = 1);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] != pre) {
            dfs(e[i], x); sz[x] += sz[e[i]];
            if(sz[e[i]] > sz[son[x]]) son[x] = e[i];
        }
    }
}

void dfs2(int x, int tt) {
    tp[x] = tt; if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nxt[i]) if(e[i] != fa[x] && e[i] != son[x]) dfs2(e[i], e[i]);
}

inline int LCA(int x, int y) {
    while(tp[x] ^ tp[y]) {
        if(dep[tp[x]] < dep[tp[y]]) std::swap(x, y);
        x = fa[tp[x]];
    }
    if(dep[x] > dep[y]) return y;
    else return x;
}

inline int dis(int x, int y) { return dep[x] + dep[y] - (dep[LCA(x, y)] << 1); }

signed main() {
    read(n, p); rep(i, 2, n) link(read(), read());
    dfs(1, 0); dfs2(1, 1); int ans = 0;
    rep(i, 1, n) {
        const int x = dis(1, i), y = dis(p, i);
        if(x > y) chmax(ans, x);
    }
    print(ans << 1);
}