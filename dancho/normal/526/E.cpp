#include <cstdio>
#include <cstring>

int n, q;
long long a[1 << 20];
long long ps[1 << 20];

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  ps[0] = a[0];
  for (int i = 1; i < n; ++i) {
    ps[i] = ps[i - 1] + a[i];
  }

  long long b;
  for (int i = 0; i < q; ++i) {
    scanf("%lld", &b);
    int s = 0;
    int cnt = 1;
    long long sm = 0;
    for (int j = 0; j < n; ++j) {
      if (sm + a[j] > b) {
        ++cnt;
        s = j;
        sm = 0;
      }
      sm += a[j];
    }
    int an = cnt;
    while (s > 0 && a[0] + ps[n - 1] - ps[s - 1] <= b) {
      sm = ps[n - 1] - ps[s - 1];
      cnt = 1;
      int os = s;
      for (int j = 0; j < os; ++j) {
        if (sm + a[j] > b) {
          ++cnt;
          s = j;
          sm = 0;
        }
        sm += a[j];
      }
      if (cnt < an)
        an = cnt;
    }
    if (an < 1)
      an = 1;
    printf("%d\n", an);
  }
  return 0;
}