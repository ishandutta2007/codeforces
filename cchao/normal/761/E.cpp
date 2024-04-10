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

vector<int> g[33];
int d[33];
int n;
LL ax[33], ay[33];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void f(int p, LL x, LL y, LL step, int pd, int pa) {
  tie(ax[p], ay[p]) = tie(x, y);
  bool vd[4] = {};
  if (pd >= 0) vd[pd] = true;
  for (int q: g[p]) {
    if (q == pa) continue;
    int cd = 0;
    REP(i, 4) if (!vd[i]) {
      vd[i] = true;
      cd = i;
      break;
    }
    f(q, x + step * dx[cd], y + step * dy[cd], step >> 1, cd ^ 2, p);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    d[u]++, d[v]++;
    g[u].PB(v);
    g[v].PB(u);
    if (d[u] > 4 || d[v] > 4) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  f(1, 0, 0, 1LL << 32, -1, 0);
  REPE(i, 1, n) printf("%lld %lld\n", ax[i], ay[i]);
  return 0;
}