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

const int MAXN = 2222222;

int a[2][MAXN], add[2], ans[MAXN];

int main() {
	
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    a[i&1][i/2] = i;
  }
  int now = 0;
  for (int i = 1; i <= q; i++) {
    int tp; scanf("%d", &tp);
    if (tp == 1) {
      int x; scanf("%d", &x); x = (x + n) % n;
      if (x & 1) {
        now ^= 1;
        add[now] = (add[now] + (x+1)/2) % (n/2);
        add[!now] = (add[!now] + x/2) % (n/2);
      } else {
        add[!now] = (add[!now] + x/2) % (n/2);
        add[now] = (add[now] + x/2) % (n/2);
      }
    } else {
      now ^= 1;
    }
  }
  for (int i = 0; i < n; i += 2) {
    ans[(i/2+add[now])%(n/2)*2] = a[now][i/2];
  }
  for (int i = 1; i < n; i += 2) {
    ans[(i/2+add[!now])%(n/2)*2+1] = a[!now][i/2];
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i]+1, i<n-1 ? ' ' : '\n');
  }
	return 0;
}