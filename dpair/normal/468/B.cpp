// Christopher, where are you?
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
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

const int MAXN = 2e5 + 5;

int head[MAXN], nxt[MAXN << 2], cnt, e[MAXN << 2];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int dep, dfn[MAXN], col[MAXN], cnt_col, low[MAXN];
bool ins[MAXN];
int stk[MAXN], tp;

void tarjan(int x){
    dfn[x] = low[x] = ++ dep;
    ins[x] = 1; stk[++ tp] = x;
    for (int i = head[x];i;i = nxt[i]){
        if(!dfn[e[i]]){
            tarjan(e[i]);
            low[x] = mn(low[x], low[e[i]]);
        }
        if(ins[e[i]]) low[x] = mn(low[x], low[e[i]]);
    }
    if(dfn[x] == low[x]){
        int cur;cnt_col ++;
        do{
            cur = stk[tp --]; ins[cur] = 0;
            col[cur] = cnt_col;
        }while(cur ^ x);
    }
}


int A, B, a[MAXN], n;

#include <unordered_map>
std :: unordered_map < int, int > b; 

int ans[MAXN], vis[MAXN];

signed main(){
    read(n, A, B); read(a + 1, a + n + 1);
    rep(i, 1, n) b[a[i]] = i;
    rep(i, 1, n) {
        const int ck1 = b[A - a[i]];
        const int ck2 = b[B - a[i]];
        if(!ck1 && !ck2) return print("NO"), 0;
        if(ck1 && ck2) {
            add(i, ck1);
            add(i, ck2);
            add(i + n, ck1 + n);
            add(i + n, ck2 + n);
        } elif(ck1) {
            add(i + n, i);
            add(ck1 + n, ck1);
        } elif(ck2) {
            add(i, i + n);
            add(ck2, ck2 + n);
        }
    }

    rep(i, 1, (n << 1)) if(!dfn[i]) tarjan(i);
    rep(i, 1, n) if(col[i] == col[i + n]) return print("NO"), 0;
    rep(i, 1, n) ans[i] = col[i] > col[i + n];
    print("YES"); print(ans + 1, ans + n + 1);
}