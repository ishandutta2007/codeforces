/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.16
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define sz(a) (int)(a).size()

typedef vector <int> vi;

const int inf = (int)1e9;
const int N = (int)1e5;

int ans, n, m, d, u[N], down[N];
vi c[N];

void precalc( int v, int pr )
{
  int x;
  down[v] = u[v] ? 0 : -inf;
  forn(i, sz(c[v]))
    if ((x = c[v][i]) != pr)
    {
      precalc(x, v);
      down[v] = max(down[v], down[x] + 1);
    }
  //printf("down[%d] = %d\n", v, down[v] );
}

void go( int v, int pr, int dep )
{
  dep--;
  if (u[v])
    dep = min(dep, d);
  //printf("v = %d, pr = %d, dep = %d, down = %d, d = %d\n", v, pr, dep, down[v], d);
  if (dep < 0)
    return;
  ans += (down[v] <= d);
  multiset <int> g;
  int x;
  forn(i, sz(c[v]))
    if ((x = c[v][i]) != pr)
      g.insert(down[x]);
  forn(i, sz(c[v]))
    if ((x = c[v][i]) != pr)
    {
      g.erase(g.find(down[x]));
      //printf("%d --> %d : %d\n", v, x, g.size() ? *g.rbegin() : inf);
      go(x, v, min(dep, g.size() ? d - (*g.rbegin() + 1) : inf));
      g.insert(down[x]);
    }
}

int main()
{
  scanf("%d%d%d", &n, &m, &d);
  forn(i, m)
  {
    int a;
    scanf("%d", &a), a--;
    u[a] = 1;
  }
  forn(i, n - 1)
  {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    c[a].pb(b), c[b].pb(a);
  }
  precalc(0, -1);
  go(0, -1, inf);
  printf("%d\n", ans);
  return 0;
}