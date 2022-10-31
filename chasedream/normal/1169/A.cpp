#include <bits/stdc++.h>
using namespace std;

int n, a, b, x, y;

int main() {
  scanf("%d%d%d%d%d", &n, &a, &x, &b, &y);
  
  for (int i = 1; i <= n; i++) {
    //printf("%d %d\n", a, b);
    if (a == x || b == y) break;
    a++; if (a > n) a -= n;
    b--; if (b < 1) b += n;
    if (a == b) {
      puts("YES");
      exit(0);
    }
  }
  puts("NO");
  return 0;
}