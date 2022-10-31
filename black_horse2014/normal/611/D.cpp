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

#define MOD 1000000007
#define N 5555

char s[N];
int dp[N][N], lcp[N];
int rnk[N], sa[N], _sa[N], cnt[11];
int num[N][N];
int rmq[15][N];

bool check(int s1, int s2, int l) {
  if (s[s1] == '0') return 1;
  int L = rnk[s1], R = rnk[s2];
  int k = 31 - clz(abs(R - L));
  int ll = min(L, R), rr = max(L, R);
  int len = min(rmq[k][ll + 1], rmq[k][rr - bit(k) + 1]);
  if (len >= l) return 0;
  return s[s1 + len] < s[s2 + len];
}

int main() {
    
  int n;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j < n - i) num[i][j] = s[i + j] - '0' + 1;
      else num[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) sa[i] = i;
  for (int i = n - 1; i >= 0; i--) {
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j < n; j++) cnt[num[sa[j]][i]]++;
    for (int j = 1; j <= 10; j++) cnt[j] += cnt[j - 1];
    for (int j = n - 1; j >= 0; j--) _sa[--cnt[num[sa[j]][i]]] = sa[j];
    memcpy(sa, _sa, sizeof(int)*n);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (num[sa[i - 1]][j] != num[sa[i]][j]) {
        lcp[i] = j;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) rnk[sa[i]] = i;
  for (int i = 0; i < n; i++) rmq[0][i] = lcp[i];
  for (int i = 1; i <= 12; i++) {
    for (int j = 0; j < n; j++) {
      rmq[i][j] = rmq[i - 1][j];
      if (j + bit(i - 1) < n) chkmin(rmq[i][j], rmq[i - 1][j + bit(i - 1)]);
    }
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i][j - 1];
      if (s[i - j] != '0') {
        int cur = dp[i - j][min(j, i - j)];
        if (j <= i - j && !check(i - 2 * j, i - j, j)) cur = ((cur - dp[i - j][j] + dp[i - j][j - 1]) % MOD + MOD) % MOD;
        dp[i][j] = (dp[i][j] + cur) % MOD;
      }
    }
  }

  cout << dp[n][n] << endl;
    return 0;
}