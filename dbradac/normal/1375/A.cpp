#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 105;

vector <int> doso[MAX][2][MAX];
int dp[MAX][2][MAX]; //
int p[MAX];
int koef[2] = {1, -1};

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &p[i]);
    REP(i, n+2) REP(j, 2) REP(k, n+2) dp[i][j][k] = -1000;

    dp[1][0][0] = dp[1][1][0] = 0;
    FOR(i, 1, n) {
      REP(st, 2) {
        REP(k, MAX) {
          REP(ja, 2) {
            int nov = koef[ja] * p[i] - koef[st] * p[i-1];
            int nk = k, nval = dp[i][st][k];

            if (nov >= 0) nk++;
            if (nov <= 0) nval++;

            if (nval > dp[i+1][ja][nk]) {
              dp[i+1][ja][nk] = nval;
              doso[i+1][ja][nk] = vector<int>{i, st, k};
            }
          }
        }
      }
    }

    vector <int> poc = {};
    REP(st, 2) REP(k, n+1) {
      if (k >= (n-1) / 2 && dp[n][st][k] >= (n-1) / 2) {
        poc = vector<int>{n, st, k};
      }
    }

    vector <int> Sol;
    for (int i=n-1; i>=0; i--) {
      assert(poc[0] == i+1);
      Sol.push_back(p[i] * koef[poc[1]]);
      poc = doso[poc[0]][poc[1]][poc[2]];
    }

    reverse(Sol.begin(), Sol.end());
    for (auto it : Sol) printf("%d ", it);
    printf("\n");

    int cnt[2] = {0, 0};
    REP(i, (int) Sol.size() - 1) {
      if (Sol[i+1] - Sol[i] >= 0) cnt[0]++;
      if (Sol[i+1] - Sol[i] <= 0) cnt[1]++;
    }
  }

  return 0;
}