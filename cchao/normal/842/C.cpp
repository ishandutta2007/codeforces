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

int n, a[200010];
vector<int> g[200010];
set<int> ans[200010];

void dfs(int x, int p, int v) {
  ans[x].insert(v);
  v = __gcd(v, a[x]);
  ans[x].insert(v);
  for (int t : ans[p])
    ans[x].insert(__gcd(t, a[x]));
  for (int y : g[x])
    if (y != p)
      dfs(y, x, v);
}

int main() {
  scanf("%d", &n);
  REPE(i, 1, n) scanf("%d", &a[i]);
  REPE(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1, 0, 0);
  REPE(i, 1, n)
    printf("%d%c", *ans[i].rbegin(), " \n"[i == n]);
  return 0;
}