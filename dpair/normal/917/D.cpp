// 
#include <assert.h>
#include <ctime>
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
const int MOD = 1e9 + 7;
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

const int MAXN = 8005;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }
int n;
struct NODE { int x, y; NODE (int x = 0, int y = 0) : x(x), y(y) {} };

#include <vector>
std::vector < NODE > f[MAXN];
int sz[MAXN];

inline void clear(std::vector < NODE > &x) { std::vector < NODE > tmp; std::swap(tmp, x); }

NODE t[MAXN];

void dfs(int x, int pre) {
    f[x].resize(sz[x] = 1); f[x][0] = NODE(1, 1);
    for (int i = head[x];i;i = nxt[i]) {
        const int v = e[i]; if(v != pre) {
            dfs(v, x);

            REP(j, 0, sz[x]) REP(k, 0, sz[v]) {
                Add(t[j + k + 1].x, 1ll * f[x][j].x * f[v][k].x % MOD);
                Add(t[j + k].x, 1ll * f[x][j].x * f[v][k].y % MOD);

                Add(t[j + k + 1].y, 1ll * f[x][j].x * f[v][k].y % MOD);
                Add(t[j + k + 1].y, 1ll * f[x][j].y * f[v][k].x % MOD);
                Add(t[j + k].y, 1ll * f[x][j].y * f[v][k].y % MOD);
            }

            f[x].resize(sz[x] += sz[v]);
            REP(j, 0, sz[x]) { f[x][j] = t[j]; t[j] = NODE(); }
            clear(f[v]);
        }
    }
}

int fac[MAXN], inv[MAXN], ifac[MAXN];
inline void init() {
    inv[1] = 1; read(n); rep(i, 2, n) { link(read(), read()); inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD; }
    fac[0] = ifac[0] = 1; rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD, ifac[i] = 1ll * ifac[i - 1] * inv[i] % MOD;
}

inline int C(int x, int y) { return 1ll * fac[x] * ifac[x - y] % MOD * ifac[y] % MOD; }

int F[MAXN], G[MAXN];
inline void solve() {
    dfs(1, 0);
    int pw = ksm(n, MOD - 2); per(i, n - 1, 0) { G[i] = 1ll * pw * f[1][i].y % MOD; pw = 1ll * pw * n % MOD; }
    REP(i, 0, n) REP(j, i, n) {
        if((j - i) & 1) Sub(F[i], 1ll * C(j, i) * G[j] % MOD);
        else Add(F[i], 1ll * C(j, i) * G[j] % MOD);
    }
    print(F, F + n);
}

signed main() { init(); solve(); }