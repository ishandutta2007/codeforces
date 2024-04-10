#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456
mt19937_64 mrand(random_device{}());

int n, m, k;
vector<int> adj[maxN];
int deg[maxN], del[maxN];
i64 lab[maxN];

struct hash_tables {
  static const int sz = 10000019;
  int head[sz], nxt[sz], mark, tmmark[sz], len;
  i64 key[sz];
  void clear() {
    len = 0;
    mark++;
  }
  void add(i64 s) {
    int val = s % sz;
    if (val < 0)
      val += sz;
    if (tmmark[val] != mark)
      tmmark[val] = mark, head[val] = -1;
    nxt[len] = head[val], head[val] = len, key[len] = s;
    len++;
  }
  bool count(i64 s) {
    int val = s % sz;
    if (val < 0)
      val += sz;
    if (tmmark[val] != mark)
      return false;
    for (int j = head[val]; j != -1; j = nxt[j])
      if (key[j] == s)
        return true;
    return false;
  }
} g;

void solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    del[i] = 0;
    lab[i] = mrand();
  }
  g.clear();
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    g.add(lab[u] ^ lab[v]);
  }
  for (int i = 1; i <= n; i++)
    deg[i] = adj[i].size();
  queue<int> q;
  vector<int> ord;
  vector<int> clique;
  auto check = [&](int u) {
    if (deg[u] < k - 1)
      return false;
    vector<int> c;
    c.push_back(u);
    for (auto v : adj[u])
      if (!del[v]) {
        if (deg[v] < k - 1)
          return false;
        c.push_back(v);
      }
    assert(c.size() == k);
    for (int i = 0; i < k; i++)
      for (int j = i + 1; j < k; j++)
        if (!g.count(lab[c[i]] ^ lab[c[j]]))
          return false;
    clique = c;
    return true;
  };
  for (int i = 1; i <= n; i++)
    if (deg[i] < k) {
      q.push(i);
      if (check(i)) {
        printf("%d\n", 2);
        for (auto p : clique)
          printf("%d ", p);
        printf("\n");
        return;
      }
    }
  while (!q.empty()) {
    int u = q.front();
    ord.push_back(u);
    del[u] = 1;
    q.pop();
    for (auto v : adj[u]) {
      --deg[v];
      if (deg[v] == k - 1) {
        q.push(v);
        if (check(v)) {
          printf("%d\n", 2);
          for (auto p : clique)
            printf("%d ", p);
          printf("\n");
          return;
        }
      }
    }
  }
  if (ord.size() != n) {
    printf("%d %d\n", 1, n - (int)ord.size());
    for (int i = 1; i <= n; i++)
      if (deg[i] >= k) {
        printf("%d ", i);
      }
    printf("\n");
    return;
  }
  printf("-1\n");
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    solve();
  }
}