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
const int MAXN = 1e6 + 5;
int n, m, a[MAXN];
struct Quest{
    int l, r, id;
    Quest (int l = 0, int r = 0) : l(l), r(r){}
}q[MAXN];


int L[MAXN], R[MAXN], stk[MAXN], tp;
LL ans[MAXN];

struct DAT{
    LL x; int y;
    DAT (LL x = 0, int y = 0) : x(x), y(y) {}
}c[MAXN];
struct NODE{
    int x, y;
    NODE (int x = 0, int y = 0) : x(x), y(y){}
}p[MAXN];
inline int lowbit(int x){return x & -x;}
signed main(){
    read(n, m); read(a + 1, a + n + 1);
    rep(i, 1, m) read(q[i].l);
    rep(i, 1, m) read(q[i].r); 
    rep(i, 1, m) q[i].id = i, ans[i] = q[i].r - q[i].l + 1;
    a[0] = INF; rep(i, 1, n) {
        while(a[stk[tp]] < a[i]) R[stk[tp --]] = i;
        L[i] = stk[tp]; stk[++ tp] = i;
    }
    while(tp) R[stk[tp --]] = n + 1;
    rep(i, 1, n) -- R[i], ++ L[i];

    rep(i, 1, n) p[i] = NODE(i, R[i]);
    std :: sort(q + 1, q + m + 1, [](const Quest &x, const Quest &y){return x.r < y.r; }); 
    std :: sort(p + 1, p + n + 1, [](const NODE &x, const NODE &y){return x.y < y.y; });
    int it = 1, itt = 1; rep(i, 1, n) {
        while(it <= n && p[it].y == i) {
            const int I = p[it ++].x, v = R[I];
            for (int j = I;j <= n;j += lowbit(j)) {-- c[j].y; c[j].x += v; }
        } for (int j = i;j <= n;j += lowbit(j)) ++ c[j].y;
        while(itt <= m && q[itt].r == i) {
            const int ID = q[itt].id, l = q[itt].l - 1, r = q[itt ++].r;
            for (int j = r;j;j -= lowbit(j)) {ans[ID] += c[j].x + 1ll * i * c[j].y; }
            for (int j = l;j;j -= lowbit(j)) {ans[ID] -= c[j].x + 1ll * i * c[j].y; }
        } if(itt > m) break;
    }

    rep(i, 1, n) p[i] = NODE(i, L[i]), c[i] = DAT();
    std :: sort(q + 1, q + m + 1, [](const Quest &x, const Quest &y){return x.l > y.l; }); 
    std :: sort(p + 1, p + n + 1, [](const NODE &x, const NODE &y){return x.y > y.y; });
    it = 1, itt = 1; per(i, n, 1) {
        while(it <= n && p[it].y == i) {
            const int I = p[it ++].x, v = L[I];
            for (int j = I;j <= n;j += lowbit(j)) {-- c[j].y; c[j].x += v; }
        } for (int j = i;j <= n;j += lowbit(j)) ++ c[j].y;
        while(itt <= m && q[itt].l == i) {
            const int ID = q[itt].id, l = q[itt].l - 1, r = q[itt ++].r;
            for (int j = r;j;j -= lowbit(j)) {ans[ID] -= c[j].x + 1ll * i * c[j].y; }
            for (int j = l;j;j -= lowbit(j)) {ans[ID] += c[j].x + 1ll * i * c[j].y; }
        } if(itt > m) break;
    }

    print(ans + 1, ans + m + 1);
}
//time test
/*

sum(min(r, R_i)) - sum(max(l, L_i))
*/