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

pair<P, int> p[MAX];

ll Ccw(P a, P b, P c)
{
  return (ll) a.X * (b.Y - c.Y) + (ll) b.X * (c.Y - a.Y) + (ll) c.X * (a.Y - b.Y);
}

inline ll Sq(int x)
{
  return (ll) x * x;
}

ll Dist(P a, P b)
{
  return Sq(a.X - b.X) + Sq(a.Y - b.Y);
}

bool ManjiKut(pair<P, int> a, pair<P, int> b)
{
  if (Ccw(p[0].X, a.X, b.X))
    return Ccw(p[0].X, a.X, b.X) < 0;
  return Dist(p[0].X, a.X) < Dist(p[0].X, b.X);
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &p[i].X.X, &p[i].X.Y);
    p[i].Y = i + 1;
  }

  sort(p, p + n);
  sort(p + 1, p + n, ManjiKut);

  for (int i=2; i<n; i++) {
    if (Ccw(p[0].X, p[1].X, p[i].X)) {
      printf("%d %d %d\n", p[0].Y, p[1].Y, p[i].Y);
      break;
    }
  }

  return 0;
}