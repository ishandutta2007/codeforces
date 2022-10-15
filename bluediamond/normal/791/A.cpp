#include <cstdio>

int main(void) {
  int a, b;
  scanf("%d%d", &a, &b);
  int y = 0;
  while (a <= b) {
    a *= 3;
    b *= 2;
    y++;
  }

  printf("%d\n", y);
  return 0;
}