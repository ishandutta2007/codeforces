/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.16
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int k, b, n, t, cnt = 0;
  scanf("%d%d%d%d", &k, &b, &n, &t);

  long long x = 1;
  while (x <= t)
    cnt++, x = k * x + b;
  printf("%d\n", max(0, n - cnt + 1));
  return 0;
}