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
#define counti(x) (__builtin_popcount(x))
#define countl(x) (__builtin_popcountll(x))
#define clz(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctz(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))

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

#define N 1000005

int id[N], dp[N], c[N], v[N];
int mc[20][N], mv[20][N];

int get_c(int st, int en) {
  if (st == en) return mc[0][st];
  int k = 31 - clz(en-st+1);
  return min(mc[k][st], mc[k][en-bit(k)+1]);
}

int get_v(int st, int en) {
  if (st == en) return mv[0][st];
  int k = 31 - clz(en-st+1);
  return max(mv[k][st], mv[k][en-bit(k)+1]);
}

bool cmp(int u, int v) {
  if (dp[u] != dp[v]) return dp[u] < dp[v];
  return u < v;
}

int main() {

  int n, m;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) scanf("%d", &v[i]), v[i] *= 100;
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

  for (int i = 1; i <= n; i++) mc[0][i] = c[i], mv[0][i] = v[i];
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= n; j++) {
      mc[i][j] = mc[i-1][j], mv[i][j] = mv[i-1][j];
      if (j + bit(i-1) <= n) {
        chkmax(mv[i][j], mv[i-1][j + bit(i-1)]);
        chkmin(mc[i][j], mc[i-1][j + bit(i-1)]);
      }
    }    
  }

  for (int i = 1; i <= n; i++) id[i] = i;
  for (int i = 1; i <= n; i++) {
    if (v[i] >= c[i]) {
      dp[i] = c[i];
      continue;
    }
    if (get_v(i, n) <= get_c(i, n)) {
      dp[i] = get_v(i, n);
      continue;
    }
    int st = i, en = n;
    while (en - st > 1) {
      int mid = st + en >> 1;
      if (get_v(i, mid) <= get_c(i, mid)) st = mid;
      else en = mid;
    }
    dp[i] = max(get_v(i, st), get_c(i, en));
  }

  sort(id + 1, id + n + 1, cmp);

  long double ans = 0;
  long double cur = (long double)m / n;
  for (int i = 1; i <= n - m + 1; i++) {
    ans += (long double)dp[id[i]] * cur;
    cur = cur * (n-i-m+1) / (n-i);
    if (fabs(cur) < 1e-100) break;
  }

  printf("%.7lf\n", (double)ans);
  return 0;
}