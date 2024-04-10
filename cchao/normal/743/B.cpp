#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

void f(int n, LL k) {
  LL len = (1LL << n) - 1;
  LL half = len / 2;
  if (k == half) {
    printf("%d\n", n);
    return;
  } else if (k < half) {
    f(n - 1, k);
  } else {
    f(n - 1, k - half - 1);
  }
}

int main() {
  LL n, k;
  scanf("%lld%lld", &n, &k);
  f(n, k - 1);
  return 0;
}