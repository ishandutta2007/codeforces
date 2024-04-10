// ~~~~
#pragma GCC optimize(2, 3, "Ofast")
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
    T x = 0; int fu = 1; char c = getcha();
    while(c < 48) { if(c == 45) { fu = -1; } c = getcha(); }
    while(c >= 48) { x = x * 10 + c - 48; c = getcha(); }
    x *= fu; return x;
}
template <typename T>
inline void read(T &x) {
    x = 0; int fu = 1; char c = getcha();
    while(c < 48) { if(c == 45) { fu = -1; } c = getcha(); }
    while(c >= 48) { x = x * 10 + c - 48; c = getcha(); }
    x *= fu;
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
    if(x < 0) putcha(45), x = -x;
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
class AutoFlush {
    public:
        ~AutoFlush() { flush(); }
}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

const int MAXN = 3e5 + 5;
int n, m;

int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }


int dep[MAXN], fa[MAXN], f[MAXN];
void dfs(int x) {
    for (int i = head[x];i;i = nxt[i]) {
        if(dep[e[i]]) continue;
        dep[e[i]] = dep[x] + 1;
        fa[e[i]] = x; dfs(e[i]);
    }
}
int u[MAXN], v[MAXN];

int s1[MAXN], t1, s2[MAXN], t2, d[MAXN];



signed main() {
    read(n, m); while(m --) link(read(), read());
    dep[1] = 1; dfs(1);

    int q = read();
    rep(i, 1, q) {
        read(u[i], v[i]); int x = u[i], y = v[i];
        while(dep[x] > dep[y]) f[x] ^= 1, x = fa[x];
        while(dep[y] > dep[x]) f[y] ^= 1, y = fa[y];
        while(x ^ y) f[x] ^= 1, f[y] ^= 1, x = fa[x], y = fa[y];
    }

    int ans = 0;
    rep(i, 2, n) ans += f[i];

    if(!ans) {
        print("YES");
        rep(i, 1, q) {
            int x = u[i], y = v[i]; t1 = t2 = 0;
            while(dep[x] > dep[y]) s1[++ t1] = x, x = fa[x];
            while(dep[y] > dep[x]) s2[++ t2] = y, y = fa[y];
            while(x ^ y) s1[++ t1] = x, s2[++ t2] = y, x = fa[x], y = fa[y];
            print(t1 + t2 + 1);
            rep(i, 1, t1) sprint(s1[i]);
            sprint(x);
            per(i, t2, 1) sprint(s2[i]);
            print();
        }
    } else { 
        print("NO");
        rep(i, 2, n) d[i] += f[i], d[fa[i]] += f[i];
        ans = 0;
        rep(i, 1, n) ans += (d[i] & 1);
        print(ans >> 1);
    }
}