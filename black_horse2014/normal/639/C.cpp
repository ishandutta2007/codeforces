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

long long a[MAXN], b[MAXN];

int sgn(long long x) {
  if (x < 0) {
    return -1;
  }
  if (x > 0) {
    return 1;
  }
  return 0;
}

int main() {
	
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) {
    scanf("%lld", &a[i]);
    long long x = abs(a[i]);
    int s = sgn(a[i]);
    for (int j = 30; j >= 0; j--) {
      if (x >> j & 1) {
        b[i+j] += s;
      }
    }
  }
  for (int i = 0; i < n+60; i++) {
    int x = abs(b[i]), s = sgn(b[i]);
    if (x > 1) {
      b[i] = 0;
      for (int j = 30; j >= 0; j--) {
        if (x >> j & 1) {
          b[i+j] += s;
        }
      }
    }
  }
  for (int i = 0; i < n+60; i++) {
    b[i] = -b[i];
  }
  int first = n+60;
  for (int i = n+59; i >= 0; i--) {
    if (b[i] != 0) {
      first = i;
      break;
    }
  }
  int s = sgn(b[first]);
  for (int i = 0, j = 0; i < n+60; i++) {
    if (!b[i]) {
      continue;
    }
    if (b[i] == s) {
      int flg = -1;
      for (int k = j; k < i; k++) {
        if (b[k] == -s) {
          flg = k;
          break;
        }
      }
      if (flg >= 0) {
        for (j = flg; j < i; j++) {
          if (j == flg) {
            b[j] = -b[j];
          } else if (j > flg) {
            b[j] += s;
          }
        }
        b[i] = 0;
      }
    }
  }
  int st = -1;
  for (int i = 0; i < n+60; i++) {
    assert(b[i] == 0 || b[i] == s);
    if (!~st && b[i] == s) {
      st = i;
    }
  }
  long long del = 0;
  int ans = 0;
  for (int i = n+59; i >= 0; i--) {
    del <<= 1;
    if (del > 2*m) {
      break;
    }
    if (b[i] == s) {
      del++;
    }
    if (i <= st && i <= n) {
      if (abs(a[i]+del*s) <= m) {
        if (i == n) {
          if (a[i] + del*s != 0) {
            ans++;
          }
        } else {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
	return 0;
}