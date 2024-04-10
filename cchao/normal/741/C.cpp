#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
typedef long long LL;
int n, a[200010], b[200010];
vector<int> g[200010];

bool v[200010];
int l[200010];

void dfs(int x, int y) {
  l[x] = y;
  v[x] = true;
  for (int i : g[x]) if (!v[i])
    dfs(i, 3 - y);
}

int main() {
  scanf("%d", &n);
  REPE(i, 1, n) {
    scanf("%d%d", &a[i], &b[i]);
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  for (int i = 1; i <= 2 * n; i += 2) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  REPE(i, 1, 2 * n) if (!v[i])
    dfs(i, 1);
  REPE(i, 1, n)
    printf("%d %d\n", l[a[i]], l[b[i]]);
  return 0;
}