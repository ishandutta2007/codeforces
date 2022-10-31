#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>
 
using namespace std;
 
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
 
typedef long double ld;
 
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
 
inline int myrand() {
  return abs((rand() << 15) ^ rand());
}
 
inline int rnd(int x) {
  return myrand() % x;
}
 
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"
 
const int INF = (int) 1.01e9;
const ld EPS = 1e-9;
 
void precalc() {
}
 
int n, k, s;
 
const int maxn = 150 + 10;
int a[maxn];
 
bool read() {
  if (scanf("%d%d%d", &n, &k, &s) < 3) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return 1;
}
 
int d[maxn][maxn * maxn];
int nd[maxn][maxn * maxn];
 
int getMaxc(int x, int t) {
  return min(s, (x - t) * t);
}
 
void update(int &x, int val) {
  x = min(x, val);
}
 
void solve() {
  d[0][0] = 0;
  for (int x = 0; x < n; ++x) {
    for (int t = 0; t <= x + 1 && t <= k; ++t) {
      int maxc = getMaxc(x + 1, t);
      for (int c = 0; c <= maxc; ++c) {
        nd[t][c] = INF;
      }
    }
    for (int t = 0; t <= x && t <= k; ++t) {
      int maxc = getMaxc(x, t);
      for (int c = 0; c <= maxc; ++c) {
        int &cur = d[t][c];
        if (cur == INF) {
          continue;
        }
        update(nd[t][c], cur);
        update(nd[t + 1][c + (x - t)], cur + a[x]);
      }
    }
    for (int t = 0; t <= x + 1 && t <= k; ++t) {
      int maxc = getMaxc(x + 1, t);
      for (int c = 0; c <= maxc; ++c) {
        d[t][c] = nd[t][c];
      }
    }
  }
  int maxc = getMaxc(n, k);
  int res = INF;
  for (int c = 0; c <= maxc; ++c) {
    res = min(res, d[k][c]);
  }
  printf("%d\n", res);
}
 
int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif
 
  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}