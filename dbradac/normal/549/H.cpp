#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> P;

P Interval(ld a, ld b, ld x)
{
  ld minn, maxx;
  ld sn[2] = {1, -1};

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      ld tmp = (a + x * sn[i]) * (b + x * sn[j]);
      if (!i && !j)
        minn = maxx = tmp;
      else {
        minn = min(minn, tmp);
        maxx = max(maxx, tmp);
      }
    }
  }

  return P(minn, maxx);
}

int main()
{
  ld a, b, c, d;

  cin >> a >> b >> c >> d;

  ld lo = 0, hi = 1e18;

  for (int i=0; i<500; i++) {
    ld mid = (lo + hi) / 2;

    P left = Interval(a, d, mid);
    P right = Interval(b, c, mid);

    if (max(left.first, right.first) < min(left.second, right.second))
      hi = mid;
    else
      lo = mid;
  }

  cout << setprecision(14) << lo << endl;

  return 0;
}