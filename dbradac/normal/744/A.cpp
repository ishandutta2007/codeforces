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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1005;

int slob;
vector <int> Sz;
vector <int> V[MAX];
int n;
int bio[MAX];
int bitan[MAX];
int gov;

int dfs(int node)
{
  if (bio[node]++) return 0;
  if (bitan[node] != -1)
    gov = bitan[node];

  int ret = 1;
  for (auto it : V[node])
    ret += dfs(it);

  return ret;
}

void komp()
{
  REP(i, n) {
    if (!bio[i]) {
      gov=-1;
      int tmp = dfs(i);
      if (gov == -1)
        slob += tmp;
      else
        Sz.push_back(tmp);
    }
  }
}

int main()
{
  int m, k;

  scanf("%d%d%d", &n, &m, &k);

  memset(bitan, -1, sizeof bitan);
  REP(i, k) {
    int x; scanf("%d", &x); x--;
    bitan[x] = i;
  }

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);    
  }

  komp();
  assert((int) Sz.size() == k);

  ll rje = -m;
  sort(Sz.begin(), Sz.end(), greater<int>());
  Sz[0] += slob;

  REP(i, k)
    rje += ((ll) Sz[i] * (Sz[i] - 1)) / 2;

  printf("%lld\n", rje);

  return 0;
}