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

int d[82][82][82][82];

int n, m, k;

vector<PII> g[82];

queue<tuple<int, int, int, int>> q;
bool inq[82][82][82][82];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  REP(i, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if (u != v) g[u].EB(v, w);
  }
  memset(d, -1, sizeof d);
  REPE(i, 1, n) {
    q.push({0, n + 1, i, 1});
    d[0][n + 1][i][1] = 0;
  }
  int ans = INT_MAX;
  while (q.size()) {
    int lb, ub, x, y;
    tie(lb, ub, x, y) = q.front(); q.pop();
    inq[lb][ub][x][y] = false;
    const int od = d[lb][ub][x][y];
    if (y == k) {
      ans = min(ans, od);
      continue;
    }
    for (auto &it : g[x]) {
      const int v = it.F, w = it.S;
      if (v <= lb || v >= ub) continue;
      const int nlb = v > x ? x : lb;
      const int nub = v < x ? x : ub;
      int &nd = d[nlb][nub][v][y + 1];
      bool &qq = inq[nlb][nub][v][y + 1];
      if (nd == -1 || od + w < nd) {
        nd = od + w;
        if (!qq) {
          qq = true;
          q.push({nlb, nub, v, y + 1});
        }
      }
    }
  }
  if (ans == INT_MAX) ans = -1;
  printf("%d\n", ans);
  return 0;
}