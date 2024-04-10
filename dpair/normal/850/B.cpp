// 
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
namespace IO {
struct IN {
    static const int DPAIRSIZ = 1 << 18;
    inline char getcha() {
        static char BB[DPAIRSIZ], *SS = BB, *TT = BB;
        return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS ++;
    }

    template <typename T>
    inline IN &operator>> (T &x) {
        x = 0; char c = getcha();
        while(c < 48) { c = getcha(); }
        while(c >= 48) { x = x * 10 + c - 48; c = getcha(); }
        return *this;
    }

    inline IN &operator>> (char &ch) {
        ch = getcha();
        while(ch <= 32) ch = getcha();
        return *this;
    }
    inline IN &operator>> (char *s) {
        char ch = getcha(); while(ch <= 32) ch = getcha();
        while(ch > 32) *s ++ = ch, ch = getcha();
        *s = '\0'; return *this;
    }
    inline void getline(char *s) {
        char ch = getcha(); while(ch < 32) ch = getcha();
        while(ch >= 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
}cin;
struct OUT{
    static const int DPAIRSIZ = 1 << 18;
    char out[DPAIRSIZ], *Out = out;
    inline void flush() { fwrite(out, 1, Out - out, stdout); Out = out; }
    inline void putcha(int x) { *Out++ = x; if(Out - out >= (DPAIRSIZ)) flush(); }
    template <typename T>
    inline OUT &operator<< (const T x) {
        if(x > 9) *this << (x / 10);
        putcha(x % 10 + 48); return *this;
    }
    inline OUT &operator<< (const char ch) { putcha(ch); return *this; }
    inline OUT &operator<< (char *ch) { 
        while(*ch != '\0') putcha(*(ch ++));
        return *this;
    }
    inline OUT &operator<< (const char *ch) { 
        while(*ch != '\0') putcha(*(ch ++));
        return *this;
    }
    ~OUT() { flush(); }
}cout;
inline char getcha() { return cin.getcha(); }
inline void putcha(int c) { cout.putcha(c); }
}
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

const int MAXN = 2e6 + 5;
int n, x, y;

int s[MAXN]; LL t[MAXN];

signed main() {
    cin >> n >> y >> x; int V = 0; rep(i, 1, n) { int o; cin >> o; ++ s[o]; t[o] += o; chmax(V, o); }
    REP(i, 1, MAXN) s[i] += s[i - 1], t[i] += t[i - 1];
    LL ans = INFll; const int z = y / x; rep(k, 2, V + 1) {
        LL ret = 0; int pos = mn(z, k - 1);
        for (int l = 1, r = k; l <= V; l += k, r += k) {
            ret += 1ll * y * (s[r - pos - 1] - s[l - 1]) + 1ll * x * (1ll * r * (s[r] - s[r - pos - 1]) - t[r] + t[r - pos - 1]);
        }
        chmin(ans, ret);
    } cout << ans << '\n';
}