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

const ll INF = 1e18;
const int GR = 1900;

int main()
{
  ll gornja = INF, donja = -INF;

  int n;
  scanf("%d", &n);
  
  ll sum = 0;

  REP(i, n) {
    int c, d;
    scanf("%d%d", &c, &d);
    if (d == 2)
      gornja = min(gornja, GR - 1 - sum);
    else
      donja = max(donja, GR - sum);

    sum += c;
  }

  if (donja > gornja)
    printf("Impossible\n");
  else if (gornja >= INF / 2)
    printf("Infinity\n");
  else
    printf("%lld\n", gornja + sum);

  return 0;
}