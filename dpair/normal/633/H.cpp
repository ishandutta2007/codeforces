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

const int MAXN = 3e4 + 5;
int f[MAXN], m, a[MAXN], n, q;
inline void init() {f[0] = f[1] = 1; rep(i, 2, n) ((f[i] = f[i - 1] + f[i - 2]) >= m) && (f[i] -= m);}
int b[MAXN];

namespace DPair{
int cnt1[256], cnt2[256], cnt3[256], cnt4[256], A[MAXN];
inline void RadixSort(int *a, const int N){//sort N next elements after a (inclusive)
    REP(i, 0, N){ 
        ++ cnt1[a[i] & 255];
        ++ cnt2[a[i] >> 8 & 255];
        ++ cnt3[a[i] >> 16 & 255];
        ++ cnt4[a[i] >> 24 & 255];
    }
    REP(i, 1, 256){
        cnt1[i] += cnt1[i - 1];
        cnt2[i] += cnt2[i - 1];
        cnt3[i] += cnt3[i - 1];
        cnt4[i] += cnt4[i - 1];
    }
    per(i, N - 1, 0) A[-- cnt1[a[i] & 255]] = a[i];
    per(i, N - 1, 0) a[-- cnt2[A[i] >> 8 & 255]] = A[i];
    per(i, N - 1, 0) A[-- cnt3[a[i] >> 16 & 255]] = a[i];
    per(i, N - 1, 0) a[-- cnt4[A[i] >> 24 & 255]] = A[i];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    memset(cnt3, 0, sizeof(cnt3));
    memset(cnt4, 0, sizeof(cnt4));
}
inline void RadixSort(int *a, int *_a){//sort from a to _a (left close right open)
    int N = _a - a, lim = 256; while(N & 3) a[N ++] = INF;
    N > lim? RadixSort(a, N) : std :: sort(a, _a);
}
}
signed main(){
    read(n, m); read(a + 1, a + n + 1); init();
    read(q); while(q --) {
        int l, r; read(l, r); const int len = (r - l + 1);
        memcpy(b, a + l, len * sizeof(int)); DPair :: RadixSort(b, b + len);
        const int p = std :: unique(b, b + len) - b; int ans[4] = {0, 0, 0, 0};
        for (int i = 0;i < p - 3;i += 4) {
            ans[0] = (1ll * b[i    ] * f[i    ] + ans[0]) % m;
            ans[1] = (1ll * b[i + 1] * f[i + 1] + ans[1]) % m;
            ans[2] = (1ll * b[i + 2] * f[i + 2] + ans[2]) % m;
            ans[3] = (1ll * b[i + 3] * f[i + 3] + ans[3]) % m;
        }
        switch(p & 3) {
            case 3: ans[0] = (1ll * b[p - 3] * f[p - 3] + ans[0]) % m;
            case 2: ans[0] = (1ll * b[p - 2] * f[p - 2] + ans[0]) % m;
            case 1: ans[0] = (1ll * b[p - 1] * f[p - 1] + ans[0]) % m;
        }
        print((ans[0] + ans[1] + ans[2] + ans[3]) % m);
    }

}