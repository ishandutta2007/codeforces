#include <set>
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

int cost[MAX];
multiset <P> S;
int t[MAX];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  FOR(i, 1, n+1) scanf("%d", &cost[i]);
  int ind = 1;
  
  FOR(i, k+1, n+k+1) {
    for (; ind<=i && ind <= n; ind++)
      S.insert(P(cost[ind], ind));

    assert(!S.empty());
    auto it = --S.end();
    t[it->Y] = i;
    //    TRACE(i _ it->Y);
    S.erase(it);
  }

  ll rje = 0;
  FOR(i, 1, n+1)
    rje += (ll) cost[i] * (t[i] - i);

  printf("%lld\n", rje);
  FOR(i, 1, n+1)
    printf("%d ", t[i]);
  printf("\n");

  return 0;
}