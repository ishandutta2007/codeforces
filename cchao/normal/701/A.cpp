#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[110], n, b[110];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = i;
  }
  sort(b + 1, b + 1 + n, [a](int x, int y) {
    return a[x] < a[y];
  });
  for (int i = 1, j = n; i < j; ++i, --j)
    printf("%d %d\n", b[i], b[j]);
  return 0;
}