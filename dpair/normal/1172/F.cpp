//
// vector 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
#define gup(x) return puts(#x), 0
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
#define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++)
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
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
inline void printl(T x, Args ...args){fprint(x);putcha(10);print(args...);}
template <typename ...Args>
inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
template <typename ...Args>
inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
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
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
//DPair
// #define int long long
#define MAXN 1000005
int n, m, a[MAXN];
LL s[MAXN], p;
LL buf[MAXN << 4 | 5], *v[MAXN << 2], *ed = buf + sizeof(buf) / sizeof(LL), *fed = buf + (sizeof(buf) / sizeof(LL) >> 1);
inline LL *alloc(int siz){return ed -= siz;}
inline LL *falloc(int siz){return fed -= siz;}
const int alpha = 16;
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

inline void merge(LL *c, LL *x, LL *y, const LL w, const int l1, const int l2){
    for (int i = 0, j = 0;i < l1;++ i){
        for (j == l2 && -- j;j < l2;++ j){// i  j  i 
            if(w - p * i + x[i + 1] - 1 < y[j]){//
                if(j) -- j;
                break;
            }
            c[i + j] = mx(x[i], y[j] - w + p * i);
        }
    }
}

void build(const int rt, const int l, const int r){
    if(r - l + 1 <= alpha) v[rt] = falloc(r - l + 3);
    else v[rt] = alloc(r - l + 3);
    v[rt][0] = -INFll;v[rt][r - l + 2] = INFll;
    if(l == r) return v[rt][1] = p - a[l], void();
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    merge(v[rt], v[rt << 1], v[rt << 1 | 1], s[mid] - s[l - 1], mid - l + 3, r - mid + 2);
}
inline void ADD(LL &x, const int y){if((x += y) >= p) x -= p;}
int x, y;LL z;
void query(const int rt, const int l, const int r){
    if(x <= l && r <= y) {
        if(r - l + 1 <= alpha) rep(i, l, r) ADD(z, a[i]);
        else z += s[r] - s[l - 1] - p * (std :: upper_bound(v[rt], v[rt] + r - l + 3, z) - 1 - v[rt]);
        return ;    
    }
    int mid = (l + r) >> 1;
    if(x > mid) return query(RSON);
    query(LSON);
    if(y > mid) query(RSON);
}
int main(){
    read(n, m, p);read(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i - 1] + a[i];
    build(1, 1, n);
    while(m --){
        read(x, y);z = 0;query(1, 1, n);
        print(z);
    }
}