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

const int MAX = 1<<20;

int bio[MAX];
vector <int> V[MAX];
int a[MAX], b[MAX];
int deg[MAX];

void dfs(int x)
{
  if (bio[x]++) return;
  for (auto it : V[x]) dfs(it);
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  int usebe = 0;
  REP(i, m) {
    scanf("%d%d", &a[i], &b[i]); a[i]--; b[i]--;
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
    if (a[i] == b[i]) usebe++;
    else {
      deg[a[i]]++;
      deg[b[i]]++;
    }
  }

  REP(i, n) {
    if (V[i].size()) {
      dfs(i);
      break;
    }
  }

  REP(i, n)
    if (!bio[i] && V[i].size()) {
      printf("0\n");
      return 0;
    }

  ll rje = 0;
  rje += (ll) usebe * (usebe - 1) / 2;
  rje += (ll) usebe * (m - usebe);

  REP(i, n)
    rje += (ll) deg[i] * (deg[i] - 1) / 2;

  printf("%lld\n", rje);

  return 0;
}