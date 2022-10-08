#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 1010;

int dn, n, p[maxn], u[maxn];
pii d[maxn];
vector <int> c[maxn];

int Get( int v )
{
  return v == p[v] ? v : (p[v] = Get(p[v]));
}

void dfs( int v )
{
  u[v] = 1;
  forn(i, sz(c[v]))
    if (!u[c[v][i]])
      dfs(c[v][i]);
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    p[i] = i;
  forn(i, n - 1)
  {
    int a, b, a0, b0;
    scanf("%d%d", &a0, &b0), a0--, b0--;
    a = Get(a0), b = Get(b0);
    if (a != b)
      p[a] = b, c[a0].pb(b0), c[b0].pb(a0);
    else
      d[dn++] = mp(a0, b0);
  }

  printf("%d\n", dn);

  int last = -1;
  forn(i, n)
    if (!u[i])
    {
      dfs(i);
      if (last != -1)
        dn--, printf("%d %d %d %d\n", d[dn].first + 1, d[dn].second + 1, last + 1, i + 1);
      last = i;
    }
  return 0;
}