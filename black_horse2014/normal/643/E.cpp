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

const int MAXN = 555555;

int T, n = 1, m;
int f[MAXN];
double dp[60][MAXN];

void update(int u) {
  VI T;
  for (int j = 0, v = u; j < 59 && v; j++, v = f[v]) {
    T.push_back(v);
  }
  for (int j = T.size()-1; j >= 2; j--) {
    dp[j][T[j]] /= (dp[j-1][T[j-1]]+1)*.5;
  }
  dp[0][u] = 0;
  for (int j = 0, v = u; j < 59 && v; j++, v = f[v]) {
    dp[j+1][f[v]] *= (dp[j][v]+1) * .5;
  }
}

int main() {
	
  int qn = 0;
  scanf("%d", &m);
  for (int i = 1; i < 60; i++) {
    dp[i][1] = 1;
  }
  for (int i = 0; i < m; i++) {
    int tp, u; scanf("%d%d", &tp, &u);
    if (tp == 1) {
      f[++n] = u;
      update(n);
      for (int j = 1; j < 60; j++) {
        dp[j][n] = 1;
      }
    } else {
      double ans = 0;
      for (int j = 1; j < 60; j++) {
        ans += 1-dp[j][u];
      }
      printf("%.12lf\n", ans);
    }
  }
	return 0;
}