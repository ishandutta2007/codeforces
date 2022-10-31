#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int a, b;

ll Gauss(int x)
{
  return (((ll) x * (x + 1)) / 2) * b;
}

int Moze(int l, int r, int t, int m)
{
  ll kraj = a + ((ll) r - 1) * b;

  if (kraj > t || (ll) t * m < ((ll) r - l + 1) * a + Gauss(r - 1) - Gauss(l - 2))
    return 0;
  return 1;
}

int main()
{
  int n;
  scanf("%d%d%d", &a, &b, &n);

  for (int i=0; i<n; i++) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);

    int lo = l - 1, hi = t + 1;
    
    for (; lo < hi; ) {
      int mid = (lo + hi + 1) / 2;
      if (Moze(l, mid, t, m))
        lo = mid;
      else
        hi = mid - 1;
    }

    if (lo < l)
      printf("-1\n");
    else
      printf("%d\n", lo);
  }

  return 0;
}