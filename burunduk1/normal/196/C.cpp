#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef vector <int> vi;
typedef long long ll;

const int maxN = 1510;

int n, x[maxN], y[maxN], size[maxN], res[maxN];
vi c[maxN];

int dfs( int v, int pr )
{
  size[v] = 1;
  forn(i, sz(c[v]))
    if (c[v][i] != pr)
      size[v] += dfs(c[v][i], v);
  return size[v];    
}

bool pless( int i, int j )
{
  return (ll)x[i] * y[j] - (ll)x[j] * y[i] < 0;
}

void go( vi p, int v, int pr )
{
  int mi = 0;
  forn(i, sz(p))
    if (mp(x[p[i]], y[p[i]]) < mp(x[p[mi]], y[p[mi]]))
      mi = i;
  swap(p[mi], p[0]);
  forn(i, sz(p)) if (i)
    x[p[i]] -= x[p[0]], y[p[i]] -= y[p[0]];
  sort(p.begin() + 1, p.end(), pless);
  forn(i, sz(p)) if (i)
    x[p[i]] += x[p[0]], y[p[i]] += y[p[0]];

  int pos = 1, u;
  res[p[0]] = v;
  forn(i, sz(c[v]))
    if ((u = c[v][i]) != pr)
    {
      vi q;
      forn(i, size[u])
        q.pb(p[pos++]);
      go(q, u, v);
    }
}

int main()             
{
  scanf("%d", &n);
  forn(i, n - 1)
  {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    c[a].pb(b), c[b].pb(a);
  }

  vi p;
  forn(i, n)
    scanf("%d%d", &x[i], &y[i]), p.pb(i);
  dfs(0, -1);
  go(p, 0, -1);
  forn(i, n)
    printf("%d ", res[i] + 1);
  return 0;
}