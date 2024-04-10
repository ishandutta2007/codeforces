/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.10.15
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int sum, ans, n, a, c[5];

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a), c[a]++, sum += a;
  if (sum == 1 || sum == 2 || sum == 5)
  {
    puts("-1");
    return 0;
  }

  //forn(i, 5) printf("%d%c", c[i], " \n"[i == 4]);
  //printf("ans = %d\n", ans);

  while (c[1] && c[2])
    c[1]--, c[2]--, c[3]++, ans++;

  //forn(i, 5) printf("%d%c", c[i], " \n"[i == 4]);
  //printf("ans = %d\n", ans);

  while (c[1] >= 3)
    c[1] -= 3, c[3]++, ans += 2;
  while (c[2] >= 3)
    c[2] -= 3, c[3] += 2, ans += 2;
  if (c[2] >= 2)
    c[2] -= 2, c[4]++, ans += 2;
  
  //forn(i, 5) printf("%d%c", c[i], " \n"[i == 4]);
  //printf("ans = %d\n", ans);

  if (c[2])
    if (c[4])
      ans++;
    else
      ans += 2;
  else if (c[1] == 2)
    ans += 2;
  else if (c[1] == 1)
  {
    if (c[3])
      ans++;
    else
      ans += 2;
  }
  printf("%d\n", ans);
  return 0;
}