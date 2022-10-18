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
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

#define int long long
int n; double p;

inline int C3(int x) { return x * (x - 1) * (x - 2) / 6; }
inline int C2(int x) { return x * (x - 1) / 2; }
inline int C1(int x) { return x; }

inline double calc(const int x) {
    const int k = x;
    return C3(x) + C1(n - k) * C2(x) + C2(n - k) * C1(x) * 0.5;
}

signed main() {
    scanf("%lld%lf", &n, &p);
    const double t = p * C3(n); rep(i, 0, n) { if(calc(i) >= t) return printf("%lld\n", i), 0; } 

}