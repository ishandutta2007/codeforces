#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18, VELB = 1<<16, KAND = (1<<16) - 1;

int kap;
vector <P> E;
P rje[MAX];
vector <P> V[2][VELB];

void Sortiraj()
{
  for (int i=0; i<(int) E.size(); i++)
    V[0][E[i].X & KAND].push_back(E[i]);

  for (int i=0; i<VELB; i++)
    for (int j=0; j<(int) V[0][i].size(); j++)
      V[1][V[0][i][j].X >> 16].push_back(V[0][i][j]);

  E.clear();

  for (int i=0; i<VELB; i++)
    for (int j=0; j<(int) V[1][i].size(); j++)
      E.push_back(V[1][i][j]);

  reverse(E.begin(), E.end());
}

P MaxPop(P pop, int sum)
{
  if (pop.X >= sum)
    return P(sum, 0);
  if (pop.X + pop.Y >= sum)
    return P(pop.X, sum - pop.X);
  return pop;
}

void Spoji(int tip, int udalj, P treb, P prom, P &ntreb, P &nprom)
{
  if (udalj > kap || treb == P(-1, -1)) {
    ntreb = P(-1, -1);
    return;
  }
  
  if (tip == 1) {
    ntreb = P(treb.X + udalj, treb.Y);
    nprom = MaxPop(P(prom.X + udalj, prom.Y), kap);
  }
  else if (tip == 2) {
    int ost = kap - udalj;
    int popX = min(ost, prom.X);
    ntreb = P(treb.X - popX, treb.Y + udalj + popX);
    nprom = MaxPop(P(0, prom.Y + udalj + popX), kap);
  }
  else {
    int ost = kap - udalj;
    int popX = min(ost, prom.X);
    int popY = min(ost - popX, prom.Y);
    ntreb = P(treb.X - popX, treb.Y - popY);
    nprom = P(0, 0);
  }
}

int main()
{
  int kraj, n, q, zadx;
  P treb = P(0, 0), prom = P(0, 0);

  scanf("%d%d%d%d", &kraj, &kap, &n, &q); kraj += (int) (1e9); zadx = kraj;
  
  for (int i=0; i<n; i++) {
    int tip, x;
    scanf("%d%d", &tip, &x); x += (int) (1e9);
    if (x < kraj)
      E.push_back(P(x, tip));
  }

  for (int i=0; i<q; i++) {
    int x;
    scanf("%d", &x); x += (int) (1e9);
    E.push_back(P(x, -i));
  }
  
  Sortiraj();

  for (int i=0; i<(int) E.size(); i++) {
    int udalj = zadx - E[i].X;

    int tip = E[i].Y;
    if (E[i].Y <= 0)
      tip = 3;

    P ntreb, nprom;
    Spoji(tip, udalj, treb, prom, ntreb, nprom);
    
    if (E[i].Y <= 0)
      rje[-E[i].Y] = ntreb;
    else {
      zadx = E[i].X;
      treb = ntreb;
      prom = nprom;
    }
  }

  for (int i=0; i<q; i++)
    printf("%d %d\n", rje[i].X, rje[i].Y);

  return 0;
}