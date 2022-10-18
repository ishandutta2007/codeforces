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
/* My Code begins here */

const int MAXN = 2e5 + 5;

int s1[MAXN], s2[MAXN], s3[MAXN], a[MAXN];

const int MOD = 1e9 + 7;
inline void Sub(int &x, const int y) {((x -= y) < 0) && (x += MOD);}
inline void Add(int &x, const int y) {((x += y) >= MOD) && (x -= MOD);}
inline int SUB(int x, const int y) {((x -= y) < 0) && (x += MOD); return x;}
inline int ADD(int x, const int y) {((x += y) >= MOD) && (x -= MOD); return x;}

int b1[MAXN], b2[MAXN], b3[MAXN];

#include <unordered_map>
std::unordered_map < int, int > pos;

inline bool judge(const int x, const int l, const int r) {
    if(pos.find(x) == pos.end()) return 0;
    const int p = pos[x];

    if(l <= p && p <= r) return 1;
    else return 0;
}

inline int calc1(const int n, const int k, const int x) { return (1ll * n * x % MOD + 1ll * k * b1[n - 1] % MOD) % MOD; }
inline int calc2(const int n, const int k, const int x) { return (1ll * n * x % MOD * x % MOD + 1ll * k * k % MOD * b2[n - 1] % MOD + 2ll * x * k % MOD * b1[n - 1] % MOD) % MOD; }
inline int calc3(const int n, const int k, const int x) {
    return (1ll * n * x % MOD * x % MOD * x % MOD + 1ll * k * k % MOD * k % MOD * b3[n - 1] % MOD + 
            3ll * x * x % MOD * k % MOD * b1[n - 1] % MOD + 3ll * x * k % MOD * k % MOD * b2[n - 1] % MOD) % MOD;
}
int n, q;

signed main() {
    read(n, q); read(a + 1, a + n + 1);
    rep(i, 1, n) {
        s1[i] = ADD(s1[i - 1], a[i]);
        s2[i] = (1ll * a[i] * a[i] + s2[i - 1]) % MOD;
        s3[i] = (1ll * a[i] * a[i] % MOD * a[i] + s3[i - 1]) % MOD;

        b1[i] = ADD(b1[i - 1], i);
        b2[i] = (1ll * i * i + b2[i - 1]) % MOD;
        b3[i] = (1ll * i * i % MOD * i + b3[i - 1]) % MOD;

        pos[a[i]] = i;
    }

    while(q --) {
        int l, r, k; read(l, r, k);
        const int key = a[l];
        int L = 1, R = r - l + 1, ans = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            if(judge((1ll * mid * k + key) % MOD, l, r)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        const int u = ans;

        L = 1, R = r - l + 1, ans = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            if(judge(SUB(key, 1ll * mid * k % MOD), l, r)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }


        const int d = ans;
        if(r - l + 1 != u + d + 1) { print("No"); continue; }

        const int x = SUB(key, 1ll * d * k % MOD);
        const int S3 = SUB(s3[r], s3[l - 1]), S2 = SUB(s2[r], s2[l - 1]), S1 = SUB(s1[r], s1[l - 1]);

        if(calc1(r - l + 1, k, x) == S1 && calc2(r - l + 1, k, x) == S2 && calc3(r - l + 1, k, x) == S3) print("Yes");
        else print("No");
    }
}