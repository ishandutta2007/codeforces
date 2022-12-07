#include <bits/stdc++.h>
using namespace std;
#define maxN 423456

int tc;
int n, deg[maxN];
int w[maxN];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    deg[i] = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    ans += w[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u] += 1;
    deg[v] += 1;
  }
  vector<int> extra;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < deg[i] - 1; j++)
      extra.push_back(w[i]);
  }
  sort(extra.rbegin(), extra.rend());
  printf("%lld", ans);
  for (int x : extra) {
    ans += x;
    printf(" %lld", ans);
  }
  printf("\n");
}

int main() {
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    solve();
  }
}