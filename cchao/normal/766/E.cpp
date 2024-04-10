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
int n, a[maxn], bit = 1;
vector<int> g[maxn];
LL ans = 0;

array<LL, 2> dfs(int x, int p) {
  array<LL, 2> ret = {};
  array<LL, 2> sum = {};
  int v = (a[x] & bit) ? 1 : 0;
  ret[v]++;
  sum[v]++;
  for (int y : g[x]) if (y != p) {
    auto t = dfs(y, x);
    REP(i, 2) REP(j, 2)
      ret[i ^ j] += t[i] * sum[j];
    sum[v] += t[0];
    sum[v^1] += t[1];
  }
  ans += bit * ret[1];
  return sum;
}

int main() {
  scanf("%d", &n);
  REPE(i, 1, n) scanf("%d", &a[i]);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  REP(i, 20) {
    dfs(1, 1);
    bit <<= 1;
  }
  printf("%lld\n", ans);
  return 0;
}