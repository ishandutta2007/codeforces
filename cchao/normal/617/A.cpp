#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 5; i >= 1; --i) {
    ans += n / i;
    n %= i;
  }
  printf("%d\n", ans);
  return 0;
}