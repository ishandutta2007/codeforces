/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.22
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = (int)2e6 + 10;

int n, cnt[2][2], k[2];
char s[N], t[N];

int main()
{
  scanf("%d ", &n);
  gets(s);
  gets(t);
  forn(i, 2 * n)
    cnt[s[i] - '0'][t[i] - '0']++;
  forn(i, 2 * n)
  {
    int x, y;
    if (cnt[1][1])
      x = 1, y = 1;
    else if (cnt[0][1])
      x = 0, y = 1;
    else if (cnt[1][0])
      x = 1, y = 0;
    else
      x = 0, y = 0;
    k[i & 1] += (i & 1) ? y : x;
    cnt[x][y]--;
  }
  if (k[0] > k[1])
    puts("First");
  else if (k[0] < k[1])
    puts("Second");
  else
    puts("Draw");
  return 0;
}