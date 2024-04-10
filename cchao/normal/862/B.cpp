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

int n;
vector<int> g[100010];
int a[2];
void dfs(int x, int d, int p) {
  a[d]++;
  for (int y : g[x]) if (y != p)
    dfs(y, d ^ 1, x);
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1, 0, 0);
  printf("%lld\n", 1LL * a[0] * a[1] - n + 1);
  return 0;
}