#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 2234

i64 comb[maxN][maxN], dpway[maxN][maxN], dpcnt[maxN][maxN];
i64 way[maxN];
i64 cnt[maxN];
i64 p;
int n, m;

int main() {
  int tc;
  scanf("%d%d%lld", &n, &m, &p);
  for (int i = 0; i <= n; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;
    }
  }
  way[0] = 1;
  way[1] = 2;
  cnt[1] = 0;
  for (int i = 2; i <= m; i++) {
    for (int l = 0; l < i; l++) {
      int r = i - 1 - l;
      i64 pway = way[l] * way[r] % p * comb[l + r][l] % p * (i + 1) % p;
      i64 pcnt = ((cnt[l] * way[r] + cnt[r] * way[l]) % p * comb[l + r][l] % p *
                      (i + 1) +
                  way[l] * way[r] % p * comb[l + r][l] % p *
                      (l * (l + 1) / 2 + r * (r + 1) / 2)) %
                 p;
      way[i] = (way[i] + pway) % p;
      cnt[i] = (cnt[i] + pcnt) % p;
    }
  }
  dpway[0][0] = 1;
  dpcnt[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i && j <= m; j++) {
      dpway[i][j] = dpway[i - 1][j];
      dpcnt[i][j] = dpcnt[i - 1][j];
      if (i == j) {
        dpway[i][i] = way[i];
        dpcnt[i][i] = cnt[i];
      }
      for (int k = 1; k <= i - 1 && k <= j; k++) {
        i64 pway = dpway[i - k - 1][j - k] * way[k] % p * comb[j][k] % p;
        i64 pcnt = (dpcnt[i - k - 1][j - k] * way[k] +
                    dpway[i - k - 1][j - k] * cnt[k]) %
                   p * comb[j][k] % p;
        dpway[i][j] = (dpway[i][j] + pway) % p;
        dpcnt[i][j] = (dpcnt[i][j] + pcnt) % p;
      }
    }
  printf("%lld\n", dpcnt[n][m]);
}