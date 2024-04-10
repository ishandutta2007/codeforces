#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int n, a[110];
int main() {
  scanf("%d", &n);
  int x, y;
  REP(i, n) {
    scanf("%d", &a[i]);
    if (a[i] == 1) x = i;
    if (a[i] == n) y = i;
  }
  if (x > y) swap(x, y);
  printf("%d\n", y - x + max(x, n - 1 - y));
  return 0;
}