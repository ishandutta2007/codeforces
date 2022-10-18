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

const int block = 350;
const int MAXN = 100005;
const int B = MAXN / block + 5;

int lst[B], bel[MAXN], c[B][MAXN >> 2];
int n, q, a[MAXN], m;
int ans[B][B];

int b[MAXN << 1], p[MAXN >> 2], tot, *pr;
const int lim = 405;
int st[lim], cc, res, tar[MAXN << 1], num[lim];
inline void sieve() {
    b[1] = 1; rep(i, 2, m) {
        if(!b[i]) p[++ tot] = i;
        for (int j = 1;j <= tot && p[j] * i <= m;++ j) {
            b[p[j] * i] = p[j];
            if(i % p[j] == 0) break;
        }
    }
    for (int j = 1;j <= tot && p[j] * p[j] <= m;++ j) {
        st[j] = st[j - 1];
        int x = 1; while((x *= p[j]) <= m) num[++ st[j]] = x;
        cc = st[j]; res = j;
    }
    rep(i, res + 1, tot) tar[p[i]] = i - res;
}
int cur[MAXN >> 1];
int s[MAXN][lim];
const int MOD = 1e9 + 7;
signed main(){
    read(n); read(a + 1, a + n + 1);
    rep(i, 1, n) bel[i] = (i - 1) / block + 1;
    rep(i, 1, bel[n]) lst[i] = mn(n, i * block);
    rep(i, 1, n) chmax(m, a[i]);
    sieve(); rep(i, 1, n) {
        int x = a[i]; rep(j, 1, res){
            int cnt = 0;
            while(x % p[j] == 0) {
                x /= p[j];
                ++ cnt;
            } if(cnt) ++ s[i][st[j - 1] + cnt];
        }
        rep(j, 1, cc) s[i][j] += s[i - 1][j];
        if(x > 1) ++ cur[tar[x]], a[i] = tar[x];
        else a[i] = 0;
        if(i == lst[bel[i]]) {
            const int id = bel[i];
            memcpy(c[id] + 1, cur + 1, (tot - res) * sizeof(int));
        }
    }
    rep(i, 1, bel[n]) { memset(cur, 0, sizeof(cur));
        ans[i][i - 1] = 1; rep(j, i, bel[n]) {
            ans[i][j] = ans[i][j - 1];
            rep(k, lst[j - 1] + 1, lst[j]) if(a[k] && !cur[a[k]]) cur[a[k]] = 1, ans[i][j] = 1ll * ans[i][j] * p[a[k] + res] % MOD;
        }
    }
    memset(cur, 0, sizeof(cur)); int lans = 0; read(q); while(q --) {
        int l = (read() + lans) % n + 1;
        int r = (read() + lans) % n + 1;
        if(l > r) l ^= r ^= l ^= r;
        int ret = 1;
        rep(j, 1, res) PER(k, st[j], st[j - 1]) {
            if(s[r][k] - s[l - 1][k]) {
                ret = 1ll * ret *  num[k] % MOD;
                break;
            }
        }
        const int L = bel[l], R = bel[r]; if(L == R) {
            rep(j, l, r) if(a[j] && !cur[a[j]]) cur[a[j]] = 1, ret = 1ll * ret * p[a[j] + res] % MOD;
            rep(j, l, r) cur[a[j]] = 0;
        } else {
            ret = 1ll * ans[L + 1][R - 1] * ret % MOD;
            rep(j, l, lst[L]) if(a[j] && !(cur[a[j]] || (c[R - 1][a[j]] - c[L][a[j]]))) cur[a[j]] = 1, ret = 1ll * ret * p[a[j] + res] % MOD;
            rep(j, lst[R - 1] + 1, r) if(a[j] && !(cur[a[j]] || (c[R - 1][a[j]] - c[L][a[j]]))) cur[a[j]] = 1, ret = 1ll * ret * p[a[j] + res] % MOD;
            rep(j, l, lst[L]) cur[a[j]] = 0;
            rep(j, lst[R - 1] + 1, r) cur[a[j]] = 0;
        } print(lans = ret);
    }
}