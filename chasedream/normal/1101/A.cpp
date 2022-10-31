%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

long long l, r, d;

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &l, &r, &d);
    if (d < l) {
      printf("%lld\n", d);
    } else {
      ll bas = r / d + 1;
      printf("%lld\n", bas * d);
    }
  }
  return 0;
}