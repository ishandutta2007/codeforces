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
const int N = 500005;
const int MOD = 1000000007;
const LL INF = LL(1e18);
inline void add(int &x, int y) {
  if ((x += y) >= MOD) x -= MOD;
}

LL u[N], d[N], l[N], r[N];
int x, y;
LL a[N], b[N];
int sum[N];
char str[N];
int n, h, w;
const char pat[] = "DRUL";
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void init() {
  
  for (int i = 0; i < h; i++) {
    chkmin(a[i], u[i + 1]);
    chkmin(a[i], d[h - i]);
  }
  
  if (x > 0) {
    for (int i = h - 1; i >= 0; i--) {
      if (i + x < h) {
        chkmin(a[i], a[i + x] + n);
      }
    }
  }
  else {
    x = -x;
    for (int i = 0; i < h; i++) {
      if (i >= x) {
        chkmin(a[i], a[i - x] + n);
      }
    }
  }

  for (int i = 0; i < w; i++) {
    chkmin(b[i], l[i + 1]);
    chkmin(b[i], r[w - i]);
  }
  if (y > 0) {
    for (int i = w - 1; i >= 0; i--) {
      if (i + y < w) {
        chkmin(b[i], b[i + y] + n);
      }
    }
  } else {
    y = -y;
    for (int i = 0; i < w; i++) {
      if (i >= y) {
        chkmin(b[i], b[i - y] + n);
      }
    }
  }
}
bool can() {
  int flg = 0;
  for (int i = 0; i < h; i++) {
    if (a[i] == INF) flg = 1;
  }
  for (int i = 0; i < w; i++) {
    if (b[i] == INF) flg |= 2;
  }
  return flg != 3;
}

int main() {
  
  x = 0, y = 0;
  cin >> n >> h >> w;
  cin >> str;
  fill(u, u + N, INF);
  fill(d, d + N, INF);
  fill(l, l + N, INF);
  fill(r, r + N, INF);
  fill(b, b + N, INF);
  fill(a, a + N, INF);
  u[0] = d[0] = l[0] = r[0] = 0;
  for (int i = 0; i < n; i++) {
    int dir = strchr(pat, str[i]) - pat;
    x += dx[dir], y += dy[dir];
    if (x) {
      if (x > 0) {
        chkmin(d[x], i + 1);
      }
      else chkmin(u[-x], i + 1);
    }
    if (y) {
      if (y > 0) {
        chkmin(r[y], i + 1);
      }
      else 
        chkmin(l[-y], i + 1);
    }
  }
  init();
  if (!can()) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  sort(b, b + w);
  for (int i = 0; i < w; i++) {
    sum[i] = b[i] % MOD;
    if (i) sum[i] = (sum[i] + sum[i - 1]) % MOD;
  }
  for (int i = 0; i < h; i++) {
    int id = lower_bound(b, b + w, a[i]) - b;
    if (id) add(ans, sum[id - 1]);
    add(ans, 1LL * a[i] % MOD * (w - id) % MOD);
  }
  cout << ans << endl;
    return 0;
}