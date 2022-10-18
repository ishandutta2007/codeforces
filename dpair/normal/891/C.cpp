//
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

const int MAXN = 5e5 + 5;

int n, m, q;

struct EDGE{
    int u, v, val, id;
    EDGE (int u = 0, int v = 0, int val = 0, int id = 0) : u(u), v(v), val(val), id(id) {}
    inline bool operator < (const EDGE &tmp) const {return val < tmp.val; }
}e[MAXN];

int u[MAXN], v[MAXN], w[MAXN];
int fa[MAXN];
inline int find(int x){return fa[x] == x? x : fa[x] = find(fa[x]);}
struct EDG{
    int u, v, val;
    EDG (int u = 0, int v = 0, int val = 0) : u(u), v(v), val(val) {}
    inline bool operator < (const EDG &tmp) const {return val < tmp.val; }
}E[MAXN];

inline bool jugde(){
    int k = read(); rep(i, 1, k) {
        const int id = read();
        E[i] = EDG(u[id], v[id], w[id]);
    } std :: sort(E + 1, E + k + 1); int lst = 1; rep(i, 1, k) {
        if(E[i].val ^ E[i - 1].val) {
            REP(j, lst, i) {
                if(find(E[j].u) ^ find(E[j].v)) fa[find(E[j].u)] = find(E[j].v);
                else {
                    rep(t, lst, j) fa[E[t].u] = E[t].u, fa[E[t].v] = E[t].v;
                    return 0;
                }
            } REP(j, lst, i) fa[E[j].u] = E[j].u, fa[E[j].v] = E[j].v;
            lst = i;
        }
    } rep(j, lst, k) {
        if(find(E[j].u) ^ find(E[j].v)) fa[find(E[j].u)] = find(E[j].v);
        else {
            rep(t, lst, j) fa[E[t].u] = E[t].u, fa[E[t].v] = E[t].v;
            return 0;
        }
    } rep(j, lst, k) fa[E[j].u] = E[j].u, fa[E[j].v] = E[j].v;
    return 1;
}

signed main(){
    read(n, m); rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        read(e[i].u, e[i].v, e[i].val);
        e[i].id = i;
    } std :: sort(e + 1, e + m + 1); int lst = 1; rep(i, 1, m) {
        if(e[i].val ^ e[i - 1].val) {
            REP(j, lst, i) {
                const int id = e[j].id;
                u[id] = find(e[j].u);
                v[id] = find(e[j].v);
                w[id] = e[j].val;
            } REP(j, lst, i) if(find(e[j].u) ^ find(e[j].v)) fa[find(e[j].u)] = find(e[j].v);
            lst = i;
        }
    } rep(j, lst, m) {
        const int id = e[j].id;
        u[id] = find(e[j].u);
        v[id] = find(e[j].v);
        w[id] = e[j].val;
    } rep(i, 1, n) fa[i] = i;
    read(q); while(q --) print(jugde()? "YES" : "NO");
}