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

const int MAX = 2005, MOD = 998244353;

int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (int) (((ll) a * b) % MOD); }

int dp[MAX][MAX];

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  dp[0][0] = m;
  FOR(i, 1, n) {
    REP(j, k+1) {
      dp[i][j] = add(dp[i-1][j], dp[i][j]);
      if (j) dp[i][j] = add(mul(dp[i-1][j-1], m-1), dp[i][j]);
    }
  }

  printf("%d\n", dp[n-1][k]);

  return 0;
}