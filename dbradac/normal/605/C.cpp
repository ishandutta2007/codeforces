#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double llf;
typedef pair<llf, llf> P;
#define X first
#define Y second

const llf EPS = 1e-3;

llf Ccw(P a, P b, P c)
{
  return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}

vector <P> V, H;
P treb;

void MakeHull()
{
  sort(V.begin(), V.end());

  for (int i=0; i<(int) V.size(); i++) {
    for (; (int) H.size(); ) {
      if (H.back().X <= V[i].X && H.back().Y <= V[i].Y)
        H.pop_back();
      else
        break;
    }

    for (; (int) H.size() > 1; ) {
      if (Ccw(H[H.size()-2], H.back(), V[i]) >= -EPS)
        H.pop_back();
      else
        break;
    }

    H.push_back(V[i]);
  }

  H.insert(H.begin(), P(0, H[0].Y));  
  H.push_back(P(H.back().X, 0));
}

P Novi(P tmp, llf koef)
{
  return P(tmp.X * koef, tmp.Y * koef);
}

int Moze(llf koef)
{
  for (int i=0; i<(int) H.size()-1; i++)
    if (Ccw(Novi(H[i], koef), Novi(H[i+1], koef), treb) > 0)
      return 0;

  return 1;
}

int main()
{
  int n, p, q;

  scanf("%d%d%d", &n, &p, &q);
  treb = P(p, q);

  for (int i=0; i<n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    V.push_back(P(a, b));
  }

  MakeHull();

  llf lo = 0, hi = (1e6) + 10;

  for (int i=0; i<100; i++) {
    llf mid = (lo + hi) / 2;
    if (Moze(mid))
      hi = mid;
    else
      lo = mid;
  }

  printf("%.10lf\n", (double) lo);

  return 0;
}