#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long double llf;
typedef pair<int, int> P;
#define X first
#define Y second

const llf PI = 3.14159265358979323846264338327950288419716939937510, EPS = 1e-9;
const int MAX = 1<<17;

struct prav {
  llf a, b, c;
};

P sred;

llf Sq(llf x)
{
  return x * x;
}

llf Dist(P a, P b)
{
  return sqrt(Sq(a.X - b.X) + Sq(a.Y - b.Y));
}

llf DistPrav(prav p, P toc)
{
  return abs(p.a * toc.X + p.b * toc.Y + p.c) / sqrt((Sq(p.a) + Sq(p.b)));
}

prav Pravac(P a, P b)
{
  return prav { (llf) b.Y - a.Y, (llf) a.X - b.X, (llf) b.X * a.Y - (llf) a.X * b.Y };
}

P tocke[MAX];

int main()
{
  int n;

  scanf("%d%d%d", &n, &sred.X, &sred.Y);

  for (int i=0; i<n; i++)
    scanf("%d%d", &tocke[i].X, &tocke[i].Y);

  llf minn = 1e15, maxx = -1e15;
  for (int i=0; i<n; i++) {
    llf dd = Dist(sred, tocke[i]);
    minn = min(minn, dd);
    maxx = max(maxx, dd);

    int slj = (i + 1) % n;
    if (Sq(Dist(tocke[i], tocke[slj])) + Sq(Dist(tocke[i], sred)) + EPS > Sq(Dist(tocke[slj], sred)) &&
        Sq(Dist(tocke[i], tocke[slj])) + Sq(Dist(tocke[slj], sred)) + EPS > Sq(Dist(tocke[i], sred))) {

      minn = min(minn, DistPrav(Pravac(tocke[i], tocke[slj]), sred));
    }
  }

  printf("%.15lf\n", (double) ((Sq(maxx) - Sq(minn)) * PI));

  return 0;
}