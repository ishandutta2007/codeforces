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
int n, mx = 1, c[maxn];
vector<int> g[maxn];

void dfs(int x, int p) {
  int no = 1;
  mx = max(mx, c[x]);
  for (int y : g[x]) if (y != p) {
    while (no == c[x] || no == c[p]) no++;
    c[y] = no++;
    dfs(y, x);
  }
}

int main() {
  scanf("%d", &n);
  REPE(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  c[1] = 1;
  dfs(1, 1);
  printf("%d\n", mx);
  REPE(i, 1, n) printf("%d%c", c[i], " \n"[i == n]);
  return 0;
}