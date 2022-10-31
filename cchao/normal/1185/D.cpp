#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10;
int n;
pair<int, int> a[maxn];

bool go(int x) {
  {
    bool ok = true;
    for (int i = 2; i < n; ++i) {
      if (a[i].first - a[i - 1].first != x) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%d\n", a[0].second);
      return true;
    }
  }
  {
    int cnt = 0, f = 1;
    for (int i = 1; i < n && cnt < 2; ++i) {
      if (a[i].first - a[i - 1].first != x) {
        cnt++;
        f = a[i].second;
        if (i == n - 1) break;
        if (a[i + 1].first - a[i - 1].first != x) {
          cnt++;
          break;
        } else {
          i++;
        }
      }
    }
    if (cnt < 2) {
      printf("%d\n", f);
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  sort(a, a + n);
  go(a[1].first - a[0].first) ||
  go(a[2].first - a[1].first) ||
  go(a[2].first - a[0].first) ||
  puts("-1");
  return 0;
}