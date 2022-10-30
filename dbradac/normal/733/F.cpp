#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<18, LOG = 20;
const ll INF = 1e18;

struct edge {
  int a, b, ind;
  ll cij, pobolj;
} ee[MAX];

struct eee {
  int node, ind;
  ll cij, pobolj;
};

int root[MAX];

int find(int x)
{
  if (root[x] == -1)
    return x;
  return root[x] = find(root[x]);
}

void merge(int a, int b)
{
  a = find(a); b = find(b);
  assert(a != b);

  if (rand() & 1)
    root[a] = b;
  else
    root[b] = a;
}

int n, m;
vector <edge> Mst;
ll summst = 0;
ll budz;
vector <eee> V[MAX];

int dub[MAX];
P lca[MAX][LOG]; //val, ind
int parlca[MAX][LOG];

void mst()
{
  vector <edge> E;
  memset(root, -1, sizeof root);

  REP(i, m)
    E.push_back(ee[i]);

  sort(E.begin(), E.end(), 
      [] (const edge &a, const edge &b) { return a.cij < b.cij; });

  REP(i, m) {
    int a = find(E[i].a);
    int b = find(E[i].b);

    if (a != b) {
      merge(a, b);
      summst += E[i].cij;
      Mst.push_back(E[i]);
    }
  }
}

void dfs(int node, int prosli, P pe)
{
  dub[node] = dub[prosli] + 1;

  lca[node][0] = pe;
  parlca[node][0] = prosli;

  FOR(i, 1, LOG) {
    parlca[node][i] = parlca[parlca[node][i-1]][i-1];
    lca[node][i] = max(lca[node][i-1], lca[parlca[node][i-1]][i-1]);
  }

  for (auto it : V[node])
    if (it.node != prosli)
      dfs(it.node, node, P(it.cij, it.ind));
}

void gen_lca()
{
  for (auto it : Mst) {
    V[it.a].push_back(eee {it.b, it.ind, it.cij, it.pobolj});
    V[it.b].push_back(eee {it.a, it.ind, it.cij, it.pobolj});
  }

  memset(lca, -1, sizeof lca);
  dfs(0, 0, P(0, 0));
}

P query(int a, int b)
{
  P ret(0, 0);

  if (dub[a] > dub[b])
    swap(a, b);

  int raz = dub[b] - dub[a];

  for (int i=0; raz; raz /= 2, i++) {
    if (raz & 1) {
      ret = max(ret, lca[b][i]);
      b = parlca[b][i];
    }
  }

  if (a == b)
    return ret;

  for (int i=LOG-1; i>=0; i--) {
    if (parlca[a][i] != parlca[b][i]) {
      ret = max(ret, lca[a][i]);
      ret = max(ret, lca[b][i]);
      a = parlca[a][i];
      b = parlca[b][i];
    }
  }

  ret = max(ret, lca[a][0]);
  ret = max(ret, lca[b][0]);

  return ret;
}

int main()
{
  scanf("%d%d", &n, &m);

  REP(i, m)
    scanf("%lld", &ee[i].cij);

  REP(i, m)
    scanf("%lld", &ee[i].pobolj);

  REP(i, m) {
    scanf("%d%d", &ee[i].a, &ee[i].b); ee[i].a--; ee[i].b--;
    ee[i].ind = i;
  }

  scanf("%lld", &budz);

  mst();
  gen_lca();

  ll rje = INF;
  P mmtmp;
  int mmind = -1;

  REP(i, m) {
    P tmp = query((int) ee[i].a, (int) ee[i].b);
    ll nval = summst - tmp.X + ee[i].cij;
    nval -= budz / ee[i].pobolj;
      
    if (nval < rje) {
      rje = nval;
      mmtmp = tmp;
      mmind = i;
    }
  }

  printf("%lld\n", rje);
  
  for (auto it : Mst)
    if (it.ind != mmtmp.Y)
      printf("%d %lld\n", 1 + it.ind, it.cij);

  printf("%d %lld\n", 1 + mmind, ee[mmind].cij - budz / ee[mmind].pobolj);

  return 0;
}