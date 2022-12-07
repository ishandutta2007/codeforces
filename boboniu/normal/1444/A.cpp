#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 123456

i64 p, pf[50], ex[50];
int q;

void solve() {
  scanf("%lld%d", &p, &q);
  if (p % q != 0) {
    printf("%lld\n", p);
    return;
  }
  int r = q;
  int t = 0;
  for (int i = 2; i * i <= r; i++) {
    if (r % i == 0) {
      pf[t] = i;
      ex[t] = 0;
      while (r % i == 0) {
        r /= i;
        ex[t]++;
      }
      ++t;
    }
  }
  if (r != 1) {
    pf[t] = r;
    ex[t] = 1;
    ++t;
  }
  i64 ans = 1;
  for (int i = 0; i < t; i++) {
    int pex = 0;
    i64 r = p;
    while (r % pf[i] == 0)
      r /= pf[i], pex++;
    r = p;
    while (pex >= ex[i])
      pex -= 1, r /= pf[i];
    ans = max(ans, r);
  }
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
}