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

const int MAXN = 80, MAXK = 20, MOD = 1e9 + 7;

int add(int a, int b)
{
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int prva[MAXN];
int n;
int dp[MAXN][1<<MAXK];
char s[MAXN];

int main()
{
  scanf("%d %s", &n, s);

  REP(i, n) {
    prva[i] = -1;
    for (int j=i; j<n; j++) {
      if (s[j] == '1') {
        prva[i] = j;
        break;
      }
    }
  }

  REP(i, n)
    dp[i][0] = 1;

  REP(i, n) {
    REP(msk, 1<<MAXK) {
      int tmp = prva[i], val = 0;
      if (tmp == -1) continue;
      for (int j=tmp; j<n; j++) {
        val = 2 * val + s[j] - '0';
        if (val > MAXK) break;
        int nmsk = msk | (1<<(val-1));
        dp[j+1][nmsk] = add(dp[j+1][nmsk], dp[i][msk]);
      }
    }
  }

  int rje = 0;

  REP(i, n+1) 
    FOR(j, 1, MAXK+1)
      rje = add(rje, dp[i][(1<<j)-1]);

  printf("%d\n", rje);

  return 0;
}