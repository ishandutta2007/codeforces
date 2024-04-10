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
const int MAXN = 1e5 + 5;
int n, m, k; LL a[MAXN]; int ans[MAXN], cnt = 0, tp[MAXN];
namespace multi {
struct NODE{
    double x; int id;
    NODE(double x = 0, int id = 0) : x(x), id(id){}
    inline bool operator < (const NODE &tmp) const{return x > tmp.x;}
}t[MAXN];
int tot = 0;
inline void ins(const double x, const int y) {t[++ tot] = NODE(x, y);}
inline void solve() {
    std :: sort(t + 1, t + tot + 1);
    for (int i = 1;i <= tot && (m --);++ i) {ans[++ cnt] = t[i].id; }
    std :: sort(ans + 1, ans + cnt + 1, [](const int x, const int y){return tp[x] < tp[y];});
}
}

namespace plus {
struct NODE{
    int pos, x, id;
    NODE(int pos = 0, int x = 0, int id = 0) : pos(pos), x(x), id(id){}
    inline bool operator < (const NODE &tmp) const{return pos < tmp.pos || (pos == tmp.pos && x > tmp.x);}
}t[MAXN];
int tot = 0;
inline void ins(const int x, const int y, const int z) {t[++ tot] = NODE(x, y, z);}
inline void solve() {std :: sort(t + 1, t + tot + 1); rep(i, 1, tot) {const int p = t[i].pos; multi :: ins(1.0 * (a[p] + t[i].x) / a[p], t[i].id); a[p] += t[i].x; } multi :: solve();}
}

namespace assign {
struct NODE{
    int pos, x, id;
    NODE(int pos = 0, int x = 0, int id = 0) : pos(pos), x(x), id(id){}
    inline bool operator < (const NODE &tmp) const{return pos < tmp.pos || (pos == tmp.pos && x > tmp.x);}
}t[MAXN];
int tot = 0;
inline void ins(const int x, const int y, const int z) {t[++ tot] = NODE(x, y, z);}
inline void solve() {
    std :: sort(t + 1, t + tot + 1); rep(i, 1, tot) {
        if(t[i].pos == t[i - 1].pos || t[i].x <= a[t[i].pos]) continue;
        plus :: ins(t[i].pos, t[i].x - a[t[i].pos], t[i].id);
    } plus :: solve();
}
}
signed main(){
    read(k, n, m); read(a + 1, a + k + 1);
    rep(i, 1, n) {
        int opt, x, y; read(opt, x, y); tp[i] = opt;
        if(opt == 1) assign :: ins(x, y, i);
        elif(opt == 2) plus :: ins(x, y, i);
        else multi :: ins(y, i);
    } assign :: solve(); print(cnt); print(ans + 1, ans + cnt + 1);
}