/*

















































*/
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) { return x < y ? x : y; }
template <typename T>
inline T mx(const T x, const T y) { return x > y ? x : y; }
template <typename T>
inline bool chmin(T &x, const T y) { return (x > y) && ((x = y), 1); }
template <typename T>
inline bool chmax(T &x, const T y) { return (x < y) && ((x = y), 1); }
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) { return mx(x, mx(args...)); }
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) { return mn(x, mn(args...)); }
}
using namespace MyMinMax;
namespace IO{
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha() { return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS ++; }

template <typename T = int>
inline T read() {
    T x = 0; char c = getcha();
    while(c <= 32) { c = getcha(); }
    while(c > 32) { x = x * 10 + c - 48; c = getcha(); }
    return x;
}
template <typename T>
inline void read(T &x) {
    x = 0; char c = getcha();
    while(c <= 32) { c = getcha(); }
    while(c > 32) { x = x * 10 + c - 48; c = getcha(); }
}

template <typename T>
inline void read(T *bg, T *ed) { while(bg != ed) read(*bg ++); }
inline void read(char &ch) { ch = getcha(); while(ch <= 32) ch = getcha(); }
inline void read(char *s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void getl(char *s) {
    char ch = getcha(); while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pread(char *&s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pgetl(char *&s) {
    char ch = getcha(); while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}

template <typename T, typename ...Args>
inline void read(T &x, Args &...args) { read(x); read(args...); }

char out[DPAIRSIZ], *Out = out;
inline void flush() { fwrite(out, 1, Out - out, stdout); }
inline void putcha(char x) { *Out++ = x; if(Out - out >= (DPAIRSIZ)) flush(), Out = out; }
template <typename T>
inline void fprint(T x){
    if(x > 9) fprint(x / 10);
    putcha(x % 10 + 48);
}
inline void print(){ putcha(10); }
template <typename T>
inline void print(T x) { fprint(x); putcha(10); }
inline void print(char *ch) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); }
inline void put(char *ch) { while(*ch != '\0') putcha(*(ch ++)); }
inline void print(const char *ch) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); }
inline void put(const char *ch) { while(*ch != '\0') putcha(*(ch ++)); }
template <typename T, typename ...Args>
inline void print(T x, Args ...args) { fprint(x); putcha(32); print(args...); }
template <typename ...Args>
inline void print(const char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(32); print(args...); }
template <typename ...Args>
inline void print(char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(32); print(args...); }
template <typename T, typename ...Args>
inline void printl(T x, Args ...args) { fprint(x); putcha(10); printl(args...); }
template <typename ...Args>
inline void printl(const char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); printl(args...); }
template <typename ...Args>
inline void printl(char *ch, Args ...args) { while(*ch != '\0') putcha(*(ch ++)); putcha(10); printl(args...); }
template <typename T>
inline void sprint(T x) { fprint(x); putcha(32); }
template <typename T, typename ...Args>
inline void sprint(T x, Args ...args) { fprint(x); putcha(32); sprint(args...); }
template <typename T>
inline void sprint(T *bg, T *ed) { while(bg != ed) sprint(*bg ++); }
template <typename T>
inline void print(T *bg, T *ed) { while(bg != ed) sprint(*bg ++); putcha(10); }
template <typename T>
inline void printl(T *bg, T *ed) { while(bg != ed) print(*bg ++); }
class AutoFlush{
    public:
        ~AutoFlush(){flush();}
}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 998244353, G = 3;
inline void Sub(int &x, const int y) {((x -= y) < 0) && (x += MOD);}
inline void Add(int &x, const int y) {((x += y) >= MOD) && (x -= MOD);}
inline int SUB(int x, const int y) {((x -= y) < 0) && (x += MOD); return x;}
inline int ADD(int x, const int y) {((x += y) >= MOD) && (x -= MOD); return x;}
inline int ksm(int x, int y) {
    int ret = 1; while(y) {
        if(y & 1) ret = 1ll * ret * x % MOD;
        y >>= 1; x = 1ll * x * x % MOD;
    } return ret;
}
/* My Code begins here */

int n, len;

const int MAXN = 2e5 + 5;
char buff[MAXN], *s[MAXN];
int buff1[MAXN], buff2[MAXN], *p1[MAXN], *p2[MAXN];

