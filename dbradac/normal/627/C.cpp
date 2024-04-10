#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200100;

P p[MAX];
int val[MAX];

struct str {
  int cij, poz, kol;
};

void Nope()
{
  printf("-1\n");
  exit(0);
}

int main()
{
  int dist, kap, n;

  scanf("%d%d%d", &dist, &kap, &n);

  for (int i=0; i<n; i++)
    scanf("%d%d", &p[i].X, &p[i].Y);

  p[n++] = P(0, 0);
  sort(p, p + n);

  if (dist - p[n-1].X > kap || p[0].X > kap)
    Nope();

  for (int i=1; i<n; i++)
    if (p[i].X - p[i-1].X > kap)
      Nope();

  stack <str> S;
  S.push(str { 0, dist, 0 });
  S.push(str { p[n-1].Y, p[n-1].X, dist - p[n-1].X });
  ll rje = (dist - p[n-1].X) * (ll) p[n-1].Y;

  for (int i=n-2; i>=0; i--) {
    int tkol = p[i+1].X - p[i].X;
    rje += (ll) tkol * p[i].Y;
    for (; !S.empty(); ) {
      str tmp = S.top();
      if (tmp.cij <= p[i].Y)
        break;

      int putt = min(kap - tkol, tmp.kol);
      rje -= (tmp.cij - p[i].Y) * (ll) putt;

      tkol += putt;
      S.pop();
      if (tkol == kap)
        break;
    }

    S.push(str {p[i].Y, p[i].X, tkol});
  }

  printf("%lld\n", rje);

  return 0;
}