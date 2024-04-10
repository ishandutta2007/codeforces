#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 20, MAXK = 1<<17;

char s[MAXN][MAXK];
int dp[2][MAXN+1][1<<MAXN];
int brred, brstup;

int main()
{
  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);

  for (int j=0; j<brstup; j++) {
    int br=0;
    for (int i=0; i<brred; i++)
      br = 2 * br + s[i][j] - '0';

    for (int i=0; i<=brred; i++)
      dp[0][i][br] += max(i, brred - i);
  }

  int ind=0;
  for (int i=0; i<brred; i++, ind^=1) {
    memset(dp[1^ind], 0, sizeof dp[1^ind]);
    for (int j=0; j<=brred; j++)
      for (int k=0; k<(1<<brred); k++) {
        dp[1^ind][j][k ^ (1<<i)] += dp[ind][j][k];
        if (j)
          dp[1^ind][j-1][k] += dp[ind][j][k];
      }
  }

  int rje=0;
  for (int i=0; i<(1<<brred); i++)
    rje = max(rje, dp[ind][0][i]);

  printf("%d\n", brred * brstup - rje);

  return 0;
}