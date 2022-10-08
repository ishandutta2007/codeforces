#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef vector <int> vi;
typedef long long ll;
typedef pair <ll, int> pii;

const int maxN = (int)2e5 + 10;
const int maxM = (int)4e5 + 10;

int n, m, k, type[maxN], a[maxN], pa[maxN];
ll d[maxN];
vi c[maxN], w[maxN];
set <pii> s;

int en, ea[maxM], eb[maxM], ep[maxM];
ll ew[maxM];

inline bool wless( int i, int j )
{
  return ew[i] < ew[j];
}

int get( int v )
{
  return v == pa[v] ? v : (pa[v] = get(pa[v]));
}

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, m)
  {
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x), a--, b--;
    c[a].pb(b), w[a].pb(x);
    c[b].pb(a), w[b].pb(x);
  }

  scanf("%d", &k);
  forn(i, n)
    d[i] = (ll)1e18;
  forn(i, k)
  {
    scanf("%d", &a[i]), a[i]--;
    d[a[i]] = 0, type[a[i]] = i;
  }
  forn(i, n)
    s.insert(mp(d[i], i));
  while (sz(s))
  { 
    int v = s.begin()->second;
    s.erase(s.begin());
    forn(i, sz(c[v]))
    {
      int u = c[v][i];
      ll tmp = d[v] + w[v][i];
      if (d[u] > tmp)
      {
        s.erase(mp(d[u], u));
        d[u] = tmp, type[u] = type[v];
        s.insert(mp(d[u], u));
      }
    }
  }

  forn(v, n)
    forn(i, sz(c[v]))
    {
      int u = c[v][i];
      if (type[v] != type[u])
      {
        ea[en] = type[v];
        eb[en] = type[u];
        ep[en] = en;
        ew[en] = d[v] + d[u] + w[v][i];
        en++;
      }
    }

  ll ans = d[0];
  sort(ep, ep + en, wless);
  forn(i, k)
    pa[i] = i;
  forn(_i, en)
  {
    int i = ep[_i];
    if (get(ea[i]) != get(eb[i]))
      pa[get(ea[i])] = get(eb[i]), ans += ew[i];
  }
  printf("%I64d\n", ans);
  return 0;
}