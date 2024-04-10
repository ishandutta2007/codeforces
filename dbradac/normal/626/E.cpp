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

bool Veci(P a, P b)
{
  if (a.X < 0 && b.X >= 0)
    return false;
  if (a.X >= 0 && b.X < 0)
    return true;

  return a.X * b.Y > b.X * a.Y;
}

int p[MAX];
ll pref[MAX];
int n;

P Eval(int sred, int kol)
{
  return P(pref[n] - pref[n-kol] + pref[sred] - pref[sred-kol-1] - ((ll) 2 * kol + 1) * p[sred], 2 * kol + 1);
}

int sred=1, kol=0;

int main()
{
  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  sort(p + 1, p + n + 1);
  for (int i=1; i<=n; i++)
    pref[i] = pref[i-1] + p[i];

  P rje = P(0, 1);

  for (int i=1; i<=n; i++) {
    int lo = 0, hi = min(i - 1, n - i);

    for (; lo < hi; ) {
      int mid = (lo + hi) / 2;
      
      if (Veci(Eval(i, mid), Eval(i, mid + 1)))
        hi = mid;
      else
        lo = mid + 1;
    }

    if (Veci(Eval(i, lo), rje)) {
      rje = Eval(i, lo);
      sred = i;
      kol = lo;
    }
  }

  printf("%d\n", 2 * kol + 1);
  for (int i=sred-kol; i<=sred; i++)
    printf("%d ", p[i]);
  for (int i=n-kol+1; i<=n; i++)
    printf("%d ", p[i]);
  printf("\n");

//  printf("%.5lf\n", (double) rje.X / rje.Y);

  return 0;
}