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

const int MAX = 1<<17;
const double EPS = 1e-13;

int X1, X2, Y1, Y2;
double lo = 0, hi = 1e50;

void nope() {
  printf("-1\n");
  exit(0);
}

pair<double, double> daj(int poz, int brz, int st) {
  int a, b;
  if (!st) { a = X1; b = X2; }
  else { a = Y1; b = Y2; }

  if (brz == 0) {
    if (poz > a && poz < b) return {0, 1e50};
    nope();
  }
  if (brz > 0)
    return { ((double) a - poz) / brz, ((double) b - poz) / brz };
  return { ((double) b - poz) / brz, ((double) a - poz) / brz };
}

int main()
{
  int n;
  scanf("%d", &n);
  scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
  //  TRACE(X1 _ X2 _ Y1 _ Y2);

  REP(i, n) {
    int x, y, bx, by;
    scanf("%d%d%d%d", &x, &y, &bx, &by);
    auto tmp = daj(x, bx, 0);
    lo = max(lo, tmp.X);
    hi = min(hi, tmp.Y);

    //    TRACE(tmp.X _ tmp.Y);
    tmp = daj(y, by, 1);
    lo = max(lo, tmp.X);
    hi = min(hi, tmp.Y);

    //    TRACE(tmp.X _ tmp.Y);
  }

  if (hi - EPS > lo)
    printf("%.10lf\n", lo);
  else
    nope();
  
  return 0;
}