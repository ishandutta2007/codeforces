#include <bits/stdc++.h>
using namespace std;
#define maxN 2222222
#define P 998244353

long long inv[maxN], fac[maxN], rfac[maxN], ans;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  fac[0] = fac[1] = 1;
  rfac[0] = rfac[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= 2000001; i++) {
    inv[i] = (P - P / i) * inv[P % i] % P;
    fac[i] = fac[i - 1] * i % P;
    rfac[i] = rfac[i - 1] * inv[i] % P;
  }
  for (int i = 1; i <= n; i++) {
    long long c =
        fac[n] * rfac[i] % P * rfac[n - i] % P * (1 + m * inv[i] % P) % P;
    if (i % 2 == 1)
      ans = (ans + c) % P;
    else
      ans = (ans + P - c) % P;
  }
  ans = ans * (n + m + 1) % P * inv[m + 1] % P;
  printf("%lld\n", ans);
}