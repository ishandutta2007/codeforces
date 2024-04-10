#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x)
//#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18, LG = 19;

vector <int> V[MAX];
int sub[MAX];
int par[MAX], lca[MAX][LG];
int disc[MAX], fin[MAX], vr=1;
int dub[MAX];
int val[MAX];
char slova[MAX];
map <P, int> Done;

void dfs(int node, int pr) {
  if (!node) pr = node;
  disc[node] = vr++;
  val[node] = val[pr];
  val[node] ^= (1<<(slova[node]-'a'));

  dub[node] = dub[pr] + 1;
  par[node] = pr;
  lca[node][0] = pr;
  FOR(i, 1, LG) lca[node][i] = lca[lca[node][i-1]][i-1];

  REP(i, (int) V[node].size()) {
    int it = V[node][i];
    if (it == pr) { V[node].erase(V[node].begin() + i--); continue; }
    if (it != pr) dfs(it, node);
  }

  fin[node] = vr;
  sub[node] = fin[node] - disc[node];
}

int get_lca(int a, int b) {
  if (dub[a] > dub[b]) swap(a, b);
  int raz = dub[b] - dub[a];
  REP(i, LG)
    if (raz & (1<<i))
      b = lca[b][i];

  if (a == b) return a;

  for (int i=LG-1; i>=0; i--) {
    if (lca[a][i] != lca[b][i]) {
      a = lca[a][i];
      b = lca[b][i];
    }
  }

  return lca[a][0];
}

int kol[1<<20];
ll prom[1<<20];
ll p[MAX];

void pocisti(int pos) {
  p[pos] += prom[val[pos]];
  kol[val[pos]]--;

  for (auto it : V[pos])
    if (it != par[pos])
      pocisti(it);
}

void potrpaj(int pos) {
  p[pos] -= prom[val[pos]];
  kol[val[pos]]++;
  for (auto it : V[pos])
    if (it != par[pos])
      potrpaj(it);
}

void upd_rje(int pos, int root) {

  REP(extra_slovo, 21) {
    int nmsk = val[pos] ^ (1<<(slova[root]-'a'));
    if (extra_slovo != 20) nmsk ^= 1<<extra_slovo;
    
    int kolko = (int) kol[nmsk];
    prom[nmsk]++;
    if (pos != root)
      p[pos] += kolko;

    if (root) {
      if (pos == root) p[par[root]] -= kolko;
      else {
        p[par[root]] -= kolko;
        p[root] -= kolko;
      }
    }
    else if (pos != root) p[root] -= kolko;
  }
}

void rjesavaj(int pos, int root) {
  upd_rje(pos, root);

  for (auto it : V[pos])
    if (it != par[pos])
      rjesavaj(it, root);
}

void sol(int node) {
  int mx = -1, ind=-1;
  for (auto it : V[node])
    if (it != par[node] && sub[it] > mx) {
      mx = sub[it];
      ind = it;
    }

  for (auto it : V[node]) {
    if (it != ind && it != par[node]) {
      sol(it);
      pocisti(it);
    }
  }
  
  if (ind!=-1)
    sol(ind);

  for (auto it : V[node]) {
    if (it != par[node] && it != ind) {
      rjesavaj(it, node);
      potrpaj(it);
    }
  }

  upd_rje(node, node);
  p[node] -= prom[val[node]];
  kol[val[node]]++;
}

ll rje[MAX];
ll dfs_rje(int pos) {
  ll ret = p[pos];
  for (auto it : V[pos])
    if (it != par[pos])
      ret += dfs_rje(it);

  return rje[pos] = ret;
}

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  scanf(" %s", slova);
  dfs(0, 0);
  sol(0);
  pocisti(0);
  dfs_rje(0);

  REP(i, n) printf("%lld ", rje[i]+1);
  printf("\n");
  
  return 0;
}