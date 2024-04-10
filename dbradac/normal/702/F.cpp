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

const int MAX = 1<<18;

P p[MAX];
int n, brq;
int poz[MAX];
ll ima[MAX], rje[MAX];
ll fenval[MAX], fenkol[MAX];
P sor[MAX];

void Stavi(ll fen[MAX], ll pos, ll val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

ll Vrati(ll fen[MAX], ll pos)
{
  ll ret = 0;
  for (pos++; pos; pos -= pos & -pos)
    ret += fen[pos];

  return ret;
}

int Binary(int poc, ll sum)
{
  sum += Vrati(fenval, poc - 1);

  int lo = 0, hi = MAX;
  for (; lo + 1 < hi; ) {
    int mid = (lo + hi) / 2;
    if (fenval[mid] <= sum) {
      sum -= fenval[mid];
      lo = mid;
    }
    else
      hi = mid;
  }

  return lo - 1;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%lld%lld", &p[i].X, &p[i].Y);

  sort(p, p + n, [] (const P &a, const P &b) 
      { return P(a.Y, -a.X) > P(b.Y, -b.X); });

  scanf("%d", &brq);
  for (int i=0; i<brq; i++)
    scanf("%lld", &ima[i]);

  for (int i=30; i>=0; i--) {
    ll sum = 0;
    ll pref[MAX];
    ll prije[MAX];
    int manj = (1<<i) / 2;

    for (int j=0; j<n; j++) {
      prije[j] = sum + p[j].X;
      if (p[j].X <= manj)
        sum += p[j].X;
      pref[j] = sum;
    }

    P q[MAX];
    for (int j=0; j<brq; j++)
      q[j] = P(ima[j] + (poz[j] ? pref[poz[j]-1] : 0), j);

    sort(q, q + brq);

    vector <P> E;
    for (int j=0; j<n; j++) {
      if (p[j].X <= manj)
        E.push_back(P(p[j].X, j));
      else if (p[j].X <= 2 * manj)
        E.push_back(P(prije[j], j));
    }

    sort(E.begin(), E.end());

    memset(fenval, 0, sizeof fenval);
    memset(fenkol, 0, sizeof fenkol);

    for (int iq=0, ie=0; iq<brq; iq++) {
      for (; ie < (int) E.size() && E[ie].X <= q[iq].X; ie++) {
        Stavi(fenval, E[ie].Y, p[E[ie].Y].X);
        Stavi(fenkol, E[ie].Y, 1);
      }

      int ind = (int) q[iq].Y;
      if (ima[ind] < manj)
        continue;

      int dokle = Binary(poz[ind], ima[ind]);
      ima[ind] -= Vrati(fenval, dokle) - Vrati(fenval, poz[ind] - 1);
      rje[ind] += Vrati(fenkol, dokle) - Vrati(fenkol, poz[ind] - 1);
      poz[ind] = dokle + 1;
    }
  }

  for (int i=0; i<brq; i++)
    printf("%lld ", rje[i]);
  printf("\n");

  return 0;
}