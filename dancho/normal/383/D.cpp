#include <cstdio>
#include <cstring>

const int mod = 1000000007;
const int hsum = 5002;

int n;
int a[1024];
long long sm[1024][10020];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  memset(sm, 0, sizeof(sm));
  ++sm[0][hsum];
  long long sol = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = a[i]-hsum; j <= hsum; ++j) {
      sm[i+1][j+hsum] += sm[i][j-a[i]+hsum];
      if (sm[i+1][j+hsum] >= mod)
        sm[i+1][j+hsum] %= mod;
    }

    for (int j = -hsum; j + a[i] <= hsum; ++j) {
      sm[i+1][j+hsum] += sm[i][j+a[i]+hsum];
      if (sm[i+1][j+hsum] >= mod)
        sm[i+1][j+hsum] %= mod;
    }
    sol += sm[i+1][hsum];
    if (sol >= mod)
      sol %= mod;
    ++sm[i+1][hsum];
    if (sm[i+1][hsum] >= mod)
      sm[i+1][hsum] %= mod;
  }

  printf("%d\n", (int) sol);
  return 0;
}