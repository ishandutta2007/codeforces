#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x;
  scanf("%d%lld", &n, &x);
  int a2 = 0;
  while (n--) {
    char s[4]; int y;
    scanf("%s%d", s, &y);
    if (s[0] == '-') {
      if (x >= y) x -= y;
      else a2++;
    } else x += y;
  }
  printf("%lld %d\n", x, a2);
  return 0;
}