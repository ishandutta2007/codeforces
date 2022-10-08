/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.13
 */

#include <cstdio>
#include <cassert>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int n, a, cnt, bad;
map <int, int> m;

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a), m[a]++;
  for (auto it = m.begin(); it != m.end(); it++)
    if (it->first)
      if (it->second == 2)
        cnt++;
      else if (it->second > 2)
        bad = 1;
  printf("%d\n", bad ? -1 : cnt);
  return 0;
}