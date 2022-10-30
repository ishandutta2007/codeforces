#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int main() {
  int n;
  scanf("%d", &n);
  int r = 1;
  for (int a = 8; n; a = (a * a) % 10, n >>= 1)
    if (n & 1)
      r = r * a % 10;
  printf("%d\n", r);
  return 0;
}