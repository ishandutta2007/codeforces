/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com5
 * Date: 2013.10.15
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = (int)3e5;

int n, m, ans[N], next[N];
int sn, s[N];

void mark( int l, int r, int x )
{
  while (l <= r)
  {
    if (!ans[l])
      ans[l] = x + 1;
    s[sn++] = l, l = next[l];
  }
  while (sn)
    next[s[--sn]] = l;
}

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, n)
    next[i] = i + 1;
  while (m--)
  {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x), l--, r--, x--;
    mark(l, x - 1, x);
    mark(x + 1, r, x);
  }
  forn(i, n)
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  return 0;
}