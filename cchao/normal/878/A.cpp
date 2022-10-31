#include <bits/stdc++.h>
using namespace std;
int n;
char s[4];
int x;
int a[2] = {0, 1023};
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", s, &x);
    if (s[0] == '|') a[0] |= x, a[1] |= x;
    else if (s[0] == '&') a[0] &= x, a[1] &= x;
    else a[0] ^= x, a[1] ^= x;
  }
  int ans[3] = {0, 1023, 0};
  for (int i = 0, j = 1; i < 10; ++i, j <<= 1) {
    int x = a[0] & j;
    int y = a[1] & j;
    if (x == j && y == j) ans[0] ^= j;
    else if (x == 0 && y == 0) ans[1] ^= j;
    else if (x == j && y == 0) ans[2] ^= j;
  }
  printf("%d\n", 3);
  printf("| %d\n", ans[0]);
  printf("& %d\n", ans[1]);
  printf("^ %d\n", ans[2]);
  return 0;
}