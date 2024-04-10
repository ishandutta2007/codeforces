#include <cstdio>
#include <cstring>

int main() {
  long long a, b, n;
  scanf("%lld %lld %lld", &a, &b, &n);
  for (int i = 0; i < n; ++i) {
    long long l, t, m;
    scanf("%lld %lld %lld", &l, &t, &m);
    if (a + (l - 1) * b > t) {
      printf("-1\n");
      continue;
    }
    long long le, ri;
    le = l; ri = 1000000 + l;
    while (le + 1 < ri) {
      long long mi = (le + ri) / 2;
      if (a + (mi - 1) * b > t) {
        ri = mi;
        continue;
      }
      if ((mi - l + 1) * a + (l + mi - 2) * b * (mi - l + 1) / 2 <= t * m) {
        le = mi;
      } else {
        ri = mi;
      }
    }
    printf("%lld\n", le);
  }
  return 0;
}