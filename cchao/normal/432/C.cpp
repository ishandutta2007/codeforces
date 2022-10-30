#include <bits/stdc++.h>
using namespace std;

int main() {
  const int maxn = 100000 + 10;
  bitset<maxn> vis;
  vector<int> p;
  for (int i = 2; i < maxn; ++i) {
    if (!vis.test(i)) {
      p.push_back(i);
    }
    for (int x : p) {
      if (1LL * i * x >= maxn)
        break;
      vis.set(i * x);
      if (i % x == 0) {
        break;
      }
    }
  }

  reverse(p.begin(), p.end());
  /*
  for (int d = 1; d < maxn; ++d) {
    int t = d;
    int cnt = 0;
    for (int x : p) {
      if (x - 1 <= t) {
        t -= (x - 1);
        cnt++;
      }
    }
    assert(t == 0);
    if (cnt > 5)
      printf("%d %d\n", d, cnt);
  }
  return 0;
  */
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1), inv(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    inv[a[i]] = i;
  }

  vector<pair<int, int>> ans;
  auto f = [&](int x, int y) {
    ans.emplace_back(x, y);
    swap(a[x], a[y]);
    inv[a[x]] = x;
    inv[a[y]] = y;
  };

  for (int i = 1; i <= n; ++i) {
    int t = inv[i] - i;
    for (int x = t + 1; x >= 2 and t; )
      if (!vis.test(x)) {
        f(inv[i] - x + 1, inv[i]);
        t -= x - 1;
        x = t + 1;
      }
      else --x;
  }
  /*
  for (int i = 1; i <= n; ++i)
    printf("%d ", a[i]);
  puts("");
  */

  printf("%d\n", int(ans.size()));
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);

  return 0;
}