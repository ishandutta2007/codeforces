#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 323456

int n;
i64 solve(i64 a, i64 b, i64 c, i64 d) {
  if (a > b * c)
    return -1;
  i64 l = 0, r = c / d;
  auto eval = [&](i64 k) { return (k + 1) * a - d * b * k * (k + 1) / 2; };
  i64 ans = 0;
  while (l + 3 < r) {
    i64 p = (l + r) / 2, q = (l + r) / 2 + 1;
    if (eval(p) > eval(q))
      r = q;
    else
      l = p;
  }
  for (i64 k = l; k <= r; k++) {
    ans = max(ans, eval(k));
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int T = 0; T < n; T++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%lld\n", solve(a, b, c, d));
  }
}