#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 222222;
const long double inf = 1e18;
const long double eps = 1e-6;

struct PT {
  long double x, y;
  PT(long double x=0, long double y=0) : x(x), y(y) {}
}q[MAXN];

long double cross(PT p, PT p1, PT p2) {
  return (p1.x-p.x) * (p2.y-p.y) - (p1.y-p.y) * (p2.x-p.x);
}

long double calc(PT p, long double x) {
  return p.y - p.x*x;
}

long double A[MAXN], B[MAXN], dp[2][MAXN], s[MAXN];

int main() {
	
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int t; scanf("%d", &t);
    long double x = (long double)t;
    s[i] = s[i-1] + x;
    A[i] = A[i-1] + s[i]/x;
    B[i] = B[i-1] + (long double)1.0/x;
  }
  int now = 0;
  for (int i = 1; i <= n; i++) {
    dp[now][i] = inf;
  }
  for (int i = 1; i <= m; i++) {
    now ^= 1;
    int h = 0, t = 0;
    for (int j = 1; j <= n; j++) {
      if (dp[!now][j-1] < inf) {
        PT tp(s[j-1], dp[!now][j-1]-A[j-1]+B[j-1]*s[j-1]);
        while (t - h > 1 && cross(q[t-2], q[t-1], tp) < eps) {
          t--;
        }
        q[t++] = tp;
      }
      while (t - h > 1 && calc(q[h], B[j]) > calc(q[h+1], B[j]) - eps) {
        h++;
      }
      if (t > h) {
        dp[now][j] = calc(q[h], B[j]) + A[j];
      } else {
        dp[now][j] = inf;
      }
    }
  }
  printf("%.10lf\n", (double)dp[now][n]);
	return 0;
}