#include <bits/stdc++.h>
using namespace std;
#define maxN 423456

int tc, n;
int cnt[maxN], cnt2[maxN];
int main() {
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n + 1; i++)
      cnt[i] = cnt2[i] = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n + 1; i++) {
      if (cnt2[i]) {
        cnt2[i + 1] = cnt[i];
        ans += 1;
      } else if (cnt[i] > 0) {
        ans += 1;
        cnt2[i + 1] = cnt[i] - 1;
      }
    }
    printf("%d\n", ans);
  }
}