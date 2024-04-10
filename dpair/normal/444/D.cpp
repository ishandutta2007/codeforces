// 
#pragma GCC optimize(2, 3, "Ofast")
#include <assert.h>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
#define elif else if
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
    T x = 0; int fu = 1; char c = getcha();
    while(c < 48) { if(c == 45) { fu = -1; } c = getcha(); }
    while(c >= 48) { x = x * 10 + c - 48; c = getcha(); }
    x *= fu; return x;
}
template <typename T>
inline void read(T &x) {
    x = 0; int fu = 1; char c = getcha();
    while(c < 48) { if(c == 45) { fu = -1; } c = getcha(); }
    while(c >= 48) { x = x * 10 + c - 48; c = getcha(); }
    x *= fu;
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
    if(x < 0) putcha(45), x = -x;
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
class AutoFlush {
    public:
        ~AutoFlush() { flush(); }
}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
inline int lowbit(int x) { return x & -x; }
/* My Code begins here */


const int MAXN = 50005;
#include <vector>
std::vector < int > v[27 * 27 * 27 * 27 + 5]; // begin pos

int n;
char s[MAXN];
int h[27 * 27 * 27 * 27 + 5];

const int lim = 445;
int ans[MAXN << 2], tot;

inline int len(int x) {
    if(x < 1) return 0;
    if(x < 27) return 1;
    if(x < 27 * 27) return 2;
    if(x < 27 * 27 * 27) return 3;
    return 4;
}

inline void init() {
    rep(i, 1, n) {
        if(i + 3 <= n) v[(s[i] - 96) * 27 * 27 * 27 + (s[i + 1] - 96) * 27 * 27 + (s[i + 2] - 96) * 27 + (s[i + 3] - 96)].push_back(i);
        if(i + 2 <= n) v[(s[i] - 96) * 27 * 27 + (s[i + 1] - 96) * 27 + (s[i + 2] - 96)].push_back(i);
        if(i + 1 <= n) v[(s[i] - 96) * 27 + (s[i + 1] - 96)].push_back(i);
        v[s[i] - 96].push_back(i);
    }
    REP(i, 0, 27 * 27 * 27 * 27) if(!v[i].empty()) h[i] = ++ tot;
}
inline void solve(const int y) {
    memset(ans, 63, sizeof(ans)); const int L = len(y) - 1;
    int p = 0; rep(i, 1, n) {
        if(i + 3 <= n) {
            const int x = (s[i] - 96) * 27 * 27 * 27 + (s[i + 1] - 96) * 27 * 27 + (s[i + 2] - 96) * 27 + (s[i + 3] - 96);
            chmin(ans[h[x]], mx(v[y][p] + L, i + 3) - mn(v[y][p], i) + 1);
            if(p + 1 < v[y].size())
                chmin(ans[h[x]], mx(v[y][p + 1] + L, i + 3) - mn(v[y][p + 1], i) + 1);
            
        }
        if(i + 2 <= n) {
            const int x = (s[i] - 96) * 27 * 27 + (s[i + 1] - 96) * 27 + (s[i + 2] - 96);
            chmin(ans[h[x]], mx(v[y][p] + L, i + 2) - mn(v[y][p], i) + 1);
            if(p + 1 < v[y].size())
                chmin(ans[h[x]], mx(v[y][p + 1] + L, i + 2) - mn(v[y][p + 1], i) + 1);
        }
        if(i + 1 <= n) {
            const int x = (s[i] - 96) * 27 + (s[i + 1] - 96);
            chmin(ans[h[x]], mx(v[y][p] + L, i + 1) - mn(v[y][p], i) + 1);
            if(p + 1 < v[y].size())
                chmin(ans[h[x]], mx(v[y][p + 1] + L, i + 1) - mn(v[y][p + 1], i) + 1);
        }
        const int x = s[i] - 96;
        chmin(ans[h[x]], mx(v[y][p] + L, i) - mn(v[y][p], i) + 1);
        if(p + 1 < v[y].size()) {
            chmin(ans[h[x]], mx(v[y][p + 1] + L, i) - mn(v[y][p + 1], i) + 1);
            if(v[y][p + 1] == i) ++ p;
        }
    }
}


struct Quest {
    int x, y, id;
    Quest (int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
    inline bool operator< (const Quest &tmp) const { return x < tmp.x; }
}q[MAXN << 1];
int res[MAXN << 1];

signed main() {
    read(s + 1); n = strlen(s + 1);
    init();
    int m = read(), tot = 0; rep(k, 1, m) {
        char tmp1[6], tmp2[6]; read(tmp1); read(tmp2);
        int x = 0, y = 0;
        for (char *it = tmp1;*it != '\0';++ it) x = x * 27 + *it - 96;
        for (char *it = tmp2;*it != '\0';++ it) y = y * 27 + *it - 96;
        if(!h[x] || !h[y]) { res[k] = -1; continue; }
        const int l1 = strlen(tmp1), l2 = strlen(tmp2);
        if(v[x].size() <= lim && v[y].size() <= lim) {
            int ret = INF, i = 0, j = 0; const int sz1 = v[x].size(), sz2 = v[y].size();
            chmin(ret, mx(v[x][i] + l1 - 1, v[y][j] + l2 - 1) - mn(v[x][i], v[y][j]) + 1);
            while(i + 1 < sz1 && j + 1 < sz2) {
                if(v[x][i] < v[y][j]) ++ i;
                else ++ j;
                chmin(ret, mx(v[x][i] + l1 - 1, v[y][j] + l2 - 1) - mn(v[x][i], v[y][j]) + 1);
            }
            while(i + 1 < sz1) { ++ i; chmin(ret, mx(v[x][i] + l1 - 1, v[y][j] + l2 - 1) - mn(v[x][i], v[y][j]) + 1); }
            while(j + 1 < sz2) { ++ j; chmin(ret, mx(v[x][i] + l1 - 1, v[y][j] + l2 - 1) - mn(v[x][i], v[y][j]) + 1); }
            res[k] = ret;
        }
        else {
            if(v[x].size() <= lim) std::swap(x, y);
            q[++ tot] = Quest(x, y, k);
        }
    }
    std::sort(q + 1,q + tot + 1);
    rep(i, 1, tot) {
        if(q[i].x != q[i - 1].x) solve(q[i].x);
        res[q[i].id] = ans[h[q[i].y]];
    }

    printl(res + 1, res + m + 1);
}