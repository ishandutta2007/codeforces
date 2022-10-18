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
/* My Code begins here */

const int MAXN = 1e6 + 5;
char t[MAXN], s[MAXN];
int m, n;

int h[MAXN][2], b[MAXN][2];
const int MOD[2] = {998244353, 1019260817};
const int base[2] = {131, 173};

inline void init() {    
    b[0][0] = b[0][1] = 1; rep(i, 1, n) {
        b[i][0] = 1ll * b[i - 1][0] * base[0] % MOD[0];
        b[i][1] = 1ll * b[i - 1][1] * base[1] % MOD[1];
        
        h[i][0] = (1ll * h[i - 1][0] * base[0] + s[i]) % MOD[0];
        h[i][1] = (1ll * h[i - 1][1] * base[1] + s[i]) % MOD[1];
    }
}

int f[2][2], len[2];
bool vis[2];

inline void get_hash(int &x, int &y, int l, int r) {
    const int o = (r - l + 1);
    x = (((1ll * h[r][0] - 1ll * h[l - 1][0] * b[o][0]) % MOD[0]) + MOD[0]) % MOD[0];
    y = (((1ll * h[r][1] - 1ll * h[l - 1][1] * b[o][1]) % MOD[1]) + MOD[1]) % MOD[1];
}

inline int judge() {
    vis[0] = vis[1] = 0; memset(f, 0, sizeof(f));
    int it = 1; rep(i, 1, m) {
        const bool x = t[i] ^ 48; int u, v; get_hash(u, v, it, it + len[x] - 1);
        if(!vis[x]) { vis[x] = 1; f[x][0] = u; f[x][1] = v; }
        else if(u != f[x][0] || v != f[x][1]) return 0;
        it += len[x];
    }
    return !(f[0][0] == f[1][0] && f[0][1] == f[1][1]);
}

signed main() {
    read(t + 1); read(s + 1); m = strlen(t + 1); n = strlen(s + 1);
    init(); int c[2] = {0, 0}; rep(i, 1, m) ++ c[t[i] ^ 48];
    if(c[0] < c[1]) { std::swap(c[0], c[1]); rep(i, 1, m) t[i] ^= 1; }
    int ans = 0; rep(k, 1, n / c[0]) {
        len[0] = k; if((n - k * c[0]) % c[1]) continue;
        if(!(len[1] = (n - k * c[0]) / c[1])) continue;
        ans += judge();
    }
    print(ans);
}