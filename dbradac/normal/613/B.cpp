#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

P p[MAX];
ll pref[MAX];
int gorgran, cf, cm;
int n;
ll nov;
int kraj[MAX];

ll Moze(int prvi, ll bud)
{
  if (bud < 0)
    return -1e15;

  if (prvi == n + 1)
    return gorgran;

  int lo = prvi, hi = n;
  for (; lo < hi; ) {
    int mid = (lo + hi) / 2;
    if (bud + pref[n] - pref[mid-1] >= (ll) p[mid].X * (n - mid + 1))
      hi = mid;
    else
      lo = mid + 1;
  }

  ll treba = (ll) (n - lo + 1) * p[lo].X - (pref[n] - pref[lo-1]);
  return min((ll) gorgran, ((ll) p[lo].X + ((bud - treba) / (n - lo + 1))));
}

void Ispis(int prvi, int minn)
{
  for (int i=1; i<prvi; i++)
    kraj[p[i].Y] = gorgran;

  for (int i=prvi; i<=n; i++)
    kraj[p[i].Y] = max(p[i].X, minn);

  for (int i=1; i<=n; i++)
    printf("%d ", kraj[i]);
  printf("\n");
}

int main()
{
  scanf("%d%d%d%d%lld", &n, &gorgran, &cf, &cm, &nov);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i].X); p[i].Y = i;
  }
  
  sort(p + 1, p + n + 1, greater<P>());
  for (int i=1; i<=n; i++)
    pref[i] = pref[i-1] + p[i].X;

  ll tros = 0;
  ll rje = 0;

  for (int i=0; i<=n; i++) {
    if (tros > nov)
      break;
    rje = max(rje, (ll) i * cf + (ll) cm * Moze(i+1, nov - tros));
    tros += gorgran - p[i+1].X;
  }

  printf("%lld\n", rje);

  tros = 0;
  for (int i=0; i<=n; i++) {
    if (tros > nov)
      break;
    ll tmp = (ll) i * cf + (ll) cm * Moze(i+1, nov - tros);
    if (tmp == rje) {
      Ispis(i + 1, (int) Moze(i + 1, nov - tros));
      break;
    }
    tros += gorgran - p[i+1].X;
  }

  return 0;
}