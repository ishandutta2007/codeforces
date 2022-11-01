#include <cmath>
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

typedef double lf;
typedef pair<lf, lf> P;
#define X first
#define Y second

const int MAX = 2505;

double dist[MAX][MAX];
double dp[MAX][MAX][2];
P p[MAX];
int n;

double sq(double x) { return x*x; }

double distance(P a, P b) {
  return sqrt(sq(a.X-b.X) + sq(a.Y-b.Y));
}

int nxt(int a) {
  if (a == n-1) return 0;
  return a + 1;
}

int prv(int a) {
  if (!a) return n-1;
  return a - 1;
}

double rek(int a, int b, int st) {
  if (nxt(a) == b) return 0;
  if (dp[a][b][st] >= 0) return dp[a][b][st];

  double ret = 0;
  int ja = st ? b : a;

  ret = max(rek(nxt(a), b, 0) + dist[ja][nxt(a)],
	    rek(a, prv(b), 1) + dist[ja][prv(b)]);
  
  return dp[a][b][st] = ret;
}

int main()
{
  scanf("%d", &n);
  REP(i, n)
    scanf("%lf%lf", &p[i].X, &p[i].Y);

  REP(i, n)
    REP(j, n)
    dist[i][j] = distance(p[i], p[j]);

  REP(i, MAX) REP(j, MAX) dp[i][j][0] = dp[i][j][1] = -1;

  double rje = 0;
  REP(i, n)
    rje = max(rje, rek(i, i, 0));

  printf("%.12lf\n", rje);
  
  return 0;
}