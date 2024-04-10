#include <cmath>
#include <cstdlib>
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

const int MAX = 1<<19;

vector <P> V[MAX]; //node, id
ll rje[MAX];
ll val[MAX];
int bio[MAX], disc[MAX], par[MAX], vr;
int col[MAX];
int ea[MAX], eb[MAX];
int done[MAX];

int dfs_bip(int node, int cl) {
  if (col[node] != -1)
    return col[node] == cl;
  col[node] = cl;

  for (auto it : V[node])
    if (!dfs_bip(it.X, 1^cl)) return 0;
  return 1;
}

int bip() {
  memset(col, -1, sizeof col);
  return dfs_bip(0, 0);
}

int dub[MAX];
int jelbip;
vector <int> Ciklus;
vector <int> CikEdge;
int incik[MAX];

void uzmi_cik(int node, int gor) {
  Ciklus.push_back(node);
  for (;;) {
    assert(par[node] != -1);
    node = par[node];
    Ciklus.push_back(node);
    if (node == gor) break;
  }
}

void nadi_cik(int node, int pr) {
  dub[node] = (pr == -1) ? 0 : (dub[pr] + 1);
  bio[node] = 1;
  disc[node] = vr++;
  par[node] = pr;

  for (auto it : V[node]) {
    if (it.X == pr) continue;
    if (bio[it.X] && disc[it.X] < disc[node]) {
      if (jelbip || ((dub[node] - dub[it.X]) % 2 == 0)) {
        uzmi_cik(node, it.X);
        return;
      }
    }
    if (!bio[it.X]) {
      nadi_cik(it.X, node);
      if (Ciklus.size()) return;
    }
  }
}

int deg[MAX];

void set_edge(int id, ll vl) {
  assert(!done[id]);
  done[id] = 1;
  int a = ea[id], b = eb[id];
  rje[id] = vl;
  deg[a]--; deg[b]--;
  val[a] -= vl;
  val[b] -= vl;
}

void dfs_sol(int node, int pr) {
  bio[node] = 1;

  for (auto it : V[node]) {
    if (it.X == pr) continue;

    if (!bio[it.X]) dfs_sol(it.X, node);
    if (!done[it.Y] && !incik[it.Y]) {
      if (deg[node] == 1) set_edge(it.Y, val[node]);
      else if (deg[it.X] == 1) set_edge(it.Y, val[it.X]);
      else set_edge(it.Y, rand() & 1 ? 1 : -1);
    }
  }
}

int n, m;

int check() {
  int nope = 0;
  REP(i, m) if (!done[i]) nope++;
  assert(!nope);
  REP(i, n) if (val[i]) return 0;
  REP(i, m) assert(abs(rje[i]) <= 2ll * n * n);

  return 1;
}

void sol_cik() {
  if (Ciklus.empty()) return;

  ll sum = 0;
  int csz = (int) Ciklus.size();
  assert(CikEdge.size() == Ciklus.size());

  REP(i, csz) {
    if (!(i % 2)) sum += val[Ciklus[i]];
    else sum -= val[Ciklus[i]];
  }

  assert(sum % 2 == 0);
  set_edge(CikEdge.back(), sum/2);
  REP(i, csz-1)
    set_edge(CikEdge[i], val[Ciklus[i]]);
}

int main()
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%lld", &val[i]);
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    ea[i] = a;
    eb[i] = b;
    V[a].push_back(P(b, i));
    V[b].push_back(P(a, i));
  }

  jelbip = bip();

  memset(bio, 0, sizeof bio);
  nadi_cik(0, -1);

  int csz = (int) Ciklus.size();

  REP(i, csz) {
    int a = Ciklus[i], b = Ciklus[(i+1) % csz];
    for (auto it : V[a])
      if (it.X == b) {
        incik[it.Y] = 1;
        CikEdge.push_back(it.Y);
      }
  }

  memset(bio, 0, sizeof bio);

  REP(i, n) deg[i] = (int) V[i].size();
  if (!Ciklus.empty()) {
    dfs_sol(Ciklus[0], -1);
    sol_cik();
  }
  else dfs_sol(0, -1);

  if (check()) {
    printf("YES\n");
    REP(i, m) printf("%lld\n", rje[i]);
  }
  else printf("NO\n");

  return 0;
}