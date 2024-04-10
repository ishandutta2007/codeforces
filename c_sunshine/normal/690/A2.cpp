#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n & 1) {
    printf("%d\n", (n - 1) / 2);
  } else {
    n ^= 1 << (31 - __builtin_clz(n));
    printf("%d\n", n / 2);
  }
  return 0;
}