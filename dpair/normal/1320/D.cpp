/*

 1  1  0 
 1  0 

 0 
 01  George 
*/
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
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

const int MAXN = 2e5 + 5;

int n, q;

char s[MAXN];

int b[MAXN];//  0 

const int MOD1 = 998244353;
const int MOD2 = 1019260817;

const int base1 = 131;
const int base2 = 193;

int b1[MAXN], b2[MAXN];
int h1[2][MAXN], h2[2][MAXN];

inline void init() {
    b1[0] = b2[0] = 1;
    rep(i, 1, n) b1[i] = 1ll * b1[i - 1] * base1 % MOD1, b2[i] = 1ll * b2[i - 1] * base2 % MOD2;
    rep(i, 1, n) if(s[i] == 48) {
        h1[0][i] = (1ll * h1[0][i - 1] * base1 + (i & 1))% MOD1;
        h1[1][i] = (1ll * h1[1][i - 1] * base1 + ((i & 1) ^ 1))% MOD1;
        h2[0][i] = (1ll * h2[0][i - 1] * base2 + (i & 1))% MOD2;
        h2[1][i] = (1ll * h2[1][i - 1] * base2 + ((i & 1) ^ 1))% MOD2;
    } else {
        h1[0][i] = h1[0][i - 1];
        h1[1][i] = h1[1][i - 1];
        h2[0][i] = h2[0][i - 1];
        h2[1][i] = h2[1][i - 1];
    }
}

inline bool judge(const int l1, const int r1, const int l2, const int r2, const int len) {
    const int H11 = (h1[l1 & 1][r1] - 1ll * h1[l1 & 1][l1 - 1] * b1[len] % MOD1 + MOD1) % MOD1;
    const int H12 = (h2[l1 & 1][r1] - 1ll * h2[l1 & 1][l1 - 1] * b2[len] % MOD2 + MOD2) % MOD2;

    const int H21 = (h1[l2 & 1][r2] - 1ll * h1[l2 & 1][l2 - 1] * b1[len] % MOD1 + MOD1) % MOD1;
    const int H22 = (h2[l2 & 1][r2] - 1ll * h2[l2 & 1][l2 - 1] * b2[len] % MOD2 + MOD2) % MOD2;

    return H11 == H21 && H12 == H22;
}

signed main(){
    read(n); read(s + 1); read(q);
    rep(i, 1, n) b[i] = b[i - 1] + (s[i] == 48);
    init(); while(q --) {
        int l1, r1, l2, r2, len; read(l1, l2, len); r1 = l1 + len - 1; r2 = l2 + len - 1;
        if(b[r2] - b[l2 - 1] != b[r1] - b[l1 - 1]) {print("No"); continue; }
        if(judge(l1, r1, l2, r2, b[r1] - b[l1 - 1])) print("Yes");
        else print("No");
    }
}