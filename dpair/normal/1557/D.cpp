// 
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

int n, m;
struct DPair{
    int l, r;
    DPair (int l, int r) : l(l), r(r) {}
};

#include <vector> 
using vi = std::vector < DPair >;

const int MAXN = 5e5 + 5;
int t[MAXN * 30], lc[MAXN * 30], rc[MAXN * 30], tag[MAXN * 30], tot;
int dp[MAXN], pre[MAXN], L = 1e9 + 7, R;
inline void pushup(int rt) {t[rt] = (dp[t[lc[rt]]] > dp[t[rc[rt]]]? t[lc[rt]] : t[rc[rt]]);}
inline void update(int &rt, int z) {
    if(!rt) rt = ++ tot;
    t[rt] = tag[rt] = z;
}
inline void pushdown(int rt) {if(tag[rt]) {update(lc[rt], tag[rt]); update(rc[rt], tag[rt]); tag[rt] = 0; }}
#define LSON lc[rt], l, mid, x, y
#define RSON rc[rt], mid + 1, r, x, y
void modify(int &rt, int l, int r, int x, int y, int z) {
    if(!rt) rt = ++ tot;
    if(x <= l && r <= y) return update(rt, z);
    int mid = (l + r) >> 1; pushdown(rt);
    if(x <= mid) modify(LSON, z);
    if(y > mid) modify(RSON, z);
    pushup(rt);    
}

int query(int rt, int l, int r, int x, int y) {
    if(!rt) return 0;
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1; pushdown(rt);
    if(x > mid) return query(RSON);
    if(y <= mid) return query(LSON);
    const int s = query(LSON), o = query(RSON);
    return dp[s] > dp[o]? s : o;
}
vi v[MAXN];
bool vis[MAXN];
signed main(){ int root = 0;
    read(n, m); rep(i, 1, m) {
        int p, l, r; read(p, l, r); chmax(R, r); chmin(L, l);
        v[p].push_back(DPair(l, r));
    } int pos = 0; rep(i, 1, n) { int x = 0;
        for (auto it : v[i]) {
            const int y = query(root, L, R, it.l, it.r);
            if(dp[x] < dp[y]) x = y;
        }
        dp[i] = dp[x] + 1; pre[i] = x; if(dp[i] > dp[pos]) pos = i;
        for (auto it : v[i]) modify(root, L, R, it.l, it.r, i);
    } print(n - dp[pos]);
    if(dp[pos] == n) return 0;
    while(pos) vis[pos] = 1, pos = pre[pos];
    rep(i, 1, n) if(!vis[i]) sprint(i);
    print();
}