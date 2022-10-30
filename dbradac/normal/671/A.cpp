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
typedef double lf;
#define X first
#define Y second

const int MAX = 1<<17;

inline ll Sq(int x)
{
  return (ll) x * x;
}

lf Dist(P a, P b)
{
  ll tmp = Sq(a.X - b.X) + Sq(a.Y - b.Y);
  return sqrt((lf) tmp);
}

P cov[2];
P bn;
P toc[MAX];
int n;

vector<pair<lf, int> > Naj(int ind)
{
  vector <pair<lf, int> > V;

  for (int i=0; i<n; i++) {
    lf tmp = Dist(cov[ind], toc[i]) - Dist(bn, toc[i]);
    V.push_back(make_pair(tmp, i));
  }

  sort(V.begin(), V.end());

  return V;
}

lf R1(int ind)
{
  auto V = Naj(ind);
  
  lf ret = V[0].X;
  for (int i=0; i<n; i++)
    ret += 2 * Dist(bn, toc[i]);

  return ret;
}

lf Rijes()
{
  auto V0 = Naj(0);
  auto V1 = Naj(1);
  lf rje = 1e50;

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      if (V0[i].Y == V1[j].Y)
        continue;

      lf sum = V0[i].X + V1[j].X;
      for (int k=0; k<n; k++)
        sum += 2 * Dist(bn, toc[k]);

      rje = min(rje, sum);
    }
  }

  return rje;
}

int main()
{
  scanf("%d%d%d%d%d%d", &cov[0].X, &cov[0].Y, &cov[1].X, &cov[1].Y, &bn.X, &bn.Y);
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d%d", &toc[i].X, &toc[i].Y);

  lf rje = min(R1(0), R1(1));
  if (n > 1)
    rje = min(rje, Rijes());
  printf("%.10lf\n", rje);

  return 0;
}