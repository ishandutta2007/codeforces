#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define P 998244353
#define maxN 2234

i64 dp[maxN][maxN], tmp[maxN][maxN], fac[maxN], rfac[maxN];
int n, k;
i64 fastpow(i64 a, int b) {
  i64 ans = 1;
  a %= P;
  while (b) {
    if (b % 2)
      ans = ans * a % P;
    a = a * a % P;
    b /= 2;
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &k);
  dp[0][0] = 1;
  fac[0] = rfac[0] = 1;
  for (int i = 1; i <= 2000; i++) {
    fac[i] = fac[i - 1] * i % P;
    rfac[i] = fastpow(fac[i], P - 2);
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);
    s += l;
    vector<array<int, 3>> term;
    for (int j = 0; l - j * k > 0; j++) {
      int sign = 1;
      if (j % 2 == 1)
        sign = -1;
      term.push_back(
          {l - j * k, j, (int)(fastpow(l - j * k, j) * rfac[j] % P * sign)});
      if (j > 0)
        term.push_back(
            {l - j * k, j - 1,
             (int)(fastpow(l - j * k, j - 1) * rfac[j - 1] % P * sign)});
    }
    for (int p = 0; p <= 2000; p++)
      for (int q = 0; q <= 2000; q++)
        tmp[p][q] = dp[p][q], dp[p][q] = 0;
    for (int p = 0; p <= 2000; p++)
      for (int q = 0; q <= 2000; q++)
        if (tmp[p][q] != 0) {
          for (auto t : term)
            dp[p + t[0]][q + t[1]] =
                (dp[p + t[0]][q + t[1]] + tmp[p][q] * t[2]) % P;
        }
  }
  for (int i = 0; i <= 2000; i++) {
    for (int j = 0; j <= 2000; j++)
      dp[i][j] = (P - dp[i][j]) % P;
  }
  dp[s][0] = 0;
  i64 invs = fastpow(s, P - 2), ans = 0;
  for (int a = 0; a <= 2000; a++)
    for (int b = 0; b <= 2000; b++)
      if (dp[a][b] != 0) {
        i64 tmp = dp[a][b] * fac[b] % P * fastpow(invs, b) % P *
                  fastpow(P + 1 - a * invs % P, P - 2 - b) % P;
        ans = (ans + tmp) % P;
      }
  printf("%lld\n", ans);
}