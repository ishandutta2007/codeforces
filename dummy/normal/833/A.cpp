#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    long long c = a * b, le = 0, ri = 1e6;
    while (le < ri) {
      long long mid = (le + ri) /2;
      long long p3 = mid * mid * mid;
      if (p3 < c)
        le = mid + 1;
      else
        ri = mid;
    }
    if (c != le * le * le) {
      puts("No");
      continue;
    }
    if ((a % le) != 0 || (b % le) != 0)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}