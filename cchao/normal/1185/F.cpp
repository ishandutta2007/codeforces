#include <bits/stdc++.h>
using namespace std;

int n, m, b[512] = {};

vector<pair<int, int>> a[512];

int c[512] = {};

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    int tmp = 0;
    for (int j = 0; j < s; ++j) {
      int x;
      scanf("%d", &x);
      tmp |= 1 << (x - 1);
    }
    b[tmp]++;
  }
  for (int i = 0; i < m; ++i) {
    int p, s;
    scanf("%d%d", &p, &s);
    int tmp = 0;
    for (int j = 0; j < s; ++j) {
      int x;
      scanf("%d", &x);
      tmp |= 1 << (x - 1);
    }
    a[tmp].emplace_back(p, i + 1);
  }
  for (int i = 0; i < 512; ++i)
    sort(a[i].begin(), a[i].end());
  for (int i = 0; i < 512; ++i)
    for (int j = 0; j <= i; ++j)
      if ((i & j) == j)
        c[i] += b[j];
  int ans = 0, ansp = 2e9 + 10, c1 = 1, c2 = 1;
  for (int i = 0; i < 512; ++i)
    for (int j = 0; j <= i; ++j) {
      int mask = i | j;
      int price = 0;
      if (i == j && a[i].size() < 2) continue;
      if (a[i].empty() || a[j].empty()) continue;
      if (i == j) price = a[i][0].first + a[i][1].first;
      else price = a[i][0].first + a[j][0].first;

      if (c[mask] < ans || (c[mask] == ans && price > ansp)) continue;
      ans = c[mask];
      ansp = price;
      if (i == j) {
        if (a[i].size() < 2) continue;
        c1 = a[i][0].second;
        c2 = a[i][1].second;
      } else {
        c1 = a[i][0].second;
        c2 = a[j][0].second;
      }
    }
  printf("%d %d\n", c1, c2);
  return 0;
}