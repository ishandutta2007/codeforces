#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 323456
const i64 P = 998244353;
int a[maxN], n;

i64 inv(i64 r) {
  if (r == 1)
    return 1;
  return (P - P / r) * inv(P % r) % P;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + 2 * n);
  i64 sa = 0;
  for (int i = 0; i < n; i++)
    sa += a[i + n] - a[i];
  i64 fac = 1, rfac = 1;
  for (int i = 1; i <= n; i++)
    fac = fac * (n + i) % P, rfac = rfac * i % P;
  sa %= P;
  sa = sa * fac % P * inv(rfac) % P;
  printf("%lld\n", sa);
}