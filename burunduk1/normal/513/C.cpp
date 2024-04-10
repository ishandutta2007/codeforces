/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.06
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#define IS(a, i) (((a) >> (i)) & 1)

typedef long double dbl;

int main() {
  int n;
  cin >> n;
  int l[n], r[n];
  forn(i, n) 
    cin >> l[i] >> r[i];
  dbl a = 0, b = 0;
  forab(x, 1, 10000) 
    forn(i, 1 << n) if (i) {
      int bn = 0, bad = 0;
      forn(j, n)
        if (IS(i, j))
          bn++, bad |= !(l[j] <= x && x <= r[j]);
      if (bad)
        continue;
      dbl num = 0;
      if (bn >= 2) {
        dbl t = 1;
        forn(j, n)
          if (!IS(i, j))
            t *= max(0, min(r[j] + 1, x) - l[j]);
        num += t;
      }
      forn(k, n)
        if (!IS(i, k)) {
          dbl t = 1;
          forn(j, n)
            if (!IS(i, j)) 
              t *= max(0, j == k ? r[j] - max(x, l[j] - 1) : min(r[j] + 1, x) - l[j]);
          num += t;
        }
      //if (num > 0)
      //  printf("x = %d, i = %d : %g\n", x, i, double(num));
      b += num, a += num * x;
    }
  printf("%.20f\n", (double)(a / b));
  return 0;
}