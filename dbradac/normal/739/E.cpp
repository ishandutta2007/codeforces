#include <cstdio>
#include <ctime>
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
typedef double lf;
typedef pair<lf, lf> P;
typedef pair<int, int> pii;
#define X first
#define Y second

const int MAX = 2005;
const double TL = 4.8;
const double INF = 1e18;
const double EPS = 1e-8;

bool eq(lf a, lf b)
{
  return max(a - b, b - a) < EPS;
}

P p[MAX];
lf dp[MAX][MAX];
pii doso[MAX][MAX];
int n;
int kola, kolb;

void stavi(int dos_i, int dos_j, int nov_i, int nov_j, lf val)
{
  if (dp[nov_i][nov_j] + EPS < val) {
    dp[nov_i][nov_j] = val;
    doso[nov_i][nov_j] = pii(dos_i, dos_j);
  }
}

pair<lf, int> dinam(lf x)
{
  REP(i, n+1) {
    REP(j,n+1) {
      dp[i][j] = -INF;
      doso[i][j] = pii(-1, -1);
    }
  }

  dp[0][0] = 0;
  REP(i, n) {
    REP(j, kola+1) {
      stavi(i, j, i + 1, j, dp[i][j] + p[i].Y + x);
      stavi(i, j, i + 1, j, dp[i][j]);
      stavi(i, j, i + 1, j + 1, dp[i][j] + 1 - (1 - p[i].X) * (1 - p[i].Y) + x);
      stavi(i, j, i + 1, j + 1, dp[i][j] + p[i].X);
    }
  }

  int kkk = 0;
  pii poz = pii(n, kola);
  for (; poz.X; ) {
    pii tmp = doso[poz.X][poz.Y];
    if (!eq(dp[poz.X][poz.Y], dp[tmp.X][tmp.Y])) {
      if (poz.Y == tmp.Y) {
        kkk++;
      }
      else if (!eq(dp[tmp.X][tmp.Y] + p[tmp.X].X, dp[poz.X][poz.Y]))
        kkk++;
    }
    poz = tmp;
  }

  return make_pair(dp[n][kola], kkk);
}

lf solve()
{
  lf poc = (double) clock() / CLOCKS_PER_SEC;
  lf lo = -1e4, hi = 1e4;

  for (; (double) clock() / CLOCKS_PER_SEC - poc < TL;) {
    lf mid = (lo + hi) / 2;
    auto tmp = dinam(mid);

    if (tmp.Y == kolb)
      return tmp.X - kolb * mid;
    if (tmp.Y < kolb)
      lo = mid;
    else if (tmp.Y > kolb)
      hi = mid;
  }

  auto tmp = dinam(lo);
  return tmp.X - kolb * lo;
}

int main()
{
  scanf("%d%d%d", &n, &kola, &kolb);

  REP(i, n)
    scanf("%lf", &p[i].X);
  REP(i, n)
    scanf("%lf", &p[i].Y);

  printf("%.10lf\n", solve());

  return 0;
}