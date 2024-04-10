#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int BUCSZ = 318, BRBUC = 318, MAX = 100100;
const ll INF = 1e18;

struct strh {
  P toc;
  ll poz;
};

ll Ccw(P a, P b, P c)
{
  return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}

struct bucket {
  int brprije;
  ll suf;
  int poi;
  vector <strh> H;
  vector <P> Sorted;
} buc[BRBUC];

int n;
int p[MAX], uzet[MAX];

vector <strh> MakeHull(const vector <strh> &V)
{
  vector <strh> R;

  for (int i=0; i<(int) V.size(); i++) {
    for (; R.size() > 1; ) {
      if (Ccw(R[R.size()-2].toc, R.back().toc, V[i].toc) >= 0)
        R.pop_back();
      else
        break;
    }

    R.push_back(V[i]);
  }

  return R;
}

void PostBuc(int ind)
{
  int poc = ind * BUCSZ, kraj = min(n - 1, (ind + 1) * BUCSZ - 1);
  ll sufb[BUCSZ + 5], prefb[BUCSZ + 5];
  
  memset(sufb, 0, sizeof sufb);
  memset(prefb, 0, sizeof prefb);

  for (int i=poc; i<=kraj; i++) {
    prefb[i-poc] = uzet[i];
    if (i > poc)
      prefb[i-poc] += prefb[i-poc-1];
  }

  for (int i=kraj; i>=poc; i--) {
    if (uzet[i])
      sufb[i-poc] = p[i];
    sufb[i-poc] += sufb[i-poc+1];
  }

  vector <strh> H;

  for (int i=0; i<(int) buc[ind].Sorted.size(); i++) {
    P tmp = buc[ind].Sorted[i];
    if (!uzet[tmp.Y])
      H.push_back(strh {P(tmp.X, tmp.X * prefb[tmp.Y-poc] + sufb[tmp.Y-poc]), tmp.Y} );
  }

  buc[ind].H = MakeHull(H);
  buc[ind].poi = 0;
}

void InitBuc(int ind)
{
  int poc = ind * BUCSZ, kraj = min(n - 1, (ind + 1) * BUCSZ - 1);

  for (int i=poc; i<=kraj; i++)
    buc[ind].Sorted.push_back(P(p[i], i));

  sort(buc[ind].Sorted.begin(), buc[ind].Sorted.end());
  PostBuc(ind);
}

ll Eval(int indb, strh tmp)
{
  return tmp.toc.X * (buc[indb].brprije  + 1) + tmp.toc.Y + buc[indb].suf;
}

P MaxBuc(int ind)
{
  if (buc[ind].H.empty())
    return P(-INF, 0);

  for (; buc[ind].poi+1<(int) buc[ind].H.size(); buc[ind].poi++)
    if (Eval(ind, buc[ind].H[buc[ind].poi]) > Eval(ind, buc[ind].H[buc[ind].poi + 1]))
      break;
    
  return P(Eval(ind, buc[ind].H[buc[ind].poi]), buc[ind].H[buc[ind].poi].poz);
}

void Makni(int poz)
{
  uzet[poz] = 1;
  int indb = poz / BUCSZ;

  for (int i=0; i<indb; i++)
    buc[i].suf += p[poz];

  for (int i=indb+1; i<BRBUC; i++)
    buc[i].brprije++;

  PostBuc(indb);
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<BRBUC; i++)
    InitBuc(i);

  ll tmp = 0, rje = 0;
  for (int i=0; i<n; i++) {
    P best = MaxBuc(0);
    for (int j=1; j<BRBUC; j++)
      best = max(best, MaxBuc(j));
  
    tmp += best.X;
    rje = max(rje, tmp);

    Makni((int) best.Y);
  }

  printf("%lld\n", rje);

  return 0;
}