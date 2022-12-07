#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n;
long long k;
int a[maxN];
int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
      ans += max(0, a[i] - a[i + 1]);
    printf("%lld\n", ans);
  }
}