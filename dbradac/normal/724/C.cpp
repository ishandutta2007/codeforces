#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

//P je par long longova
//vraca -1 ako je sustav nekonzistentan
//do GRAN sito ide

namespace crt {
  const int GRAN = 1<<9;
  int sito[GRAN];
  vector <int> Prosti;
  int init_ch;

  void init() { //sito
    if (init_ch++)
      return;

    for (int i=2; i<GRAN; i++) {
      if (!sito[i]) {
        Prosti.push_back(i);
        for (int j=2*i; j<GRAN; j+=i)
          sito[j] = 1;
      }
    }
  }

  P ext_euc(ll a, ll b) {
    if (!b)
      return P(1, 0);

    P tmp = ext_euc(b, a % b);
    P ret = P(tmp.Y, tmp.X - (a / b) * tmp.Y);
    return ret;
  }

  P spoji(P a, P b) {
    P koef = ext_euc(a.X, b.X);
    ll val = (ll) a.X * koef.X * b.Y + (ll) b.X * koef.Y * a.Y;
    ll ost = (ll) a.X * b.X;
    val = ((val % ost) + ost) % ost;

    return P(ost, val);
  }

  vector <ll> rastav(ll x) { //vraca potencije prostih
    vector <ll> R;

    for (auto it : Prosti) {
      if (!(x % it)) {
        ll tmp = 1;
        for (; !(x % it); tmp *= it, x /= it);
        R.push_back(tmp);
      }
    }

    if (x)
      R.push_back(x);

    return R;
  }

  P vrati(vector <P> V) { //vraca mod, ost
    init();
    vector <P> T;

    for (auto it : V) {
      vector <ll> R = rastav(it.X);
      for (auto it2 : R)
        T.push_back(P(it2, it.Y % it2));
    }

    sort(T.begin(), T.end(), greater<P>());
    if (T.empty())
      return P(1, 0);

    P ret = T[0];
    for (int i=1; i<(int) T.size(); i++) {
      int da = 1;
      for (int j=0; j<i; j++)
        if (!(T[j].X % T[i].X))
          da = 0;

      if (da)
        ret = spoji(ret, T[i]);
    }

    for (auto it : V)
      if (ret.Y % it.X != it.Y)
        return P(ret.X, -1);

    return ret;
  }
}

int brred, brstup;

ll daj(int x, int y)
{
  ll ret = 1e18;
  for (int i=0; i<2; i++) {
    int o1 = i ? x : 2*brred - x;
    for (int j=0; j<2; j++) {
      int o2 = j ? y : 2*brstup - y;
      P tmp = crt::vrati(vector<P>{P(2*brred, o1), P(2*brstup, o2)});
      if (tmp.Y != -1)
        ret = min(ret, tmp.Y);
    }
  }

  return ret;
}

int main()
{
  int q;

  scanf("%d%d%d", &brred, &brstup, &q);

  ll mrtav = crt::vrati(vector<P>{P(2*brred, 0), P(2*brstup, 0)}).X;
  mrtav = min(mrtav, daj(0, brstup));
  mrtav = min(mrtav, daj(brred, brstup));
  mrtav = min(mrtav, daj(brred, 0));

  for (; q--; ) {
    int x, y;
    scanf("%d%d", &x, &y);

    ll tmp = daj(x, y);
    printf("%lld\n", tmp < mrtav ? tmp : -1);
  }

  return 0;
}