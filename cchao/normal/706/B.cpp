#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int n, a[100010];
int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", int(upper_bound(a, a + n, x) - a));
  }
  return 0;
}