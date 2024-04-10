#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;
long long n, m, s;

int main() {
  scanf("%lld%lld%lld", &n, &m, &s);
  a = n % s, b = m % s, c = n / s, d = m / s;
  if (a == 0) a = s; else c++;
  if (b == 0) b = s; else d++;
  printf("%lld\n", a * b * c * d);
  return 0;
}