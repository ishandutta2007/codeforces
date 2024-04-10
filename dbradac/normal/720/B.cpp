#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second
#define REP(i, n) for (int i=0; i<n; i++)

const int MAX = 60005;
const int S = 0, T = 1;

struct stre {
  int node, kap, poz;
};

vector <P> V[MAX];
int bio[MAX];
int n, e;
vector <vector<int> > Ciklusi;
int kolko[MAX];
map <P, int> Boja;
int postoji[MAX];
int pozboj[MAX];

namespace Dinic {
  const int MAXV = MAX;
  const int MAXE = MAX * 10;
  const ll oo = 1e18;
  int V, E;
  int last[MAXV], dist[MAXV], curr[MAXV];
  int next[MAXE], adj[MAXE]; ll cap[MAXE];
  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }
  void edge(int x, int y, ll c1, ll c2) {
    adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
  }
  ll push(int x, int sink, ll flow) {
    if (x == sink) return flow;
    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];
      if (cap[e] && dist[x] + 1 == dist[y])
        if (ll f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }
  ll run(int
      src, int sink) {
    ll ret =
      0;
    for (;;) {
      REP(i, V)
        curr[i] = last[i];
      REP(i, V)
        dist[i] = -1;
      queue<int> Q;
      Q.push(src), dist[src] = 0;
      while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
        }
      }
      if (dist[sink] == -1) break;
      while (ll f = push(src, sink, oo)) ret += f;
    }
    return ret;
  }
}


vector <int> Stek;

void UbaciCik(int node)
{
  vector <int> Tmp;

  for (int i=(int) Stek.size()-1; i>=0; i--) {
    Tmp.push_back(Stek[i]);
    if (Stek[i] == node)
      break;
  }

  vector <int> C;
  for (int i=0; i<(int) Tmp.size(); i++)
    C.push_back(Boja[P(Tmp[i], Tmp[(i + 1) % Tmp.size()])]);

  Ciklusi.push_back(C);
}

int br=0;
void Dfs(int node, int prosli)
{
  bio[node] = 2;
  Stek.push_back(node);

  for (auto it : V[node]) {
    br++;
    assert(br < 1e7);
    if (bio[it.X] == 2 && it.X != prosli)
      UbaciCik(it.X);
    else if (!bio[it.X])
      Dfs(it.X, node);
  }

  bio[node] = 1;
  Stek.pop_back();
}

void StaviEdge(int a, int b, int c)
{
  Dinic::edge(a, b, c, 0);
}

int main()
{
  scanf("%d%d", &n, &e);

  for (int i=0; i<e; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
    Boja[P(a, b)] = c;
    Boja[P(b, a)] = c;
    kolko[c]++;
    postoji[c] = 1;
  }

  for (int i=0; i<n; i++)
    if (!bio[i])
      Dfs(i, -1);

  for (auto it : Ciklusi)
    for (auto it2 : it)
      kolko[it2]--;

  int rje = 0;
  for (int i=0; i<MAX; i++)
    if (kolko[i])
      rje++;

  int brnode = 2;

  Dinic::init(MAX);

  for (int i=0; i<MAX; i++)
    if (postoji[i] && !kolko[i]) {
      pozboj[i] = brnode;
      StaviEdge(S, brnode++, 1);
    }

  for (auto it : Ciklusi) {
    for (auto it2 : it)
      if (!kolko[it2])
        StaviEdge(pozboj[it2], brnode, 1);
    StaviEdge(brnode++, T, (int) it.size() - 1);
  }

  printf("%lld\n", rje + Dinic::run(S, T));

  return 0;
}