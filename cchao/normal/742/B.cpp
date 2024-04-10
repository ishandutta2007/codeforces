#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  map<int, int> m;
  LL ans = 0;
  while (n--) {
    int t;
    scanf("%d", &t);
    ans += m[x ^ t];
    m[t]++;
  }
  printf("%lld\n", ans);
  return 0;
}