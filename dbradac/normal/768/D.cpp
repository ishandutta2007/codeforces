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

const int MAX = 1005;
const double EPS = 1e-7;

int n;
double dp[10*MAX][MAX];

int main()
{
  int brq;
  scanf("%d%d", &n, &brq);

  dp[0][0] = 1;
  
  double krozn = 1.0 / n;
  REP(i, 10*MAX-2) {
    REP(j, n+1) {
      dp[i+1][j] += dp[i][j] * krozn * j;
      dp[i+1][j+1] += dp[i][j] * krozn * (n - j);
    }
  }
  
  for (; brq--; ) {
    int tmp;
    scanf("%d", &tmp);
    double prob = (tmp - EPS) / 2000;

    int da = 0;
    REP(i, 10*MAX-3)
      if (dp[i][n] >= prob) {
	da = 1;
	printf("%d\n", i);
	break;
      }

    assert(da);
  }

  return 0;
}