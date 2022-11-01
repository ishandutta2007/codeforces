#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, d, b;
int c[N];

int bisa(int x) {
  for (int i = 0; i < n; ++i) c[i] = a[i];
  int sum = 0;
  int need = (n + 1)/2 - x;
  int tot = need * b;
  for (int i = 0, j = 0; i + i < n; ++i) {
    while (j <= (i + d * (i+1)) && j < n) {
      int v = min(c[j], tot);
      c[j] -= v;
      tot -= v;
      sum += v;
      ++j;
    }
    if (sum >= b) {
      --need;
      sum -= b;
    }
  }
  if (need > 0) return false;
  need = n/2 - x;
  sum = 0;
  for (int i = 0, j = 0; i+i+1 < n; ++i) {
    while (j <= (i + d * (i+1)) && j < n) {
      int v = c[n-1-j];
      c[n-1-j] -= v;
      sum += v;
      ++j;
    }
    if (sum >= b) {
      --need;
      sum -= b;
    }
  }
  if (need > 0) return false;
  return true;
}


int main() {
  scanf("%d %d %d", &n, &d, &b);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int l = 0, r = (n+1)/2;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (bisa(mid))
      r = mid;
    else
      l = mid+1;
  }
  printf("%d\n", l);
  return 0;
}