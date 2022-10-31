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

int n, q, c;

int d[11][101][101];

int main() {
  scanf("%d%d%d", &n, &q, &c);
  REP(i, n) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    d[v][x][y] += 1;
  }
  REPE(v, 0, c) REPE(i, 1, 100) REPE(j, 1, 100) {
    d[v][i][j] += d[v][i-1][j] + d[v][i][j-1] - d[v][i-1][j-1];
  }
  REP(it, q) {
    int t, x1, x2, y1, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    int s = 0;
    x1--, y1--;
    REPE(v, 0, c) {
      int tmp = d[v][x2][y2] - d[v][x1][y2] - d[v][x2][y1] + d[v][x1][y1];
      s += ((v + t) % (c + 1)) * tmp;
    }
    printf("%d\n", s);
  }
  return 0;
}