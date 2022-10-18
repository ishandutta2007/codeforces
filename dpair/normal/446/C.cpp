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
const int MOD = 1e9 + 9;
const int MAXN = 3e5 + 5;
int buf[MAXN << 1], *f = buf + MAXN, b[MAXN];
int n, m;
inline void init() {
    b[1] = f[1] = f[2] = 1; b[2] = 2;
    rep(i, 3, n + 1) b[i] = (b[i - 1] + (f[i] = (f[i - 1] + f[i - 2]) % MOD)) % MOD;
    rep(i, 1, n + 1) f[-i] = (i & 1)? f[i] : MOD - f[i];
}
int a[MAXN];
struct NODE{
    int val, t1, t2;
}t[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushup(int rt){t[rt].val = (t[rt << 1].val + t[rt << 1 | 1].val) % MOD;}
void build(int rt, int l, int r) {
    if(l == r) return t[rt].val = a[l], void();
    int mid = (l + r) >> 1;build(LSON);build(RSON);
    pushup(rt);
}
inline void update(int rt, int l, int r, int x, int y){
    t[rt].t1 = (t[rt].t1 + x) % MOD; t[rt].t2 = (t[rt].t2 + y) % MOD;
    t[rt].val = (1ll * x * (b[r + 1] - b[l] + MOD) + 1ll * y * (b[r] - b[l - 1] + MOD) + t[rt].val) % MOD;
}
inline void pushdown(int rt, int l, int r){
    if(t[rt].t1 || t[rt].t2) {
        int mid = (l + r) >> 1;
        update(LSON, t[rt].t1, t[rt].t2);
        update(RSON, t[rt].t1, t[rt].t2);
        t[rt].t1 = t[rt].t2 = 0;
    }
}
void modify(int rt, int l, int r, int x, int y, int z1, int z2) {
    if(x <= l && r <= y) return update(rt, l, r, z1, z2);
    pushdown(rt, l, r); int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z1, z2);
    if(y > mid) modify(RSON, x, y, z1, z2);
    pushup(rt);
}
int query(int rt, int l, int r, int x, int y) {
    if(x <= l && r <= y) return t[rt].val;
    pushdown(rt, l, r); int mid = (l + r) >> 1;
    if(y <= mid) return query(LSON, x, y);
    if(x > mid) return query(RSON, x, y);
    return (query(LSON, x, y) + query(RSON, x, y)) % MOD;
}
signed main(){
    read(n, m); init(); read(a + 1, a + n + 1); build(1, 1, n); while(m --){
        int opt, l, r; read(opt, l, r);
        opt == 1? modify(1, 1, n, l, r, f[1 - l], f[-l]) : print(query(1, 1, n, l, r));
    }
}