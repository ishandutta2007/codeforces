#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 223456;
int n, m, deg[maxN], label1[maxN], label2[maxN];
vector<int> e[maxN], rev[maxN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    rev[v].push_back(u);
    deg[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0)
      q.push(i);
  }
  vector<int> order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (auto v : e[u]) {
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] != 0) {
      printf("-1\n");
      return 0;
    }
  for (int i = 0; i < n; i++) {
    int u = order[i];
    label1[u] = u;
    for (auto v : rev[u])
      label1[u] = min(label1[u], label1[v]);
  }
  for (int i = n - 1; i >= 0; i--) {
    int u = order[i];
    label2[u] = u;
    for (auto v : e[u])
      label2[u] = min(label2[u], label2[v]);
  }
  int ans = 0;
  string ch(n, 'E');
  for (int i = 1; i <= n; i++) {
    if (i <= label1[i] && i <= label2[i]) {
      ans += 1;
      ch[i - 1] = 'A';
    }
  }
  printf("%d\n%s\n", ans, ch.c_str());
}