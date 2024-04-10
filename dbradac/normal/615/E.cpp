#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MIL = 1e9;

ll Gauss(ll x)
{
  return (ll) x * (x + 1) / 2;
}

ll Proso(ll x)
{
  if (x < 0)
    return 0;
  return 6 * Gauss(x) + 1;
}

P Slj(P poc, ll kol, P prav)
{
  return P(poc.X + kol * prav.X, poc.Y + kol * prav.Y);
}

P Pocetak(ll x)
{
  if (!x)
    return P(0, 0);
  return P(-1 + 2 * x, 2);
}

P smj[6] = { P(-1, 2), P(-2, 0), P(-1, -2), P(1, -2), P(2, 0), P(1, 2) };

int main() {
  ll n;

  scanf("%lld", &n);

  if (!n) {
    printf("0 0\n");
    return 0;
  }
  n++;

  ll lo = 0, hi = MIL;
  for (; lo < hi; ) {
    ll mid = (lo + hi) / 2;
    if (Proso(mid) < n)
      lo = mid + 1;
    else
      hi = mid;
  }

  ll prvi = Proso(lo - 1);
  n -= prvi;

  P poz = Pocetak(lo);
  ll pomak = lo;

  for (int i=0;; i++) {
    if (pomak >= n) {
      poz = Slj(poz, (int) (n - 1), smj[i]);
      break;
    }
      
    poz = Slj(poz, pomak - 1, smj[i]);
    n -= pomak - 1;

    if (!i)
      pomak++;
  }
  
  printf("%lld %lld\n", poz.X, poz.Y);

  return 0;
}