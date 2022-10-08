/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.03
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 1010;
const int inf = (int)1e9;

int n, cnt[26];
char s[N];

int main()
{
  scanf("%s%d", s, &n);
  for (int i = 0; s[i]; i++)
    cnt[s[i] - 'a']++;

  int l = 1, r = inf;
  while (l < r)
  {
    int m = (l + r) / 2, k = 0;
    forn(i, 26)
      k += (cnt[i] + m - 1) / m;
    if (k <= n)
      r = m;
    else
      l = m + 1;
  }
  if (l == inf)
  {
    puts("-1");
    return 0;
  }
  printf("%d\n", l);
  forn(i, 26)
    forn(j, (cnt[i] + l - 1) / l)
      putchar('a' + i), n--;
  while (n--)
    putchar('z');
  return 0;
}