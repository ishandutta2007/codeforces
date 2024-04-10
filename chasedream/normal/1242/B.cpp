#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector <int> adj[N], B;

unordered_map <int, int> cnt;
int sz[N], f[N];
int n, m;

int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) swap(u, v);
    adj[u].push_back(v); // u > v
  }  
  for (int i = 1; i <= n; i++) {
    f[i] = i, sz[i] = 1;
  }
  for (int u = 1; u <= n; u++) {
    cnt.clear();
    for (auto v: adj[u]) {
      cnt[find(v)]++;
    }
    for (auto v: B) {
      int x = find(u), y = find(v);
      if (x == y) continue;
      if (cnt[y] < sz[y]) {
        f[x] = y, sz[y] += sz[x]; 
      }
    }
    if (u == find(u)) B.push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == i) ans++;
  }
  printf("%d\n", ans - 1);
  return 0;
}