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

int p[MAXN], t[MAXN], q[MAXN], id1[MAXN], id[MAXN];
LL sum[MAXN];

double x[MAXN];

LL cross(int u, int v) {
  return (LL)p[u]*t[v]-(LL)p[v]*t[u];
}

bool cmp(int u, int v) {
  LL A = (LL)p[u]*t[v], B = (LL)p[v]*t[u];
  if (A != B) {
    return A > B;
  }
  return p[u] < p[v];
}

bool cmp1(int u, int v) {
  return p[u] < p[v];
}

int n;
LL T;

double BIT[MAXN];

void update(int x, double y) {
  for (; x <= n; x += x & -x) {
    chkmax(BIT[x], y);
  }
}

double get(int x) {
  double ret = 0;
  for (x--; x; x -= x & -x) {
    chkmax(ret, BIT[x]);
  }
  return ret;
}

bool check(double mid) {
  for (int i = 1; i <= n; i++) {
    BIT[i] = 0;
  }
  double cur = 0;
  for (int i = 1, j = 1; i <= n; i = j) {
    for (j = i; j <= n && cross(id[i], id[j]) == 0; j++) {
      double temp = get(q[id[j]]);
      double temp1 = p[id[j]]*(1.0-mid*(double)sum[id[j]]/T);
      if (temp > temp1+1e-8) {
        return 0;
      }
      update(q[id[j]], p[id[j]]*(1.0-mid*(cur+t[id[j]])/T));
    }
    cur = sum[id[i]];
  }
  return 1;
}

int main() {
	
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  T = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    T += t[i];
  }
  for (int i = 1; i <= n; i++) {
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  LL temp = 0;
  for (int i = 1, j = 1; i <= n; i = j) {
    for (j = i; j <= n && cross(id[i], id[j]) == 0; j++) {
      temp += t[id[j]];
    }
    for (int k = i; k < j; k++) {
      sum[id[k]] = temp;
    }
  }
  for (int i = 1; i <= n; i++) {
    id1[i] = i;
  }
  sort(id1 + 1, id1 + n + 1, cmp1);
  for (int i = 1, j = 1, k = 1; i <= n; i = j) {
    for (j = i; j <= n && p[id1[i]] == p[id1[j]]; j++) {
      q[id1[j]] = k;
    }
    k++;
  }
  double lo = 0, hi = 1;
  for (int i = 0; i < 40; i++) {
    double mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%.10lf\n", lo);
	return 0;
}