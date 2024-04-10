#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

int n, k, a[1000000 + 10];

bool ok(int x) {
  LL sum = 0;
  REP(i, n) {
    if (x > a[i]) break;
    LL t = 0;
    for (LL j = 1; a[i] / j + 1 >= x; j += j) {
      LL r = a[i] % j;
      LL tmp = a[i] / j >= x ? j : r;
      t = max(t, tmp);
      if (a[i] / j == 0) break;
    }
    if (sum + (n - i) * t < k) break;
    sum += t;
    if (sum >= k) break;
  }
  return sum >= k;
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n, greater<int>());
  int l = 1, r = 1e7 + 1, ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m)) {
      ans = m;
      l = m + 1;
    }
    else r = m - 1;
  }
  printf("%d\n", ans);
  return 0;
}