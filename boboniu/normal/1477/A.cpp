#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

int n;
i64 k, x[maxN];

i64 gcd(i64 a, i64 b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &x[i]);
    }
    i64 d = 0;
    for (int i = 1; i < n; i++)
      d = gcd(d, x[i] - x[0]);
    if ((k - x[0]) % d == 0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}