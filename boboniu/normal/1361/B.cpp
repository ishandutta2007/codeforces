#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1000000007;

int fastpow(int a, int n) {
  int b = 1;
  while (n) {
    if (n & 1)
      b = (i64)b * a % P;
    a = (i64)a * a % P;
    n /= 2;
  }
  return b;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    int n, p;
    scanf("%d%d", &n, &p);
    map<int, int> prob;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      prob[-x] += 1;
    }
    i64 ans1 = 0, ans2 = 0;
    if (p == 1) {
      printf("%d\n", n % 2);
      continue;
    }
    int pre = 1 << 30;
    i64 inf = 1ll << 60;
    for (auto k : prob) {
      int val = -k.first;
      int cnt = k.second;
      if (ans1 != 0) {
        if (pre - val > 30) {
          ans1 = inf;
        } else {
          for (int j = 0; j < pre - val; j++) {
            if (inf / ans1 / p)
              ans1 = ans1 * p;
            else {
              ans1 = inf;
              break;
            }
          }
        }
      }
      if (ans1 >= cnt) {
        ans1 -= cnt;
        ans2 = (ans2 - (i64)cnt * fastpow(p, val)) % P;
      } else {
        cnt -= ans1;
        cnt %= 2;
        ans1 = cnt;
        if (cnt)
          ans2 = fastpow(p, val);
        else
          ans2 = 0;
      }
      pre = val;
    }
    if (ans2 < 0)
      ans2 += P;
    printf("%lld\n", ans2);
  }
}