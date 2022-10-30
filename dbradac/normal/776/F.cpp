#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;


vector <int> Dij[MAX];
map <P, int> ind_edge;
vector <int> Komp[MAX];
int dij_a[MAX], dij_b[MAX];

void dfs(int poc, int node, int prosli, int indk)
{
  auto it = lower_bound(Dij[node].begin(), Dij[node].end(), prosli);
  if (it == Dij[node].begin()) {
    it = Dij[node].end(); it--;
  }
  else it--;

  if (node == poc && !Komp[indk].empty()) return;

  Komp[indk].push_back(node);
  ind_edge[P(node, *it)] = indk;
  dfs(poc, *it, node, indk);
}

vector <int> E[MAX];
int n, m;

void dodaj(int a, int b)
{
  E[a].push_back(b);
  E[b].push_back(a);
}

void gen_stablo()
{
  int kolk = 0;

  REP(i, n) {
    for (auto it : Dij[i]) {
      if (ind_edge.find(P(i, it)) == ind_edge.end()) {
	Komp[kolk].push_back(i);
	ind_edge[P(i, it)] = kolk;
	dfs(i, it, i, kolk++);
      }
    }
  }
 
  assert(kolk == 1 + m);
  
  REP(i, m) {
    //    TRACE(dij_a[i] _ dij_b[i]);
    assert(ind_edge.find(P(dij_a[i], dij_b[i])) != ind_edge.end());
    assert(ind_edge.find(P(dij_b[i], dij_a[i])) != ind_edge.end());
    
    dodaj(ind_edge[P(dij_a[i], dij_b[i])], ind_edge[P(dij_b[i], dij_a[i])]);
    //    V[ind_edge[P(dij_a[i], dij_b[i])]].push_back(
  }
}

const int MAXN = 1<<17;

bool bio[MAXN];
int parent[MAXN], d[MAXN];
int sz[MAXN], bal[MAXN];
vector<int> v;
vector <P> D[MAXN];
vector <int> V[MAXN];

int color[MAXN];

void dfs(int x, int dad) {
  sz[x] = 1;
  bal[x] = 0;
  v.push_back(x);
  for (int y: E[x])
    if (y != dad && !bio[y]) {
      d[y] = d[x] + 1;
      dfs(y, x);
      bal[x] = max(bal[x], sz[y]);
      sz[x] += sz[y];
    }
}

int decompose(int x) {
  v.clear();
  dfs(x, -1);

  int m = -1;
  for (int x: v) {
    bal[x] = max(bal[x], (int)v.size()-sz[x]);
    if (m == -1 || bal[x] < bal[m]) m = x;
  }
  x = m;

  v.clear();
  d[x] = 0;
  dfs(x, -1);
  for (int y: v)
    D[y].push_back({x, d[y]});

  bio[x] = true;
  
  for (int y: E[x])
    if (!bio[y]) {
      y = decompose(y);
      parent[y] = x;     
    }
  return x;
}

pair <vector<int>, int> sor[MAXN];

bool manji(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b)
{
  int mn = (int) min((int) a.X.size(), (int) b.X.size());
  REP(i, mn)
    if (a.X[i] != b.X[i])
      return a.X[i] < b.X[i];
  
  return a.X.size() < b.X.size();
}

int rje[MAXN];

void dfs_dub(int node, int dub)
{
  assert(dub <= 20);
  rje[node] = dub;
  for (auto it : V[node])
    dfs_dub(it, dub+1);
}

int main()
{
  scanf("%d%d", &n, &m);
  
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    dij_a[i] = a;
    dij_b[i] = b;
    Dij[a].push_back(b);
    Dij[b].push_back(a);
  }

  REP(i, n) {
    Dij[i].push_back((i+1)%n);
    //    Dij[(i+1)%n].push_back(i);
  }

  REP(i, n) {
    sort(Dij[i].begin(), Dij[i].end());
    //    for (auto it : Dij[i]) TRACE(it);
    //    printf("\n");
  }

  gen_stablo();
  int rt = decompose(0);
  parent[rt] = -1;
  
  int broj_reg = 1 + m;  
  REP(i, broj_reg) {
    if (parent[i] != -1)
      V[parent[i]].push_back(i);
  }

  dfs_dub(rt, 1);
  
  REP(i, broj_reg) {
    sort(Komp[i].begin(), Komp[i].end(), greater<int>());
    Komp[i].resize(unique(Komp[i].begin(), Komp[i].end()) - Komp[i].begin());
    sor[i] = {Komp[i], i};
  }

  sort(sor, sor + broj_reg, manji);
  REP(i, broj_reg)
    printf("%d ", rje[sor[i].Y]);
  printf("\n");

  return 0;
}