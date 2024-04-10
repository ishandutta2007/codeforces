// D.D.D. 
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

const int G = 17;
const int lim = 1 << G;
template < bool opt = 0 > 
inline void FWT_or(int *a) {
    for (int mid = 1;mid < lim;mid <<= 1) {
        for (int j = 0;j < lim;j += (mid << 1)) {
            REP(k, 0, mid) {
                if constexpr (opt) Sub(a[k | mid | j], a[k | j]);
                else Add(a[k | mid | j], a[k | j]);
            }
        }
    }
}

template < bool opt = 0 > 
inline void FWT_and(int *a) {
    for (int mid = 1;mid < lim;mid <<= 1) {
        for (int j = 0;j < lim;j += (mid << 1)) {
            REP(k, 0, mid) {
                if constexpr (opt) Sub(a[k | j], a[k | mid | j]);
                else Add(a[k | j], a[k | mid | j]);
            }
        }
    }
}

const int inv2 = ksm(2, MOD - 2);
template < bool opt = 0 > 
inline void FWT_xor(int *a) {
    for (int mid = 1;mid < lim;mid <<= 1) {
        for (int j = 0;j < lim;j += (mid << 1)) {
            REP(k, 0, mid) {
                const int x = a[j | k], y = a[j | mid | k];
                a[j | k] = ADD(x, y); a[j | mid | k] = SUB(x, y);
                if constexpr (opt) {
                    a[j | k] = 1ll * inv2 * a[j | k] % MOD;
                    a[j | mid | k] = 1ll * inv2 * a[j | mid | k] % MOD;
                }
            }
        }
    }
}

int n, A[lim + 5], B[lim + 5], C[lim + 5], D[G + 1][lim + 5], E[G + 1][lim + 5];

int f[lim + 5];

inline void init() { f[1] = 1; REP(i, 2, lim) f[i] = ADD(f[i - 1], f[i - 2]); }

signed main() {
    init();
    read(n); while(n --) { int x; read(x); ++ A[x]; ++ B[x]; ++ C[x]; }

    // part1
    REP(i, 0, lim) D[__builtin_popcount(i)][i] = A[i];
    rep(i, 0, G) FWT_or (D[i]);
    rep(i, 0, G) rep(j, 0, i) REP(k, 0, lim) Add(E[i][k], 1ll * D[j][k] * D[i - j][k] % MOD);
    rep(i, 0, G) FWT_or < 1 > (E[i]);
    REP(i, 0, lim) A[i] = E[__builtin_popcount(i)][i];

    // part3
    FWT_xor (C); REP(i, 0, lim) C[i] = 1ll * C[i] * C[i] % MOD;
    FWT_xor < 1 > (C);

    REP(i, 0, lim) {
        A[i] = 1ll * A[i] * f[i] % MOD;
        B[i] = 1ll * B[i] * f[i] % MOD;
        C[i] = 1ll * C[i] * f[i] % MOD;
    }

    FWT_and (A); FWT_and (B); FWT_and (C);
    REP(i, 0, lim) A[i] = 1ll * A[i] * B[i] % MOD * C[i] % MOD;
    FWT_and < 1 > (A);
    int ans = 0; for (int i = 1;i < lim;i <<= 1) Add(ans, A[i]);
    print(ans);
}