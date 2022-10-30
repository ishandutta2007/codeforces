#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double llf;
typedef pair<ll, ll> P;
#define X first
#define Y second

llf Ccw(P a, P b, P c)
{
  return (llf) a.X * (b.Y - c.Y) + (llf) b.X * (c.Y - a.Y) + (llf) c.X * (a.Y - b.Y);
}

const llf EPS = 1e-3;
const int MAX = 200100;

ll pref[MAX];
int p[MAX];
int n;
vector <P> Hull;

void DodajDes(P nov)
{
  for (; Hull.size() > 1 && Ccw(Hull[Hull.size()-2], Hull.back(), nov) <= EPS; )
    Hull.pop_back();

  Hull.push_back(nov);
}

void DodajLijev(P nov)
{
  for (; Hull.size() > 1 && Ccw(Hull[Hull.size()-2], Hull.back(), nov) >= -EPS; )
    Hull.pop_back();

  Hull.push_back(nov);
}

ll Eval(P tmp, int k)
{
  return tmp.X * k + tmp.Y;
}

ll Bin(int k)
{
  int lo = 0, hi = (int) Hull.size() - 1;

  for (; lo<hi; ) {
    int mid = (lo + hi) / 2;
    if (Eval(Hull[mid], k) < Eval(Hull[mid+1], k))
      lo = mid + 1;
    else
      hi = mid;
  }

  return Eval(Hull[lo], k);
}

int main()
{
  scanf("%d", &n);

  ll poc = 0;
  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    poc += (ll) p[i] * i;
    pref[i] = pref[i-1] + p[i];
  }

  ll rje = poc;
  for (int i=n; i; i--) {
    DodajDes(P(i, -pref[i]));

    ll tmp = Bin(p[i]);
    ll val = tmp + pref[i] - (ll) i * p[i];
    rje = max(rje, poc + val);
  }

  Hull.clear();

  for (int i=1; i<=n; i++) {
    DodajLijev(P(i, -pref[i-1]));

    ll tmp = Bin(p[i]);
    ll val = tmp + pref[i-1] - (ll) i * p[i];

    rje = max(rje, poc + val);
  }

  printf("%lld\n", rje);

  return 0;
}