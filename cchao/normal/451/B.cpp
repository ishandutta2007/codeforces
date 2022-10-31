#include <bits/stdc++.h>
using namespace std;

int n, a[100010], b[100010];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  pair<int, int> ans = {1, 1};
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      int j = n - 1;
      while (a[j] != b[i]) j--;
      reverse(a + i, a + j + 1);
      ans = {i + 1, j + 1};
      break;
    }
  }
  if (is_sorted(a, a + n)) {
    puts("yes");
    printf("%d %d\n", ans.first, ans.second);
  } else puts("no");
  return 0;
}