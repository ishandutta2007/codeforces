#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<19;
const ll INF = 1e18;

int n, q;
vector <int> V[MAX];
set <P> S[MAX];
vector <int> Nodeovi[MAX];
int sroot[MAX];
ll oduz[MAX];
int disc[MAX], vr=1;
ll rje=0;

void Merge(int a, int b)
{
  a = sroot[a];
  b = sroot[b];

  if (S[a].size() + Nodeovi[a].size() < S[b].size() + Nodeovi[b].size())
    swap(a, b);

  for (auto it : S[b])
    S[a].insert(P(it.X - oduz[b] + oduz[a], it.Y));

  for (auto it : Nodeovi[b]) {
    Nodeovi[a].push_back(it);
    sroot[it] = a;
  }

  vector<int>().swap(Nodeovi[b]);
  set<P>().swap(S[b]);
}

void Dfs(int node, int prosli)
{
  disc[node] = vr++;

  for (auto it : V[node])
    if (it != prosli)
      Dfs(it, node);
}

int DfsRje(int node, int prosli)
{
  int gore = MAX;

  for (auto it : V[node])
    if (it != prosli) {
      gore = min(gore, DfsRje(it, node));
      Merge(node, it);
    }

  if (gore < disc[node])
    return gore;

  int pz = sroot[node];

  for (auto it = S[pz].begin(); it != S[pz].end(); ) {
    if (disc[it->Y] >= disc[node]) {
      auto it2 = it++;
      S[pz].erase(it2);
    }
    else {
      rje += (it->X - oduz[pz]);
      oduz[pz] += it->X - oduz[pz];
      return disc[it->Y];
    }
  }

  if (node) {
    printf("-1\n");
    exit(0);
  }

  return 0;
}

int main()
{
  scanf("%d%d", &n, &q);

  for (int i=0; i<n; i++) {
    Nodeovi[i].push_back(i);
    sroot[i] = i;
  }

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Dfs(0, -1);

  for (int i=0; i<q; i++) {
    int dol, gor, val;
    scanf("%d%d%d", &dol, &gor, &val); dol--; gor--;
    if (disc[gor] > disc[dol])
      swap(gor, dol);

    S[dol].insert(P(val, gor));
  }

  DfsRje(0, -1);
  printf("%lld\n", rje);

  return 0;
}