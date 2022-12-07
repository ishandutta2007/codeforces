#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 553456
#define maxW 2234567

i64 d, pinv, k, period;
vector<i64> skip;
int n, m, a[maxN], b[maxN], mark[maxW];
i64 merge(i64 x1, i64 x2) {
  x2 -= x1;
  if (x2 % d != 0)
    return -1;
  x2 /= d;
  i64 t = x2 * pinv % (m / d);
  if (t < 0)
    t += m / d;
  return (n / d) * t * d + x1;
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n && i <= m; i++)
    if (n % i == 0 && m % i == 0)
      d = i;
  period = (i64)n * m / d;
  pinv = 0;
  for (int i = 0; i < m / d; i++)
    if ((i64)i * (n / d) % (m / d) == 1)
      pinv = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mark[a[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    if (mark[b[i]] != 0) {
      i64 w = merge(mark[b[i]] - 1, i - 1);
      if (w != -1)
        skip.push_back(w);
    }
  }
  i64 l = 0, r = (1ll << 61);
  while (l + 1 < r) {
    i64 M = (l + r) / 2;
    i64 counter = M;
    for (auto day : skip)
      counter -= (M + period - 1 - day) / period;
    if (counter < k)
      l = M;
    else
      r = M;
  }
  printf("%lld\n", r);
}