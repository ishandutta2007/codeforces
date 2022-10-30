#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double llf;
typedef pair<int, int> P;
#define X first
#define Y second


int n, k, kol;
llf l, v1, v2;

int Ok(llf poz)
{
  llf kraj = poz, poc = v1 / v2 * poz;  

  for (int i=1; i<kol; i++) {
    llf t1 = (kraj - poc) / (v1 + v2);
    llf npoc = poc + v1 * t1;
    llf nkraj = kraj + v1 * t1;
    llf t2 = (nkraj - npoc) / (v2 - v1);

    poc += v1 * (t1 + t2);
    kraj += v1 * (t1 + t2);
    if (kraj > l)
      return 0;
  }

  return 1;
}

int main()
{
  cin >> n >> l >> v1 >> v2 >> k;

  kol = (n - 1) / k + 1;

  llf lo = 0, hi = l;

  for (int i=0; i<200; i++) {
    llf mid = (lo + hi) / 2;
    if (Ok(mid))
      lo = mid;
    else
      hi = mid;
  }

  printf("%.10lf\n", (double) (lo / v2 + (l - lo) / v1));

  return 0;
}