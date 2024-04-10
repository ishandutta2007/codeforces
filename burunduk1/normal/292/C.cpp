/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.15
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

int n, k, is[10], u[10];
char s[10], t[99], tmp[99];
int an, a[4];
vector <string> res;

void rec( int i, int j, int len )
{
  if (i == len && j == 4)
  {
    sprintf(tmp, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
    res.pb(tmp);
  }
  if (i == len || j == 4)
    return;
  if (i + (4 - j) > len)
    return;
  if (i + 3 * (4 - j) < len)
    return;
  if (i + 1 <= len)
    a[j] = t[i], rec(i + 1, j + 1, len);
  if (i + 2 <= len && t[i] != 0)
    a[j] = t[i] * 10 + t[i + 1], rec(i + 2, j + 1, len);
  if (i + 3 <= len && t[i] != 0)
  {
    a[j] = ((int)t[i] * 10 + t[i + 1]) * 10 + t[i + 2];
    if (a[j] < 256)
      rec(i + 3, j + 1, len);
  }
}

void add( int len )
{
  rec(0, 0, len);
}

void go( int i )
{
  int good = 1;
  forn(j, 10)
    if (is[j] && !u[j])
      good = 0;
  if (i && good)
  {
    memcpy(t, s, i);
    memcpy(t + i, s, i);
    reverse(t + i, t + 2 * i);
    add(2 * i);
    memcpy(t + i - 1, s, i);
    reverse(t + i - 1, t + 2 * i - 1);
    add(2 * i - 1);
  }
  if (i == 6)
    return;
  forn(j, 10)
    if (is[j])
      s[i] = j, u[j]++, go(i + 1), u[j]--;
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &k), is[k] = 1;
  go(0);
  printf("%d\n", res.size());
  forn(i, res.size())
    printf("%s\n", res[i].c_str());
  return 0;
}