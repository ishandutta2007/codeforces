// 
#pragma GCC optimize(2, 3, "Ofast")
#include <assert.h>
#include <ctime>
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
#define flush() fwrite(out, 1, Out - out, stdout)
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
/* My Code begins here */

const int MAXN = 1e6 + 5;
int n;
char a[MAXN], b[MAXN], c[MAXN];
int t[MAXN];
inline void work() {
    read(n); read(a + 1); read(b + 1); read(c + 1);
    int ca[2] = {0, 0}, cb[2] = {0, 0}, cc[2] = {0, 0};
    rep(i, 1, n << 1) {
        ++ ca[a[i] ^ 48];
        ++ cb[b[i] ^ 48];
        ++ cc[c[i] ^ 48];
        t[i] = 0;
    }
    if(ca[1] >= n && cb[1] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(a[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(b[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(ca[1], cb[1])) {
            while(t[i] --) putcha(48);
            putcha(49);
        }
        while(t[mx(ca[1], cb[1]) + 1] --) putcha(48);
        putcha(10); return ;
    }
    if(ca[1] >= n && cc[1] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(a[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(c[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(ca[1], cc[1])) {
            while(t[i] --) putcha(48);
            putcha(49);
        }
        while(t[mx(ca[1], cc[1]) + 1] --) putcha(48);
        putcha(10); return ;
    }
    if(cc[1] >= n && cb[1] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(b[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(c[i] == '0') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(cc[1], cb[1])) {
            while(t[i] --) putcha(48);
            putcha(49);
        }
        while(t[mx(cc[1], cb[1]) + 1] --) putcha(48);
        putcha(10); return ;
    }
    if(ca[0] >= n && cb[0] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(a[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(b[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(ca[0], cb[0])) {
            while(t[i] --) putcha(49);
            putcha(48);
        }
        while(t[mx(ca[0], cb[0]) + 1] --) putcha(49);
        putcha(10); return ;
    }
    if(ca[0] >= n && cc[0] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(a[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(c[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(ca[0], cc[0])) {
            while(t[i] --) putcha(49);
            putcha(48);
        }
        while(t[mx(ca[0], cc[0]) + 1] --) putcha(49);
        putcha(10); return ;
    }
    if(cc[0] >= n && cb[0] >= n) {
        int cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(b[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);
        cnt = 0, tot = 0; rep(i, 1, n << 1) {
            if(c[i] == '1') ++ cnt;
            else chmax(t[++ tot], cnt), cnt = 0;
        }
        chmax(t[++ tot], cnt);

        rep(i, 1, mx(cc[0], cb[0])) {
            while(t[i] --) putcha(49);
            putcha(48);
        }
        while(t[mx(cc[0], cb[0]) + 1] --) putcha(49);
        putcha(10); return ;
    }
}

signed main() {
    int T = read();
    while(T --) work();
}