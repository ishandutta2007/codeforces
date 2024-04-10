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

const int maxn = 1e5 + 10;
int n, m;
int a[maxn];
vector<int> gg[maxn];

int p[maxn << 1];
int f(int x) {
  return x == p[x] ? x : p[x] = f(p[x]);
}

int main() {
  scanf("%d%d", &n, &m);
  REPE(i, 1, n) scanf("%d", &a[i]);
  REP(i, m) {
    int x;
    scanf("%d", &x);
    REP(j, x) {
      int t;
      scanf("%d", &t);
      gg[t].PB(i);
    }
  }
  REP(i, m + m) p[i] = i;
  REPE(i, 1, n) {
    int u = gg[i][0];
    int v = gg[i][1];
    int fu = f(u), ffu = f(u + m);
    int fv = f(v), ffv = f(v + m);
    // printf("check %d %d: %d %d\n", i, a[i], u, v);
    if (a[i] == 0) { // u != v
      if (fu == fv || ffu == ffv) {
        puts("NO");
        exit(0);
      }
      p[f(u)] = f(v + m);
      p[f(v)] = f(u + m);
    } else { // u == v
      if (fu == ffv || fv == ffu) {
        puts("NO");
        exit(0);
      }
      p[f(u)] = f(v);
      p[f(u + m)] = f(v + m);
    }
  }
  puts("YES");
  return 0;
}