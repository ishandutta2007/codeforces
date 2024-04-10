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

const int MAXN = 111;
const int MOD = 1e6+3;

int a[MAXN][MAXN];
int ans[MAXN][MAXN], _ans[MAXN][MAXN];

int main() {
	
  int C, W, H; cin >> C >> W >> H;
  for (int i = 0; i <= W; i++) {
    for (int j = 0; j <= W; j++) {
      a[i][j] = ((i==0) ? 1 : ((i && j==i-1) ? H : 0));
    }
  }
  for (int i = 0; i <= W; i++) {
    for (int j = 0; j <= W; j++) {
      ans[i][j] = (i==j);
    }
  }
  for (int i = 31-clzi(C); i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= W; k++) {
        LL sum = 0;
        for (int l = 0; l <= W; l++) {
          sum += (LL)ans[j][l]*ans[l][k];
        }
        _ans[j][k] = sum % MOD;
      }
    }
    memcpy(ans, _ans, sizeof(ans));
    if (C >> i & 1) {
      for (int j = 0; j <= W; j++) {
        for (int k = 0; k <= W; k++) {
          LL sum = 0;
          for (int l = 0; l <= W; l++) {
            sum += (LL)ans[j][l]*a[l][k];
          }
          _ans[j][k] = sum % MOD;
        }
      }
      memcpy(ans, _ans, sizeof(ans));
    }
  }
  int ret = 0;
  for (int i = 0; i <= W; i++) {
    ret = (ret + ans[i][0]) % MOD;
  }
  cout << ret << endl;
  return 0;
}