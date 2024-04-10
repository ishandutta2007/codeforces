#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("-1");
  }
  else {
    printf("%d %d %d\n", n, n + 1, n * (n + 1));
  }
  return 0;
}