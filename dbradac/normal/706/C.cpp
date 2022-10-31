#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;
const ll INF = 1e18;

string s[MAX][2];
int c[MAX];
ll dp[MAX][2];
char ss[MAX];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &c[i]);
  for (int i=0; i<n; i++) {
    scanf("%s", ss);
    s[i][0] = s[i][1] = ss;
    reverse(s[i][1].begin(), s[i][1].end());
  }

  for (int i=0; i<MAX; i++)
    for (int j=0; j<2; j++)
      dp[i][j] = INF;

  dp[1][0] = 0;
  dp[1][1] = c[0];

  for (int i=1; i<n; i++)
    for (int j=0; j<2; j++)
      for (int k=0; k<2; k++)
        if (!(s[i-1][j] > s[i][k]))
          dp[i+1][k] = min(dp[i+1][k], dp[i][j] + k * c[i]);
  
  ll rje = min(dp[n][0], dp[n][1]);
  printf("%lld\n", rje < INF / 2 ? rje : -1);
    
	return 0;
}