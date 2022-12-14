#include <cstdio>
#include <cstring>

int n, m, b, mod;
int a[1024];

long long f[1024][1024];
int main() {
  memset(f, 0, sizeof(f));
  scanf("%d %d %d %d", &n, &m, &b, &mod);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k <= b; ++k) {
        f[j + 1][k + a[i]] += f[j][k];
        while (f[j + 1][k + a[i]] >= mod) {
          f[j + 1][k + a[i]] -= mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= b; ++i) {
    ans += f[m][i];
    if (ans >= mod)
      ans %= mod;
  }
  printf("%d\n", (int) ans);
  return 0;
}