struct Trie {
    int ch[MAXN][26], tot, dfn[MAXN], low[MAXN], total;
    inline int NewNode() { const int rt = ++ tot; memset(ch[rt], 0, sizeof(ch[rt])); return rt; }
    inline int ins(char *c) { int rt = 0; REP(i, 0, len) { rt = (ch[rt][c[i] - 97]? ch[rt][c[i] - 97] : (ch[rt][c[i] - 97] = NewNode())); } return rt; }
    inline void ins(char *c, int *p) { int rt = 0; REP(i, 0, len) { p[i] = rt = (ch[rt][c[i] - 97]? ch[rt][c[i] - 97] : (ch[rt][c[i] - 97] = NewNode())); } }
    inline void rins(char *c, int *p) { int rt = 0; per(i, len - 1, 0) { p[i] = rt = (ch[rt][c[i] - 97]? ch[rt][c[i] - 97] : (ch[rt][c[i] - 97] = NewNode())); } }
    inline void clear() { tot = total = 0; memset(ch[0], 0, sizeof(ch[0])); }
    void dfs(int x) { dfn[x] = ++ total; REP(i, 0, 26) { if(ch[x][i]) dfs(ch[x][i]); } low[x] = total; }
}t1, t2;

#include <vector>
std::vector < int > v[MAXN];

LL ans = 0; int c[MAXN];
inline int lowbit(int x) { return x & -x; }
inline void add(int x) { for(;x <= t2.total;x += lowbit(x)) ++ c[x]; }
inline void del(int x) { for(;x <= t2.total;x += lowbit(x)) -- c[x]; }
inline int ask(int x) { int s = 0; for(;x;x -= lowbit(x)) s += c[x]; return s; }

struct Quest1 {
    int pos, x; Quest1 (int pos = 0, int x = 0) : pos(pos), x(x) {}
    inline bool operator< (const Quest1 &tmp) const { return pos < tmp.pos; }
}q1[MAXN];

struct Quest2 {
    int pos, l, r, val; Quest2 (int pos = 0, int l = 0, int r = 0, int val = 0) : pos(pos), l(l), r(r), val(val) {}
    inline bool operator< (const Quest2 &tmp) const { return pos < tmp.pos; }
}q2[MAXN << 1];

int tot1 = 0, tot2 = 0;
inline void solve(const std::vector < int > &vi) {
    t1.clear(); t2.clear(); const int m = vi.size(); for (auto &it : vi) { t1.ins(s[it], p1[it]); t2.rins(s[it], p2[it]); }
    t1.dfs(0); t2.dfs(0); tot1 = 0; tot2 = 0; for (auto &it : vi) {
        q1[++ tot1] = Quest1(t1.dfn[p1[it][len - 1]], t2.dfn[p2[it][0]]);
        ans += (m - 1) << 1; ans += 1337 * (n - m); int lst = -1; REP(i, 0, len) {
            if(i == len - 1 || s[it][i] > s[it][i + 1]) {
                const int u = ((lst == -1)? 0 : p1[it][lst]), v = ((i == len - 1)? 0 : p2[it][i + 1]);
                if(t1.dfn[u] - 1) q2[++ tot2] = Quest2(t1.dfn[u] - 1, t2.dfn[v], t2.low[v], 2);
                q2[++ tot2] = Quest2(t1.low[u], t2.dfn[v], t2.low[v], -2);
                lst = i; ans += 2;
            }
        }
    }
    std::sort(q1 + 1, q1 + tot1 + 1); std::sort(q2 + 1, q2 + tot2 + 1);
    int it1 = 1, it2 = 1; rep(i, 1, t1.total) {
        while(it1 <= tot1 && q1[it1].pos == i) add(q1[it1 ++].x);
        while(it2 <= tot2 && q2[it2].pos == i) { ans += q2[it2].val * (ask(q2[it2].r) - ask(q2[it2].l - 1)); ++ it2; }
    }
    REP(i, 1, it1) del(q1[i].x);
}

char tmp[MAXN];
signed main() {
    read(n); s[1] = buff; read(s[1]);  len = strlen(s[1]); p1[1] = buff1; p2[1] = buff2; 
    rep(i, 2, n) { s[i] = s[i - 1] + len; p1[i] = p1[i - 1] + len; p2[i] = p2[i - 1] + len; read(s[i]); }
    rep(i, 1, n) {
        memcpy(tmp, s[i], len * sizeof(char));
        std::sort(tmp, tmp + len); const int u = t1.ins(tmp);
        v[u].push_back(i);
    }
    rep(i, 1, t1.tot) if(!v[i].empty()) solve(v[i]); 
    print(ans >> 1);
}
/*

*/