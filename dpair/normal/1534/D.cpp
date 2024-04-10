//
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

typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */
const int MAXN = 2e3 + 5;
int n, a[MAXN], b[MAXN];

inline void ask(const int x, int *tmp) {
    printf("? %d\n", x);
    fflush(stdout);
    rep(i, 1, n) scanf("%d", tmp + i);
}

int cnt[2];

int c, u[MAXN], v[MAXN];

signed main(){
    scanf("%d", &n); ask(1, a); rep(i, 1, n) ++ cnt[a[i] & 1];
    int tar = 0; if(cnt[0] > cnt[1]) tar = 1;
    else {rep(j, 1, n) if(a[j] == 1){++ c; u[c] = 1; v[c] = j;} }
    rep(i, 2, n) {if((a[i] & 1) == tar) {ask(i, b); rep(j, 1, n) {if(b[j] == 1) {++ c; u[c] = i; v[c] = j; }}}}
    printf("!\n");
    rep(i, 1, c) printf("%d %d\n", u[i], v[i]);
    fflush(stdout);
}