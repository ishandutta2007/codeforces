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
const int INF = 0x3f3f3f3f;
/* My Code begins here */

const int MAXN = 1e5 + 5;

int n, a[MAXN], L[MAXN], LL[MAXN], p[MAXN];// 
int m, ans[MAXN];

template <typename T>
struct BIT{
    T c[MAXN];
    inline void clear(){memset(c, 0, sizeof(c));}
    inline int lowbit(int x){return x & -x;}
    inline void add(int x, int y){for (;x <= n;x += lowbit(x)) c[x] += y;}
    inline void add(int x){for (;x <= n;x += lowbit(x)) ++ c[x];}
    inline void del(int x){for (;x <= n;x += lowbit(x)) -- c[x];}
    inline void resume(int x){for (;x <= n;x += lowbit(x)) c[x]? c[x] = 0 : x = n + 1;}
    inline T ask(int x){T ret = 0; for (;x;x ^= lowbit(x)) ret += c[x]; return ret;}
    inline T ask(int l, int r) {
        -- l; T ret = 0; 
        while(r > l) ret += c[r], r -= lowbit(r);
        while(l > r) ret -= c[l], l -= lowbit(l);
        return ret;
    }
    inline void build(const int *const a) {rep(i, 1, n) i + lowbit(i) > n? c[i] += a[i] : c[i + lowbit(i)] += (c[i] += a[i]);}
};

BIT < int > t[2];

struct Quest{
    int l, r, id;
    inline bool operator < (const Quest &tmp) const{return r < tmp.r;}
}q[MAXN];

signed main(){
    read(n); read(a + 1, a + n + 1);
    read(m); rep(i, 1, m) {
        q[i].id = i;
        read(q[i].l, q[i].r);
    } std :: sort(q + 1, q + m + 1);
    int it = 0;
    rep(i, 1, m) {
        while(it < q[i].r) {
            const int x = a[++ it];
            if(!L[x]) {t[0].add(L[x] = it);}
            elif(!LL[x]) {t[0].del(LL[x] = L[x]); t[0].add(L[x] = it);}
            else {
                t[0].del(L[x]); t[0].add(it);
                if(L[x] - LL[x] != it - L[x]) {
                    if(p[x]) t[1].del(p[x]);
                    t[1].add(p[x] = LL[x]);
                }
                LL[x] = L[x]; L[x] = it;
            }
        } const int x = t[0].ask(q[i].l, q[i].r);
        ans[q[i].id] = x + (t[1].ask(q[i].l, q[i].r) == x);
    } printl(ans + 1, ans + m + 1);
}
/*



*/