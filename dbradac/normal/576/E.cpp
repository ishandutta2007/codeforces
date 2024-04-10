#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int TOUR = 1<<19, MAXK = 55;

struct edge {
  int a, b, col;
};

struct strq {
  int inde, col, indr;
};

vector <edge> V[2*TOUR];
vector <int> Vr[TOUR];
int root[MAXK][TOUR], urank[MAXK][TOUR], par[MAXK][TOUR];
int ea[TOUR], eb[TOUR];
vector <P> Prom[TOUR]; //vrijeme, boja
int nakojem[TOUR];
int qind[TOUR], qcol[TOUR];
int tcol[TOUR];
int n, m, k, q;

P Find(int a, int col)
{
  if (root[col][a] == -1)
    return P(a, 0);
  P tmp = Find(root[col][a], col);
  return P(tmp.X, tmp.Y ^ par[col][a]);
}

P Union(int a, int b, int col)
{
  P pa = Find(a, col);
  P pb = Find(b, col);

  if (pa.X != pb.X) {
    if (urank[col][pa.X] < urank[col][pb.X]) {
      root[col][pa.X] = pb.X;
      par[col][pa.X] = pa.Y ^ pb.Y ^ 1;
      return P(pa.X, col);
    }
    else if (urank[col][pa.X] > urank[col][pb.X]) {
      root[col][pb.X] = pa.X;
      par[col][pb.X] = pa.Y ^ pb.Y ^ 1;
      return P(pb.X, col);
    }
    else {
      urank[col][pa.X]++;
      root[col][pb.X] = pa.X;
      par[col][pb.X] = pa.Y ^ pb.Y ^ 1;
      return P(pb.X, -col);
    }
  }

  return P(-1, -1);
}

void VratiUnion(int x, int col)
{
  int st = 0;
  if (col < 0) {
    st = 1;
    col = -col;
  }

  if (x != -1) {
    if (st)
      urank[col][root[col][x]]--;
    root[col][x] = -1;
    par[col][x] = 0;
  }
}

void Stavi(int pos, int lo, int hi, int begin, int end, edge val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    V[pos].push_back(val);
    return;
  }

  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
}

void Dfs(int pos)
{
  vector <P> Vrati;

  if (pos >= TOUR + q)
    return;

  for (int i=0; i<(int) V[pos].size(); i++)
    Vrati.push_back(Union(V[pos][i].a, V[pos][i].b, V[pos][i].col));
  
  if (pos >= TOUR) {
    int ti = pos - TOUR;
    int qi = qind[ti];
    int a = ea[qi];
    int b = eb[qi];
    int col = qcol[ti];
    int sljt = Vr[qi][++nakojem[qi]];

    P pa = Find(a, col);
    P pb = Find(b, col);

    if (pa == pb) {
      printf("NO\n");
      Stavi(1, 0, TOUR, ti + 1, sljt, edge { a, b, tcol[qi] });
    }
    else {
      printf("YES\n");
      Stavi(1, 0, TOUR, ti + 1, sljt, edge { a, b, col });
      tcol[qi] = col;
    }
  }
  else {
    Dfs(2*pos+0);
    Dfs(2*pos+1);
  }

  for (int i=(int) Vrati.size()-1; i>=0; i--)
    VratiUnion(Vrati[i].X, Vrati[i].Y);
}

int main()
{
  memset(root, -1, sizeof root);

  scanf("%d%d%d%d", &n, &m, &k, &q);

  for (int i=0; i<m; i++)
    scanf("%d%d", &ea[i], &eb[i]);

  for (int i=0; i<q; i++) {
    scanf("%d%d", &qind[i], &qcol[i]); qind[i]--;
    Vr[qind[i]].push_back(i);
  }

  for (int i=0; i<TOUR; i++)
    Vr[i].push_back(TOUR);

  Dfs(1);

  return 0;
}