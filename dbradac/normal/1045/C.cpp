#include <cstdio>
#include <stack>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAXN = 1<<20, LG = 20;

int lca[MAXN][LG];
int n, m;
vector< int > G[MAXN];
vector< pair< int, int > > com[MAXN]; // N - 1 maks
int ccom;

void init(int _n) { 
  n = _n;
  REP(i, n) G[i].clear();
  m = 0;
  ccom = 0;
}

void add_edge(int a, int b) {
  G[a].push_back(b);
  G[b].push_back(a);
  ++m;
}

enum {WHITE, GRAY, BLACK};
int color[MAXN];
int dis[MAXN], tick;
int low[MAXN];
int art[MAXN];
stack< pair< int, int > > stk;

void dfs(int i, int dad, bool is_root) {
  color[i] = GRAY;
  low[i] = dis[i] = ++tick;
  int cnt = 0;

  REP(jt, (int)G[i].size()) {
    int j = G[i][jt];
    if (j == dad) continue;
    if (color[j] == GRAY) {
      low[i] = min(low[i], dis[j]);
      stk.push({i, j});
    }
    else if (color[j] == WHITE) {
      stk.push({i, j});
      dfs(j, i, 0);
      low[i] = min(low[i], low[j]);

      if (low[j] < dis[i]) continue;
      if (!is_root) art[i] = 1;

      ++cnt;
      pair< int, int > e = {-1, -1};
      com[ccom].clear();

      do {
        e = stk.top(); stk.pop();
        com[ccom].push_back(e);
      } while (e != make_pair(i, j));

      ++ccom;
    }
  }

  if (is_root && cnt >= 2) art[i] = 1;

  color[i] = BLACK;
}

void decompose() {
  REP(i, n) art[i] = low[i] = dis[i] = 0, color[i] = WHITE;
  REP(i, n) if (color[i] == WHITE) dfs(i, -1, 1);
  assert(stk.empty());
}

vector <int> St[MAXN];
int bio[MAXN];

void gen_st() {
  REP(i, ccom) {
    for (auto it : com[i]) {
      if (!bio[it.X]++) {
        St[i+n].push_back(it.X);
        St[it.X].push_back(i+n);
      }
      if (!bio[it.Y]++) {
        St[i+n].push_back(it.Y);
        St[it.Y].push_back(i+n);
      }
    }

    for (auto it : com[i]) {
      bio[it.X] = bio[it.Y] = 0;
    }
  }
}

int dub[MAXN];
void dfs_lca(int node, int pr) {
  dub[node] = dub[pr] + 1;
  lca[node][0] = pr;
  FOR(i, 1, LG)
    lca[node][i] = lca[lca[node][i-1]][i-1];

  for (auto it : St[node])
    if (it != pr)
      dfs_lca(it, node);
}

int f_lca(int a, int b) {
  if (dub[a] > dub[b]) swap(a,b);
  int raz = dub[b] - dub[a];
  REP(i, LG)
    if (raz>>i & 1)
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

int main()
{
  int N, M, q;
  scanf("%d%d%d", &N, &M, &q);

  init(N);
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    add_edge(a, b);
  }

  decompose();
  gen_st();
  REP(i, N)
    if (dub[i] == 0)
      dfs_lca(i, i);

  for (; q--; ) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    int lc = f_lca(a, b);
    printf("%d\n", (dub[a] + dub[b] - 2*dub[lc]) / 2);
  }

  return 0;
}