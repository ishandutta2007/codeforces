/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.15
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n, cur = 0, q = 0, t, c, ma = 0;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d%d", &t, &c);
    q -= t - cur;
    if (q < 0)
      q = 0;
    cur = t;
    q += c;
    ma = max(ma, q);
  }
  printf("%d %d\n", cur + q, ma);
  return 0;
}