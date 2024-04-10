#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int a[1 << 20];
int c[1 << 20];

int ia(int x) {
  if (x < 0)
    return -x;
  return x;
}

int main() {
  scanf("%d", &n);
  int orig = 0;
  for (int i = 2; i < (1 << (n + 1)); ++i) {
    scanf("%d", &a[i]);
    orig += a[i];
  }

  memset(c, 0, sizeof(c));
  int plant = 0;
  for (int i = (1 << n) - 1; i >= 1; --i) {
    int j = i * 2;
    int k = i * 2 + 1;
    int t = ia(a[j] + c[j] - a[k] - c[k]);
    plant += t;
    c[i] = std::max(a[j] + c[j], a[k] + c[k]);
  }
  printf("%d\n", plant);

  return 0;
}