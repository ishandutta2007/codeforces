#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long double llf;
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18;

bool Manji(P a, P b)
{
  ll l = (ll) a.X * b.Y;
  ll r = (ll) b.X * a.Y;

  if (l != r)
    return l > r;
  return a.X < b.X;
}

P sor[MAX];
P p[MAX];
llf akoprvi[MAX], akozad[MAX];
ll pref[MAX];
ll ukvr=0;
int n;

llf Eval(int poz, llf c)
{
  return (llf) p[poz].X * (1 - c * pref[poz] / ukvr);
}

int Ok(llf c)
{
  for (int i=0; i<n; ) {
    P poc = p[i];
    llf tmax = -1;

    ll vrijeme = 0;
    for (int j=i; j<n && (ll) poc.X * p[j].Y == (ll) poc.Y * p[j].X; j++)
      vrijeme += p[j].Y;

    ll prije = 0;
    if (i)
      prije = pref[i-1];
    vrijeme += prije;

    for (; i<n && (ll) poc.X * p[i].Y == (ll) poc.Y * p[i].X; i++) {
      akozad[i] = p[i].X * (1 - c * (llf) vrijeme / ukvr);
      if (akozad[i] < tmax)
        return 0;

      akoprvi[i] = p[i].X * (1 - c * (prije + p[i].Y) / ukvr);
      if (i == n-1 || p[i+1] != p[i])
        tmax = max(tmax, akoprvi[i]);
    }
  }

  llf maxx = -1;

  for (int i=0; i<n; ) {
    int poc = sor[i].X;
    int poz = i;

    for (; i<n && sor[i].X == poc; i++)
      if (maxx > akozad[sor[i].Y])
        return 0;

    i=poz;
    for (; i<n && sor[i].X == poc; i++)
      maxx = max(maxx, akoprvi[sor[i].Y]);
  }

  return 1;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i].X);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i].Y);
    ukvr += p[i].Y;
  }

  sort(p, p + n, Manji);
  for (int i=0; i<n; i++)
    sor[i] = P(p[i].X, i);
  sort(sor, sor + n);

  ll pp = 0;
  for (int i=0; i<n; i++) {
    pp += p[i].Y;
    pref[i] = pp;
  }

  llf lo=0, hi=1;

  for (int i=0; i<45; i++) {
    llf mid = (lo + hi) / 2;
    if (Ok(mid))
      lo = mid;
    else
      hi = mid;
  }

  printf("%.10lf\n", (double) lo);

  return 0;
}