#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long double llf;
typedef long long ll;
typedef pair<int,int> P;
#define X first
#define Y second

const int MAX = 1<<17, MIL = 1<<21;

int n;
P p[MAX];
int br[MIL];

int Norm(int x)
{
  return (x + n) % n;
}

ll Ccw(P a, P b, P c)
{
  return (ll) a.X * (b.Y - c.Y) + (ll) b.X * (c.Y - a.Y) + (ll) c.X * (a.Y - b.Y);
}

inline ll SumBr(int x)
{
  return (ll) x * (x + 1) / 2;
}

inline llf SumKvad(int x)
{
  return (llf) x * (x + 1) * (2 * x + 1) / 6;
}

inline ll Sq(ll x)
{
  return x * x;
}

llf Rijesi()
{
  memset(br, 0, sizeof br);

  int najvisa = 0, najniza = 0;
  int lduz = 0, rduz = 0;

  for (int i=1; i<n; i++) {
    if (p[i].Y > p[najvisa].Y) {
      najvisa = i;
      lduz = rduz = najvisa;
    }
    else if (p[i].Y == p[najvisa].Y) {
      if (p[i].X < p[lduz].X)
        lduz = i;
      if (p[i].X > p[rduz].X)
        rduz = i;
    }
    if (p[i].Y < p[najniza].Y)
      najniza = i;  
  }

  int ltoc = 0, rtoc = MIL - 5;
  ll brtoc = 0;

  for (int vis=p[najvisa].Y; vis >= p[najniza].Y; vis--) {
    for (; vis < p[Norm(lduz + 1)].Y; lduz = Norm(lduz + 1));
    for (; vis < p[Norm(rduz - 1)].Y; rduz = Norm(rduz - 1));

    int pr = lduz, dr = Norm(lduz + 1);
    for (; ltoc - 1 >= min(p[pr].X, p[dr].X) && Ccw(p[pr], p[dr], P(ltoc-1, vis)) >= 0; ltoc--);
    for (; ltoc < min(p[pr].X, p[dr].X) || Ccw(p[pr], p[dr], P(ltoc, vis)) < 0; ltoc++);
    
    pr = Norm(rduz - 1), dr = rduz;
    for (; rtoc + 1 <= max(p[pr].X, p[dr].X) && Ccw(p[pr], p[dr], P(rtoc+1, vis)) >= 0; rtoc++);
    for (; rtoc > max(p[pr].X, p[dr].X) || Ccw(p[pr], p[dr], P(rtoc, vis)) < 0; rtoc--);

    br[vis] = max(0, rtoc - ltoc + 1);
    brtoc += br[vis];
  }

  llf koef = (llf) 1 / ((llf) brtoc * (brtoc - 1) / 2);
  llf ret = 0;
  llf sumkvad = 0, sumlin = 0;
  llf broj = 0;

  for (int i=0; i<MIL; i++) {
    ret += koef * br[i] * (Sq(i) * broj +
                           sumkvad - 2 * sumlin * i);

    broj += br[i];
    sumlin += (llf) i * br[i];
    sumkvad += (llf) Sq(i) * br[i];
  }

  return ret;
}

int main() {
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &p[i].X, &p[i].Y);
    p[i].X += MIL / 2;
    p[i].Y += MIL / 2;
  }

  int rev=0;
  for (int i=0; i<n; i++)
    if (Ccw(p[i], p[Norm(i+1)], p[Norm(i+2)]) < 0)
      rev = 1;
  if (rev)
    reverse(p, p + n);

  llf rje = Rijesi();
  for (int i=0; i<n; i++)
    swap(p[i].X, p[i].Y);

  rev=0;
  for (int i=0; i<n; i++)
    if (Ccw(p[i], p[Norm(i+1)], p[Norm(i+2)]) < 0)
      rev = 1;
  if (rev)
    reverse(p, p + n);

  rje += Rijesi();

  printf("%.10lf\n", (double) rje / 2);

  return 0;
}