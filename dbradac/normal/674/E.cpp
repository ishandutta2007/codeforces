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
typedef double llf;
#define X first
#define Y second

const int MAX = 1<<19, MAXDUB = 40;
const llf GRAN = 1 - (1e-9);

int vr=1;
int par[MAX];
P q[MAX];
llf umn[MAX][MAXDUB];

void Makni(int ja, int ch, int indd)
{
  umn[ja][indd] /= (0.5 * umn[ch][indd-1] + 0.5);
}

void Stavi(int ja, int ch, int indd)
{
  umn[ja][indd] *= (0.5 * umn[ch][indd-1] + 0.5);
}

void Dodaj(int node)
{
  int tmp = node;
  vector <int> V;

  for (int i=0; i<MAXDUB && node; i++, node=par[node])
    V.push_back(node);
  V.push_back(par[node]);

  for (int i=(int) V.size()-1; i>0; i--)
    Makni(V[i], V[i-1], i);

  umn[tmp][0] = 0;

  for (int i=0; i<(int) V.size()-1; i++)
    Stavi(V[i+1], V[i], i+1);
}

int main()
{
  int brq;
  int ind = 1;

  scanf("%d", &brq);

  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAXDUB; j++)
      umn[i][j] = 1;

  umn[0][0] = 0;
  for (int i=0; i<brq; i++) {
    scanf("%d%d", &q[i].X, &q[i].Y); q[i].Y--;
    if (q[i].X == 1) {
      par[ind] = q[i].Y;
      Dodaj(ind++);
    }
    else {
      llf ret = 0;
      for (int j=1; j<MAXDUB; j++)
        ret += 1 - umn[q[i].Y][j];

      printf("%.10lf\n", (double) ret);
    }
  }

  return 0;
}