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
LL tot = 0; int n, m;
const int block = 355, B = MAXN / block + 5;
int bel[MAXN], lst[B];
LL tag[B], a[MAXN], con[MAXN];
const int lim = 600;
template <typename T>
inline T jdz(T x){return x < 0? -x : x;}
inline LL val(int p){return a[p] + tag[bel[p]];}
bool d[B];//
LL o[B];//
int p[B];//
inline void build(int x) {
    if(x == 1 || x == bel[n]) return ;
    const int l = lst[x - 1], r = lst[x];
    d[x] = 0; p[x] = 0; o[x] = INFll; REP(i, l, r) {
        const bool ck1 = val(i) >= val(i - 1), ck2 = val(i) >= val(i + 1);
        
        if(ck1 && ck2) return d[x] = 1, void();
        elif(ck1 || ck2) chmin(o[x], ck1? val(i + 1) - val(i) : val(i - 1) - val(i));
        else p[x] = i;
    }
}

signed main(){
    read(n); read(a + 1, a + n + 1);
    rep(i, 1, n) bel[i] = (i - 1) / block + 1;
    rep(i, 0, bel[n]) lst[i] = mn(n, i * block) + 1;

    REP(i, 1, n) tot += jdz(a[i] - a[i + 1]);

    REP(i, 2, bel[n]) build(i);
    read(m); while(m --) { int opt, l, r; LL x; read(opt, l, r, x); const int L = bel[l], R = bel[r];
        if(opt == 1) {
            LL ans = -INFll;
            if(l == 1) chmax(ans, jdz(val(1) + x - val(2)) - jdz(val(1) - val(2))), ++ l;
            if(r == n) chmax(ans, jdz(val(n) + x - val(n - 1)) - jdz(val(n) - val(n - 1))), -- r;
            
            if(r - l <= lim) {
                rep(i, l, r) {
                    const LL ll = val(i - 1), mm = val(i), rr = val(i + 1);
                    chmax(ans, jdz(mm + x - ll) + jdz(mm + x - rr) - jdz(mm - ll) - jdz(mm - rr));
                } 
            } else {
                REP(i, l, lst[L]) {
                    const LL ll = val(i - 1), mm = val(i), rr = val(i + 1);
                    chmax(ans, jdz(mm + x - ll) + jdz(mm + x - rr) - jdz(mm - ll) - jdz(mm - rr));
                }
                rep(i, lst[R - 1], r) {
                    const LL ll = val(i - 1), mm = val(i), rr = val(i + 1);
                    chmax(ans, jdz(mm + x - ll) + jdz(mm + x - rr) - jdz(mm - ll) - jdz(mm - rr));
                }

                REP(i, L + 1, R) {
                    if(d[i]) {ans = (x << 1); break; }
                    if(o[i] ^ INFll) chmax(ans, (x - o[i]) > 0? ((x - o[i]) << 1) : 0);
                    if(!p[i]) continue;
                    const LL ll = val(p[i] - 1), mm = val(p[i]), rr = val(p[i] + 1);
                    chmax(ans, jdz(mm + x - ll) + jdz(mm + x - rr) - jdz(mm - ll) - jdz(mm - rr));
                } 
            } print(ans + tot);
        } else {
            if(l > 1) tot -= jdz(val(l) - val(l - 1));
            if(r < n) tot -= jdz(val(r) - val(r + 1));
            if(L == R) { rep(i, l, r) a[i] += x; build(L); }
            else {
                REP(i, l, lst[L]) a[i] += x;
                rep(i, lst[R - 1], r) a[i] += x;
                REP(i, L + 1, R) tag[i] += x;
                build(L); build(R);
            }
            if(l > 1) tot += jdz(val(l) - val(l - 1));
            if(r < n) tot += jdz(val(r) - val(r + 1));
        }
    }
}