/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.15
 */

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

const int maxN = (int)1e6;

int n, m, cnt, u[maxN];
vector <int> c[maxN];

void finish( const char *s )
{
  puts(s);
  exit(0);
}

void go( int v )
{
  if (u[v])
    return;
  cnt++, u[v] = 1;
  forn(i, sz(c[v]))
    go(c[v][i]);
}

int connected()
{
  go(0);
  return cnt == n;
}

void go()
{
  if (m == n)
  {
    int v = 0;
    forn(i, n)
      if (sz(c[v]) > sz(c[i]))
        v = i;
    if (sz(c[v]) == 2)
      finish("ring topology");
  }
  else if (m == n - 1)
  {
    int v = 0;
    forn(i, n)
      if (sz(c[v]) < sz(c[i]))
        v = i;
    if (sz(c[v]) == n - 1)
      finish("star topology");
    else if (sz(c[v]) == 2)
      finish("bus topology");
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, m)
  {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    c[a].pb(b), c[b].pb(a);
  }
  if (connected())
    go();
  puts("unknown topology");
  return 0;
}