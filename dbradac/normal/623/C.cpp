#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;
const int INF = 0x3f3f3f3f;

P p[MAX];
P polje[4][MAX];
int miny[MAX], maxy[MAX];
int minx, maxx;
int n;

inline ll Sq(int x)
{
  return (ll) x * x;
}

ll Eval(int mina, int maxa, int minb, int maxb)
{
  ll ret = 0;
  if (minb != INF)
     ret = max(ret, Sq(maxb - minb));
  if (mina != INF)
    ret = max(ret, Sq(maxa - mina));
  if (mina != INF && minb != INF)
    ret = max(ret, max(Sq(mina), Sq(maxa)) + max(Sq(minb), Sq(maxb)));

  return ret;
}

int Moze(ll val)
{
  if (Sq(maxy[1] - miny[1]) <= val || Sq(maxx - minx) <= val)
    return 1;

  int lefminy = INF, lefmaxy = -INF;

  for (int i=1, j=n+1; i<=n; i++) {
    for (; j; j--) {
      int miniy = lefminy, maxiy = lefmaxy;
      if (j != n + 1) {
        miniy = min(miniy, miny[max(j, i+1)]);
        maxiy = max(maxiy, maxy[max(j, i+1)]);      
      }

      if (miniy != INF && (Sq(p[i].X) + max(Sq(miny[j]), Sq(maxy[j])) > val || 
          Sq(miniy - maxiy) > val)) {
        if (j <= n)
          j++;
        break;
      }
    }

    int miniy = lefminy, maxiy = lefmaxy;
    if (j != n + 1) {
      miniy = min(miniy, miny[max(j, i+1)]);
      maxiy = max(maxiy, maxy[max(j, i+1)]);      
    }

    if (Eval(p[i].X, p[j-1].X, miniy, maxiy) <= val)
      return 1;

    lefminy = min(lefminy, p[i].Y);
    lefmaxy = max(lefmaxy, p[i].Y);
  }

  return 0;
}

int main()
{
  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d%d", &p[i].X, &p[i].Y);

  memcpy(polje[0], p, sizeof p);
  sort(polje[0] + 1, polje[0] + n + 1);

  for (int i=1; i<4; i++) {
    for (int j=1; j<=n; j++) {
      polje[i][j] = polje[i-1][j];
      if (i & 1)
        polje[i][j].X = -polje[i][j].X;
      if (i == 2)
        swap(polje[i][j].X, polje[i][j].Y);
    }

    sort(polje[i] + 1, polje[i] + n + 1);
  }

  ll lo = 0, hi = Sq(INF);

  for (; lo<hi; ) {
    ll mid = (lo + hi) / 2;
    int da = 0;
    for (int st=0; st<4; st++) {
      memcpy(p, polje[st], sizeof p);

      miny[n] = maxy[n] = p[n].Y;
      minx = maxx = p[n].X;
      for (int i=n-1; i; i--) {
        miny[i] = min(miny[i+1], p[i].Y);
        maxy[i] = max(maxy[i+1], p[i].Y);
        minx = min(minx, p[i].X);
        maxx = max(maxx, p[i].X);
      }
      miny[0] = miny[1];
      maxy[0] = maxy[1];    

      da |= Moze(mid);
    }

    if (da)
      hi = mid;
    else
      lo = mid + 1;
  }

  printf("%lld\n", lo);

  return 0;
}