#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int h, c, t; cin >> h >> c >> t;
    h -= c; t -= c; c = 0;

    if (2 * t <= h) {
      cout << 2 << '\n';
    } else if (t == h) {
      cout << 1 << '\n';
    } else {
      int i = t / (2 * t - h);
      long long up1 = 1LL * i * h - 1LL * t * (2 * i - 1);
      int dw1 = 2 * i - 1;
      long long up2 = 1LL * t * (2 * i + 1) - 1LL * (i + 1) * h;
      int dw2 = 2 * i + 1;
      assert(up1 >= 0); assert(up2 >= 0);
      if (up1 * dw2 > up2 * dw1) {
        cout << 2 * i + 1 << '\n';
      } else {
        cout << 2 * i - 1 << '\n';
      }
    }
  }

  return 0;
}