#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> link;
  DSU(int n) : link(n, -1) {}

  int Find(int x) {
    if (link[x] == -1) return x;
    return link[x] = Find(link[x]);
  }
  bool Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a == b) return false;
    link[a] = b;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  
  int m, n; cin >> m >> n;
  vector<int> a(m), b(n);
  for (int i = 0; i < m; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return b[i] > b[j];    
  });

  vector<vector<int>> sets(n);
  long long total = 0;
  vector<tuple<int, int, int>> all;
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    while (x--) {
      int y; cin >> y; --y;
      sets[y].push_back(i);
      total += a[i] + b[y];
      all.emplace_back(a[i] + b[y], y, i);
    }
  }

  DSU dsu(n);
  vector<int> taken(m, -1);
  sort(all.rbegin(), all.rend());
  for (auto [cost, i, j] : all) {
    if (taken[j] == -1) {
      taken[j] = i;
    } else if (!dsu.Union(i, taken[j])) {
      continue;
    }
    total -= cost;
  }
  /*
  for (auto i : order) {
    sort(sets[i].begin(), sets[i].end(), [&](int i, int j) {
      return a[i] > a[j];    
    });
    for (auto j : sets[i]) {
      if (taken[j] == -1) {
        taken[j] = i;
      } else if (!dsu.Union(i, taken[j])) {
        continue;
      }
      total -= b[i];
      total -= a[j];
    }
  }
  */
  cout << total << endl;

  return 0;
}