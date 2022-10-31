#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) puts("-1");
  else printf("%d %d %d\n", n, n + 1, n * (n + 1));
  return 0;
}