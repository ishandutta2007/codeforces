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

#define N 1111111

int f[N], a[N];
PII b[N];
int deg[N], dp[N];
VPII e; VI adj[N];
int n, m, tot;

int get(int u) {
  return f[u] == -1 ? u : f[u] = get(f[u]);
}

int main() {

  scanf("%d%d", &n, &m);

  memset(f, -1, sizeof f);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i*m+j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) b[j] = PII(a[i*m+j], i*m+j);
    sort(b, b + m);
    for (int j = 1; j < m; j++) {
      if (b[j].X == b[j-1].X) {
        int u = get(b[j].Y), v = get(b[j-1].Y);
        if (u != v) f[u] = v;
      } else {
        e.pb(PII(b[j-1].Y, b[j].Y));
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) b[j] = PII(a[j*m+i], j*m+i);
    sort(b, b + n);
    for (int j = 1; j < n; j++) {
      if (b[j].X == b[j-1].X) {
        int u = get(b[j].Y), v = get(b[j-1].Y);
        if (u != v) f[u] = v;
      } else {
        e.pb(PII(b[j-1].Y, b[j].Y));
      }
    }
  }

  for (int i = 0; i < sz(e); i++) {
    int u = get(e[i].X), v = get(e[i].Y);
    adj[u].pb(v), deg[v]++;
  }

  queue<int> Q;
  for (int i = 0; i < n*m; i++) if (get(i) == i && deg[i] == 0) Q.push(i), dp[i] = 1;

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < sz(adj[u]); i++) {
      int v = adj[u][i];
      deg[v]--;
      if (!deg[v]) Q.push(v), dp[v] = dp[u]+1;
    }
  }

  for (int i = 0; i < n*m; i++) dp[i] = dp[get(i)];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d%c", dp[i*m+j], (j<m-1 ? ' ' : '\n'));
  }

  return 0;
}