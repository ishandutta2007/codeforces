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

int dp[MAXN];
int f[18][MAXN];

inline int lca(int u, int v) {
  if (dp[u] < dp[v]) {
    swap(u, v);
  }
  int d = dp[u]-dp[v];
  for (int i = 17; i >= 0; i--) {
    if (d >> i & 1) {
      u = f[i][u];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 17; i >= 0; i--) {
    if (f[i][u] == f[i][v]) {
      continue;
    }
    u = f[i][u], v = f[i][v];
  }
  return f[0][u];
}

inline int get(int u, int v) {
  int w = lca(u, v);
  return dp[u]+dp[v]-2*dp[w];
}

int main() {
	
  int n; cin >> n;
  int u = 1, v = 1, d = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &f[0][i]), dp[i] = dp[f[0][i]]+1;
    for (int j = 1; j <= 17; j++) {
      f[j][i] = f[j-1][f[j-1][i]];
    }
    int x = get(u, i);
    if (x > d) {
      d = x, v = i;
    }
    int y = get(v, i);
    if (y > d) {
      d = y, u = i;
    }
    printf("%d%c", d, i<n ? ' ' : '\n');
  }
  return 0;
}