/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

ll F( ll n ) {
  return n < 0 ? 0 : n * (n + 1) / 2;
}

ll da( int b_max, int c_max, int y ) {
  b_max = min(b_max, y);
  c_max = min(c_max, y);
  if (y < 0 || b_max < 0 || c_max < 0)
    return 0;
  ll res = (ll)(b_max + 1) * (c_max + 1) - F(b_max + c_max - y);
  //printf("da(%d,%d,%d) : %I64d\n", b_max, c_max, y, res);
  return res;
}

int main() {
  int a, b, c, l;
  ll ans = 0;
  cin >> a >> b >> c >> l;
  forn(x, l + 1) {
    int y = l - x;
    if (b + c + y > a + x) {
      int mi = max(0, (a + x + 1) - (b + c));
      int b_max = min(y, a + x - b);
      int c_max = min(y, a + x - c);
      //ll da = (ll)(b_max + 1) * (c_max + 1) - (b_max + c_max <= y ? 0 : F(y - b_max) + F(y - c_max));
      //printf("x=%d a : %d, %d : +%I64d\n", x, b_max, c_max, da);
      ans += da(b_max, c_max, y) - da(b_max, c_max, mi - 1);
    }
    //printf("%d: %I64d\n", x, ans);
    if (a + c + y > b + x) {
      int mi = max(0, (b + x + 1) - (a + c));
      int a_max = min(y, b + x - a - 1);
      int c_max = min(y, b + x - c);
      //ll da = (ll)(a_max + 1) * (c_max + 1) - (a_max + c_max <= y ? 0 : F(y - a_max) + F(y - c_max));
      ////printf("x=%d b : %d, %d : +%I64d\n", x, a_max, c_max, da);
      ans += da(a_max, c_max, y) - da(a_max, c_max, mi - 1);
    }
    //printf("%d: %I64d\n", x, ans);
    if (a + b + y > c + x) {
      int mi = max(0, (c + x + 1) - (a + b));
      int a_max = min(y, c + x - a - 1);
      int b_max = min(y, c + x - b - 1);
      //ll da = (ll)(a_max + 1) * (b_max + 1) - (a_max + b_max <= y ? 0 : F(y - a_max) + F(y - b_max));
      ////printf("x=%d c : %d, %d : +%I64d\n", x, a_max, b_max, da);
      ans += da(a_max, b_max, y) - da(a_max, b_max, mi - 1);
    }
    //printf("%d: %I64d\n", x, ans);
  }
  cout << ans << endl;
}