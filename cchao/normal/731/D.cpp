#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a[500010];
int b[1000010];

inline void add(int l, int r) {
  b[l]++;
  b[r + 1]--;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, s; i < n; ++i) {
    scanf("%d", &s);
    a[i].resize(s);
    for (int j = 0; j < s; ++j)
      scanf("%d", &a[i][j]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    int s = min(a[i].size(), a[i + 1].size());
    bool fg = false;
    for (int j = 0; j < s && !fg; ++j) {
      int x = a[i][j], y = a[i + 1][j];
      if (x != y) {
        if (x < y) add(m - y + 1, m - x);
        else add(0, m - x), add(m - y + 1, m - 1);
        fg = true;
        break;
      }
    }
    if (!fg && a[i].size() > a[i + 1].size()) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0, s = 0; i < m; ++i) {
    if ((s += b[i]) == 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}