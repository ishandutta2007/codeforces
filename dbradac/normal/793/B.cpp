#include <deque>
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

int pr[4] = {1, 0, -1, 0};
int ps[4] = {0, 1, 0, -1};
char s[MAX][MAX];
P poc, kraj;
int dp[MAX][MAX][4], done[MAX][MAX][4];
int brred, brstup;

int van(int red, int stup) {
  return red >= brred || red < 0 || stup >= brstup || stup < 0;
}

int bfs() {
  deque <pair<P, int> > Q;
  memset(dp, -1, sizeof dp);
  REP(i, 4) {
    dp[poc.X][poc.Y][i] = 0;
    Q.push_front({poc, i});
  }

  for (; !Q.empty(); ) {
    auto tmp = Q.front(); Q.pop_front();
    if (done[tmp.X.X][tmp.X.Y][tmp.Y]++) continue;
    int ja = dp[tmp.X.X][tmp.X.Y][tmp.Y];
    P slj = P(tmp.X.X + pr[tmp.Y], tmp.X.Y + ps[tmp.Y]);
    if (!van(slj.X, slj.Y) && s[slj.X][slj.Y] != '*') {      
      if (dp[slj.X][slj.Y][tmp.Y] == -1 || dp[slj.X][slj.Y][tmp.Y] > ja) {
	dp[slj.X][slj.Y][tmp.Y] = ja;
	Q.push_front({slj, tmp.Y});
      }
    }

    REP(i, 4) {
      if (dp[tmp.X.X][tmp.X.Y][i] == -1) {
	dp[tmp.X.X][tmp.X.Y][i] = ja + 1;
	Q.push_back({tmp.X, i});
      }
    }
  }

  int mn = 123;
  REP(i, 4) {
    mn = min(mn, dp[kraj.X][kraj.Y][i]);
    if (dp[kraj.X][kraj.Y][i] <= 2 && dp[kraj.X][kraj.Y][i] != -1) return 1;
  }
  TRACE(mn);
  return 0;  
}

int main()
{
  scanf("%d%d", &brred, &brstup);
  REP(i, brred)
    scanf(" %s", s[i]);

  REP(i, brred) {
    REP(j, brstup) {
      if (s[i][j] == 'S') poc = P(i, j);
      if (s[i][j] == 'T') kraj = P(i, j);
    }
  }

  if (bfs())
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}