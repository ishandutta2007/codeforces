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
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << endl
#define X first
#define Y second
  
template <typename T, typename U> 
inline void chkmax(T& x, U y) {
    if (x < y) x = y;
}
  
template <typename T, typename U>
inline void chkmin(T& x, U y) {
    if (y < x) x = y;
}

#define N 1111111
#define MOD 1000000007

int x[N], y[N];
LL cross(int i, int j) {
  return (LL)x[j] * y[i] - (LL)x[i] * y[j];
}

int main() {

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = n; i <= n + n; i++) x[i] = x[i - n], y[i] = y[i - n];

  LL s = 0;
  for (int i = 0; i < n; i++) s += cross(i, (i + 1) % n);

  int cnt = 0;
  int ans = 0;
  LL cur = 0;

  for (int i = 0, j = 0, sx = (x[0] % MOD + MOD) % MOD, sy = (y[0] % MOD + MOD) % MOD, sum = 0; i < n; i++) {
    for (; j < n + i; j++) {
      LL add = cross(i, j % n) + cross(j % n, (j + 1) % n) + cross((j + 1) % n, i);
      if (cur + add > s / 2) break;
      cur += add;
      sx = (sx + x[(j + 1) % n] % MOD) % MOD;
      sx = (sx + MOD) % MOD;
      sy = (sy + y[(j + 1) % n] % MOD) % MOD;
      sy = (sy + MOD) % MOD;
      sum = (sum + cur % MOD) % MOD;
    }
    ans = (ans + sum) % MOD;
    int k = j - i;
    cnt += k - 1;
    cnt %= MOD;
    sx = (sx - x[i] % MOD) % MOD;
    sx = (sx + MOD) % MOD;
    sy = (sy - y[i] % MOD) % MOD;
    sy = (sy + MOD) % MOD;
    if (j > i + 1) {
      cur -= cross(i, (i + 1) % n) + cross((i + 1) % n, j % n) + cross(j % n, i);
      LL add = (LL)sx * (y[(i + 1) % n] - y[i]) - (LL)sy * (x[(i + 1) % n] - x[i]);
      add = (add % MOD + MOD) % MOD;
      sum = (sum - add % MOD + MOD) % MOD;
      sum = (sum - (LL)k * (cross(i, (i + 1) % n) % MOD) % MOD + MOD) % MOD;
    }
  }

  ans = ((s % MOD) * cnt % MOD - 2 * ans % MOD + MOD) % MOD;
  cout << ans << endl;

    return 0;
}