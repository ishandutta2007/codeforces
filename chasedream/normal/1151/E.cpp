%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int a[maxn], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int za = a[i], zb = a[i + 1];
    if (za > zb) ans += (long long)(za - zb) * (n - za + 1);
    else         ans += (long long)(zb - za) * za;
  }
  printf("%lld\n", ans);
  return 0;
}