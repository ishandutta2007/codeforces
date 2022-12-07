#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 555555

int n, m, u, v, p[maxN], q[maxN];
vector<int> adj[maxN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    q[i] = i;
  }
  sort(q + 1, q + n + 1,
       [&](int x, int y) { return p[x] < p[y] || (p[x] == p[y] && x < y); });
  for (int i = 1; i <= n; i++) {
    int u = q[i];
    set<int> number;
    for (auto v : adj[u]) {
      if (p[u] == p[v]) {
        printf("-1\n");
        exit(0);
      }
      if (p[u] > p[v]) {
        number.insert(p[v]);
      }
    }
    for (int j = 1; j < p[u]; j++)
      if (!number.count(j)) {
        printf("-1\n");
        exit(0);
      }
  }
  for (int i = 1; i <= n; i++)
    printf("%d ", q[i]);
  printf("\n");
}