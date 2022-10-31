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

vector<int> g[maxn];

int n, k;

int size[maxn];
LL r[maxn][6];
LL sum[maxn];
LL ans;
void dfs(int x, int p) {
  size[x] = 1;
  r[x][0] = 1;
  for (int y : g[x]) if (y != p) {
    dfs(y, x);
    REP(i, k) REP(j, k) {
      ans += r[y][i] * r[x][j] * ((i + j + k - 1) / k);
    }
    size[x] += size[y];
    REP(i, k) r[x][i] += r[y][i];
    sum[x] += sum[y];
  }
  for (int y : g[x]) if (y != p) {
    ans += sum[y] * (size[x] - size[y]);
  }
  for (int i = k; i >= 1; --i)
    r[x][i] = r[x][i - 1];
  r[x][0] = r[x][k];
  sum[x] += r[x][0];
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1, 1);
  printf("%lld\n", ans);
  return 0;
}