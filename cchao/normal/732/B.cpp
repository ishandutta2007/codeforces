#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int n, k, a[510];
int main() {
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int sum = a[i] + a[i - 1];
    int delta = max(0, k - sum);
    a[i] += delta;
    ans += delta;
  }
  printf("%d\n", ans);
  REP(i, n) printf("%d%c", a[i], " \n"[i == n -1]);
  return 0;
}