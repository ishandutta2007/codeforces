#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20, INF = 0x3f3f3f3f;

int dp[MAX][3][5];
int p[MAX];

void upd(int &x, int val) {
  x = max(x, val);
}

int main()
{
  int N, m;
  scanf("%d%d", &N, &m);

  REP(i, N) {
    int x;
    scanf("%d", &x);
    x += 3;
    p[x]++;
  }

  REP(i, MAX) REP(j, 3) REP(k, 5) dp[i][j][k] = -INF;
  dp[2][0][0] = 0;
  FOR(n, 2, MAX) {
    REP(pr2, 3) {
      REP(prosli, 5) {
	REP(trojke, 3) {
	  if (trojke > pr2 || trojke > prosli || trojke > p[n]) continue;
	  int val = dp[n][pr2][prosli] + trojke;
	  val += (p[n] - trojke) / 3;

	  upd(dp[n+1][min(2, prosli - trojke)][(p[n] - trojke) % 3], val);
	  if (p[n] - trojke >= 3)
	    upd(dp[n+1][min(2, prosli - trojke)][min(4,(p[n] - trojke) % 3 + 3)], val - 1);
      }}
    }
  }

  int sol = 0;
  REP(i, MAX) REP(j, 3) REP(k, 5) sol = max(sol, dp[i][j][k]);
  printf("%d\n", sol);

  return 0;
}