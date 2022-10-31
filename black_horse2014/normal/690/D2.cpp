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
const int MOD = 1e6+3;

int r[MAXN];

int main() {
	
  int n, m; cin >> n >> m;
  r[1] = 1;
  for (int i = 2; i <= m; i++) {
    r[i] = (LL)(MOD-r[MOD%i]) * (MOD/i) % MOD;
  }
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = (LL)ans*(n+m+1-i) % MOD;
    ans = (LL)ans*r[i] % MOD;
  }
  ans = (ans + MOD-1) % MOD;
  cout << ans << endl;
  return 0;
}