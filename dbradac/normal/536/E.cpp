#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200100, TOUR = 1<<18;;

struct tour {
  int val, sz, poc, kraj;
} t[2*TOUR];

int polje[MAX];
int subtree[MAX], hlroot[MAX], poz[MAX], par[MAX], wpar[MAX], dub[MAX];
int vr=0;
P edge[MAX];
P q[MAX];
int qa[MAX], qb[MAX], rje[MAX];
vector <P> V[MAX];

tour Merge(tour a, tour b)
{
  tour ret = { a.val + b.val, a.sz + b.sz, a.poc, b.kraj };
  if (a.poc == a.sz)
    ret.poc += b.poc;
  if (b.kraj == b.sz)
    ret.kraj += a.kraj;

  if (a.poc < a.sz && b.kraj < b.sz)
    ret.val += polje[a.kraj + b.poc];

  return ret;
}

void InitTour()
{
  for (int i=2*TOUR-1; i; i--) {
    if (i >= TOUR)
      t[i] = { 0, 1, 0, 0 };
    else
      t[i] = Merge(t[2*i], t[2*i+1]);
  }
}

void Stavi(int pos)
{
  t[pos + TOUR] = { 0, 1, 1, 1 };

  for (pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = Merge(t[2*pos], t[2*pos+1]);
}

tour Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return { 0, 0, 0, 0 };
  if (lo >= begin && hi <= end)
    return t[pos];

  return Merge(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
               Vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int Rek1(int node, int prosli)
{
  int ret = 1;

  for (int i=0; i<(int) V[node].size(); i++)
    if (V[node][i].X != prosli)
      ret += Rek1(V[node][i].X, node);

  return subtree[node] = ret;
}

void Rek2(int node, int prosli, int kor)
{
  if (kor == -1)
    kor = node;

  if (prosli != -1)
    dub[node] = dub[prosli] + 1;
  par[node] = prosli;
  poz[node] = vr++;
  hlroot[node] = kor;

  int maxx = -1, ind = -1;
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i].X;
    if (nn != prosli && subtree[nn] > maxx) {
      maxx = subtree[nn];
      ind = nn;
    }
    if (nn == prosli)
      wpar[node] = V[node][i].Y;
  }

  if (ind != -1)
    Rek2(ind, node, kor);

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i].X;
    if (nn != ind && nn != prosli)
      Rek2(nn, node, -1);
  }
}

void HLD()
{
  Rek1(0, -1);
  Rek2(0, -1, -1);
}

int Lca(int a, int b, int gran)
{
  tour ta = { 0, 0, 0, 0 }, tb = { 0, 0, 0, 0 };

  for (;;) {
    if (hlroot[a] == hlroot[b]) {
      if (dub[a] > dub[b]) {
        swap(a, b);
        swap(ta, tb);
      }

      tb = Merge(Vrati(1, 0, TOUR, poz[a] + 1, poz[b] + 1), tb);
      swap(ta.poc, ta.kraj);
      ta = Merge(ta, tb);
      break;
    }

    if (dub[hlroot[a]] > dub[hlroot[b]]) {
      swap(a, b);
      swap(ta, tb);
    }

    tb = Merge(Vrati(1, 0, TOUR, poz[hlroot[b]] + 1, poz[b] + 1), tb);
    if (wpar[hlroot[b]] >= gran)
      tb = Merge( { 0, 1, 1, 1 }, tb);
    else
      tb = Merge( { 0, 1, 0, 0 }, tb);

    b = par[hlroot[b]];
  }

  int ret = ta.val;
  ret += polje[ta.poc];
  if (ta.poc != ta.sz)
    ret += polje[ta.kraj];

  return ret;
}

int main()
{
  int n, brq;

  scanf("%d%d", &n, &brq);

  for (int i=1; i<n; i++)
    scanf("%d", &polje[i]);

  for (int i=0; i<n-1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  HLD();

  for (int i=0; i<brq; i++) {
    int l;
    scanf("%d%d%d", &qa[i], &qb[i], &l); qa[i]--; qb[i]--;
    q[i] = P(l, i);
  }

  for (int i=1; i<n; i++)
    edge[i-1] = P(wpar[i], i);

  sort(q, q + brq, greater<P>());
  sort(edge, edge + n - 1, greater<P>());

  InitTour();

  for (int i=0, j=0; i<brq; i++) {
    for (; j<n-1 && edge[j].X >= q[i].X; j++)
      Stavi(poz[edge[j].Y]);

    rje[q[i].Y] = Lca(qa[q[i].Y], qb[q[i].Y], q[i].X);
  }

  for (int i=0; i<brq; i++)
    printf("%d\n", rje[i]);

  return 0;
}