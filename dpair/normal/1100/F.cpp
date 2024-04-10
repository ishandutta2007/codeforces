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
inline void chmin(T &x, const T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, const T y) {(x < y) && (x = y);}
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
    T x = 0;
    char c = getcha();
    while(c > 57 || c < 48) c = getcha();
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
    return x;
}
template <typename T>
inline void read(T &x){
    x = 0;
    char c = getcha();
    while(c > 57 || c < 48) c = getcha();
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
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

const int MAXN = 5e5 + 5;
struct Quest{
    int l, r, id;
    inline bool operator < (const Quest &tmp) const {return r < tmp.r;}
}q[MAXN];

int n, m, ans[MAXN], a[MAXN];
int b[25], p[25];
inline void swap(int &x, int &y){x ^= y ^= x ^= y;}

namespace DPair{
int cnt1[256], cnt2[256], cnt3[256];
Quest A[MAXN];
inline void RadixSort(Quest *a, const int N){//sort N next elements after a (inclusive)
    REP(i, 0, N){
        ++ cnt1[a[i].r & 255];
        ++ cnt2[a[i].r >> 8 & 255];
        ++ cnt3[a[i].r >> 16 & 255];
    }
    REP(i, 1, 256){
        cnt1[i] += cnt1[i - 1];
        cnt2[i] += cnt2[i - 1];
        cnt3[i] += cnt3[i - 1];
    }
    per(i, N - 1, 0) A[-- cnt1[a[i].r & 255]] = a[i];
    per(i, N - 1, 0) a[-- cnt2[A[i].r >> 8 & 255]] = A[i];
    per(i, N - 1, 0) A[-- cnt3[a[i].r >> 16 & 255]] = a[i];
    memcpy(a, A, N * sizeof(Quest));
}
inline void RadixSort(Quest *a, Quest *_a){//sort from a to _a (left close right open)
    const int N = _a - a;
    RadixSort(a, N);
}
}

signed main(){
    read(n); read(a + 1, a + n + 1); read(m); rep(i, 1, m) {read(q[i].l, q[i].r); q[i].id = i; }
    DPair :: RadixSort(q + 1, q + m + 1);
    int it = 0; rep(i, 1, m) {
        while(it < q[i].r) {
            int x = a[++ it], y = it;
            per(j, 20, 0) {
                if(x >> j) {
                    if(!b[j]) {b[j] = x; p[j] = y; break; }
                    elif(p[j] < y) swap(p[j], y), swap(b[j], x);
                    x ^= b[j];
                }
            }
        }
        int res = 0;
        per(j, 20, 0) chmax(res, (p[j] >= q[i].l) * (res ^ b[j]));
        ans[q[i].id] = res;
    }
    printl(ans + 1, ans + m + 1);
}