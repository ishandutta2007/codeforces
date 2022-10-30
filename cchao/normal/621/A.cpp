#include <bits/stdc++.h>
using namespace std;

int main() {
  long long sum = 0;
  int n, mi = INT_MAX;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    sum += x;
    if (x & 1)
      mi = min(mi, x);
  }
  printf("%lld\n", sum % 2 == 0 ? sum : sum - mi);
  return 0;
}