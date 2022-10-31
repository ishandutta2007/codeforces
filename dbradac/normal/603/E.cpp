#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 300100;

struct edge {
  int a, b, t, cost;
} p[MAX], povr[MAX];

bool operator < (const edge &a, const edge &b)
{
  return a.cost < b.cost;
}

bool Manji(const edge &a, const edge &b)
{
  return a.t < b.t;
}

struct union_find {
  int urank[MAX], uroot[MAX], sz[MAX];
  int brnep;
  stack <P> S;

  union_find() {
    memset(uroot, -1, sizeof uroot);
    for (int i=0; i<MAX; i++)
      sz[i] = 1;
  }

  int ufind(int x) {
    if (uroot[x] == -1)
      return x;
    return ufind(uroot[x]);
  }

  int spoji(int ind) {
    int a = ufind(p[ind].a);
    int b = ufind(p[ind].b);

    if (a == b)
      return 0;

    brnep -= (sz[a] & 1) + (sz[b] & 1);
    if (urank[a] > urank[b]) {
      sz[a] += sz[b];
      uroot[b] = a;
      S.push(P(b, 0));
    }
    else if (urank[b] > urank[a]) {
      sz[b] += sz[a];
      uroot[a] = b;
      S.push(P(a, 0));
    }
    else {
      urank[a]++;
      sz[a] += sz[b];
      uroot[b] = a;
      S.push(P(b, 1));
    }

    brnep += max(sz[a], sz[b]) & 1;

    return 1;
  }

  void odspoji() {
    assert(!S.empty());
    P tmp = S.top();
    S.pop();

    brnep -= (sz[uroot[tmp.X]] & 1);
    sz[uroot[tmp.X]] -= sz[tmp.X];
    brnep += (sz[uroot[tmp.X]] & 1) + (sz[tmp.X] & 1);

    urank[uroot[tmp.X]] -= tmp.Y;    
    uroot[tmp.X] = -1;
  }
} Uf;

int brnode, bredge;
int rje[MAX];
int cijene[MAX];

void Rijesi(int lo, int hi, int from, int to)
{
  if (lo > hi)
    return;

  int mid = (lo + hi) / 2;
  int stavio=0;

  if (!Uf.brnep)
    rje[mid] = from;
  else {
    vector <edge> V;
    for (int i=lo; i<=mid; i++)
      if (povr[i].cost <= to)
        V.push_back(povr[i]);

    for (int i=from; i<=to; i++)
      if (p[i].t <= mid)
        V.push_back(p[i]);

    sort(V.begin(), V.end());
    for (int i=0; i<(int) V.size(); i++) {
      stavio += Uf.spoji(V[i].cost);
      if (!Uf.brnep) {
        rje[mid] = V[i].cost;
        break;
      }
    }
  }

  for (; stavio; stavio--)
    Uf.odspoji();

  for (int i=from; i<rje[mid]; i++)
    if (p[i].t < lo)
      stavio += Uf.spoji(i);
  
  if (rje[mid] != -1)
    Rijesi(lo, mid - 1, rje[mid], to);

  for (; stavio; stavio--)
    Uf.odspoji();

  for (int i=lo; i<=mid; i++)
    if (povr[i].cost < from)
      stavio += Uf.spoji(povr[i].cost);

  int kraj = to;
  if (rje[mid] != -1)
    kraj = rje[mid];
  Rijesi(mid + 1, hi, from, kraj);

  for (; stavio; stavio--)
    Uf.odspoji();
}

int main()
{
  scanf("%d%d", &brnode, &bredge);
  Uf.brnep = brnode;

  for (int i=0; i<bredge; i++) {
    scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].cost);
    p[i].a--; p[i].b--;
    p[i].t = i;
  }

  sort(p, p + bredge);
  for (int i=0; i<bredge; i++) {
    cijene[i] = p[i].cost;
    p[i].cost = i;
    povr[i] = p[i];
  }

  sort(povr, povr + bredge, Manji);
  memset(rje, -1, sizeof rje);
  Rijesi(0, bredge - 1, 0, bredge - 1);

  for (int i=0; i<bredge; i++) {
    if (rje[i] == -1)
      printf("-1\n");
    else
      printf("%d\n", cijene[rje[i]]);
  }

  return 0;
}