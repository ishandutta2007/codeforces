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

const int MAX = 1e4 + 3;
const ll INF = 1e18;

int s[MAX], t[MAX];
int n, c;
ll dp[2][MAX];

int main()
{
  scanf("%d%d", &n, &c);

  for (int i=0; i<n; i++)
    scanf("%d", &s[i]);

  for (int i=0; i<n; i++)
    scanf("%d", &t[i]);
  
  int ind = 0;
  for (int i=n-1; i>=0; i--, ind^=1) {
    for (int j=0; j<MAX; j++)
      dp[1^ind][j] = INF;

    for (int j=0; j<MAX-1; j++) {
      dp[1^ind][j+1] = min(dp[1^ind][j+1], dp[ind][j] + s[i]);
      dp[1^ind][j] = min(dp[1^ind][j], dp[ind][j] + t[i] + (ll) c * j);
    }
    dp[1^ind][0] = min(dp[1^ind][0], dp[ind][0] + t[i]);
  }

  ll rje = INF;
  for (int i=0; i<MAX; i++)
    rje = min(rje, dp[ind][i]);

  printf("%lld\n", rje);

  return 0;
}