#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 623456
#define P 1000000007

int tc;
int n;
i64 a[maxN], pow2[100];
int cnt[100][2];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < 60; i++)
    cnt[i][0] = cnt[i][1] = 0;
  for (int i = 0; i < n; i++) {
    i64 x;
    scanf("%lld", &x);
    a[i] = x;
    for (int i = 0; i < 60; i++)
      cnt[i][(x >> i) & 1]++;
  }
  i64 ans = 0;
  for (int i = 0; i < 60; i++)
    pow2[i] = (1ll << i) % P;
  for (int i = 0; i < n; i++) {
    i64 s0 = 0, s1 = 0;
    for (int j = 0; j < 60; j++) {
      int b = (a[i] >> j) & 1;
      if (b == 0)
        s1 = (s1 + cnt[j][1] * pow2[j]) % P;
      else {
        s0 = (s0 + cnt[j][1] * pow2[j]) % P;
        s1 = (s1 + n * pow2[j]) % P;
      }
    }
    ans = (ans + s0 * s1) % P;
  }
  printf("%lld\n", ans);
}

int main() {
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    solve();
  }
}