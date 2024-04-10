#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

ll f[100];

int rek(ll n, int k, ll ind)
{
  assert(k >= 0);
  if (ind < f[k-1]) return rek(n/2, k-1, ind);
  if (ind == f[k-1]) return (int) (n % 2);
  return rek(n/2, k-1, ind - f[k-1] - 1);
}

int main()
{
  f[0] = 1;
  FOR(i, 1, 100) {
    f[i] = 2 * f[i-1] + 1;
    TRACE(i _ f[i]);
  }

  ll n, l, r;
  scanf("%lld%lld%lld", &n, &l, &r); l--; r--;

  int tmpk = 0;
  for (ll tmp=2; tmp<=n; tmp*=2, tmpk++);
  TRACE(tmpk);

  int rje = 0;
  for (ll i=l; i<=r; i++)
    rje += rek(n, tmpk, i);

  printf("%d\n", rje);

  return 0;
}