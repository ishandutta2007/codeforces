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

const int MAX = 300100, MAXK = 105, INF = 0x3f3f3f3f;

int dp[MAX][MAXK];
int p[MAX], n;

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);

  memset(dp, INF, sizeof dp);
  
  dp[0][0] = 0;
  REP(i, n) {    
    int st = p[i] / 1000;
    REP(j, MAXK-2) {
      dp[i+1][j+st] = min(dp[i+1][j+st], dp[i][j] + 10*st);
      dp[i+1][max(0, j-10*st)] = min(dp[i+1][max(0, j-10*st)], dp[i][j] + max(0, 10*st - j));
    }
  }  

  int rje = INF;
  REP(i, MAXK) rje = min(rje, dp[n][i]);
  cout << (ll) rje * 100 << endl;

  return 0;
}