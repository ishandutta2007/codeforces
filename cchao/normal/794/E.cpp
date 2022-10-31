#include <bits/stdc++.h>
using namespace std;

int n, a[300010], ans[300010];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  ans[n - 1] = *max_element(a, a + n);
  for (int i = 0; i + 1 < n; ++i) {
    int got = max(a[i], a[i + 1]);
    int left = i;
    int right = n - i - 2;
    int required = left + right - min(left, right) * 2;
    ans[required] = max(ans[required], got);
  }
  for (int i = 0; i + 2 < n; ++i) {
    int got = min(a[i + 1], max(a[i], a[i + 2]));
    int left = i;
    int right = n - i - 3;
    int required = left + right - min(left, right) * 2;
    ans[required] = max(ans[required], got);
  }
  for (int i = 0; i < n; ++i) {
    if (i >= 2) ans[i] = max(ans[i], ans[i - 2]);
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}