#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

const int maxn = 2e5 + 10;
int u[maxn], v[maxn], n, c[maxn];

int p[maxn];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

vector<int> g[maxn];
int deg[maxn], sz[maxn];

bool only(int x, int p) {
  for (int y : g[x]) if (y != p) {
    if (c[y] != c[x] || !only(y, x)) return false;
  }
  return true;
}

bool verify(int x) {
  for (int y : g[x])
    if (!only(y, x))
      return false;
  return true;
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    scanf("%d%d", &u[i], &v[i]);
    g[u[i]].PB(v[i]);
    g[v[i]].PB(u[i]);
  }
  REPE(i, 1, n) scanf("%d", &c[i]);
  REPE(i, 1, n) p[i] = i;
  REP(i, n - 1) {
    if (c[u[i]] == c[v[i]])
      p[f(u[i])] = f(v[i]);
  }
  REP(i, n - 1) {
    int x = f(u[i]);
    int y = f(v[i]);
    if (x != y) {
      deg[x]++, deg[y]++;
    }
  }
  REPE(i, 1, n) sz[f(i)]++;
  int chz = max_element(deg, deg + 1 + n) - deg;
  if (deg[chz] == 0) {
    puts("YES\n1");
    return 0;
  }
  REP(i, n - 1) {
    int x = f(u[i]);
    int y = f(v[i]);
    if (x != y) {
      if (x == chz || y == chz) {
        int t = x == chz ? u[i] : v[i];
        if (verify(t)) {
          puts("YES");
          printf("%d\n", t);
        } else puts("NO");
        break;
      }
    }
  }
  return 0;
}