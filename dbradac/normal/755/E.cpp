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

int e[MAX][MAX];
int n, k;

void nope()
{
  printf("-1\n");
  exit(0);
}

void ispis()
{
  vector <P> R;
  REP(i, n)
    REP(j, n)
    if (e[i][j])
      R.push_back({i, j});

  printf("%d\n", (int) R.size());
  for (auto it : R)
    printf("%d %d\n", it.X+1, it.Y+1);
}
/*
int prov()
{
  int edge[10][10];

  int rje = 1000;
  REP(st, 2) {
    REP(i, n)
      REP(j, n) {
        if (i == j) edge[i][j] = 0;
        else if (e[i][j] == st) edge[i][j] = 1;
        else edge[i][j] = 1000;
        }

    REP(i, n)
      REP(j, n)
      REP(l, n)
      edge[j][l] = min(edge[j][l], edge[j][i] + edge[i][l]);

    int mx = -1;
    REP(i, n)
      REP(j, n)
        mx = max(mx, edge[i][j]);

    if (mx >= 500) return 0;

    rje = min(rje, mx);
  }

  if (rje == k) {
    printf("DA\n");
    exit(0);
  }

  return rje == k;
}
*/

int main()
{
  scanf("%d%d", &n, &k);

  if (k == 1 || k > 3) nope();
  if (k == 2 && n <= 4) nope();
  if (k >= n) nope();

  if (k == 2) {
    REP(i, n-1)
      e[i][i+1] = 1;
  }
  else {
    FOR(i, 1, n-1)
      e[0][i] = 1;
    e[1][n-1] = 1;
  }

  ispis();

  return 0;
}