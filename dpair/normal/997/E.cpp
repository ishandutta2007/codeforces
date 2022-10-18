// da
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


const int MAXN = 1.2e5 + 5;
int n, m, a[MAXN]; LL ans[MAXN];
struct Quest{ int l, r, id; inline bool operator< (const Quest &tmp) const{return r < tmp.r;}}q[MAXN];

struct Segment_tree{
#define LSON rt << 1, l, mid, x, y
#define RSON rt << 1 | 1, mid + 1, r, x, y
LL t[MAXN << 2];
int tag[MAXN << 2], tim[MAXN << 2], s[MAXN << 2], p[MAXN << 2];
inline void pushup(int rt) {
    t[rt] = t[rt << 1] + t[rt << 1 | 1]; p[rt] = mn(p[rt << 1], p[rt << 1 | 1]);
    s[rt] = (p[rt << 1] == p[rt]) * s[rt << 1]; s[rt] += (p[rt << 1 | 1] == p[rt]) * s[rt << 1 | 1];
}
void build(int rt, int l, int r) {
    if(l == r) {s[rt] = 1; p[rt] = l; return ;}
    int mid = (l + r) >> 1; build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r); pushup(rt);
}
inline void update(int rt, int z) {tag[rt] += z; p[rt] += z; }
inline void Update(int rt, int z) {t[rt] += 1ll * z * s[rt]; tim[rt] += z;}
inline void pushdown(int rt) {
    if(tag[rt]) update(rt << 1, tag[rt]), update(rt << 1 | 1, tag[rt]), tag[rt] = 0;
    if(tim[rt]) {
        if(p[rt << 1] == p[rt]) Update(rt << 1, tim[rt]);
        if(p[rt << 1 | 1] == p[rt]) Update(rt << 1 | 1, tim[rt]);
        tim[rt] = 0;
    }
}
void modify(int rt, int l, int r, int x, int y, int z) {
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt); int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, z);
    if(y > mid) modify(RSON, z);
    pushup(rt);
}
LL query(int rt, int l, int r, int x, int y) {
    if(x <= l && r <= y) return t[rt];
    pushdown(rt); int mid = (l + r) >> 1;
    if(x > mid) return query(RSON);
    if(y <= mid) return query(LSON);
    return query(LSON) + query(RSON);
}
#undef LSON
#undef RSON
}t;
int s1[MAXN], s2[MAXN];
signed main(){
    read(n); read(a + 1, a + n + 1); read(m); rep(i, 1, m) {read(q[i].l, q[i].r); q[i].id = i; }
    t.build(1, 1, n); std::sort(q + 1, q + m + 1); int it = 0, t1 = 0, t2 = 0; rep(i, 1, m) {
        while(it < q[i].r) { ++ it;
            while(t1 && a[s1[t1]] < a[it]) t.modify(1, 1, n, s1[t1 - 1] + 1, s1[t1], a[it] - a[s1[t1]]), -- t1;
            while(t2 && a[s2[t2]] > a[it]) t.modify(1, 1, n, s2[t2 - 1] + 1, s2[t2], a[s2[t2]] - a[it]), -- t2;
            s1[++ t1] = s2[++ t2] = it; t.update(1, -1); t.Update(1, 1);
        } ans[q[i].id] = t.query(1, 1, n, q[i].l, q[i].r);
    } printl(ans + 1, ans + m + 1);
}