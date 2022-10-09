#include <bits/stdc++.h>
using namespace std;

#define llong long long 

int main() {
  llong n; cin >> n;
  llong ans = 0;
  for (llong i = 1; i <= n; ++i) {
    for (llong f = i; f <= n; ++f) {
      llong x = round(i * i + f * f);
      if (x <= n * n) {
        llong t = sqrt(x);
        if (t * t == x) ++ ans;
      }
    }
  }
  cout << ans;
}