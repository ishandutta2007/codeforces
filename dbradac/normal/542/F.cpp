#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1005;
int dp[MAX][MAX];
int sum[MAX];
vector <int> V[MAX];

int Rek(int dub, int br)
{
  if (br >= MAX)
    return sum[dub];
  if (dp[dub][br] != -1)
    return dp[dub][br];
  if (!br)
    return 0;

  int ret=0;
  ret = max(ret, Rek(dub+1, 2*br));
    
  for (int i=0, ts=0; i<(int) V[dub].size(); i++) {
    if (i >= br)
      break;
    ts += V[dub][i];
    ret = max(ret, ts + Rek(dub + 1, 2 * (br - i - 1)));
  }

  return dp[dub][br] = ret;
}

int main()
{
  int n, T;

  scanf("%d%d", &n, &T);

  for (int i=0; i<n; i++) {
    int t, v;
    scanf("%d%d", &t, &v);
    V[T-t].push_back(v);
  }
  
  for (int i=0; i<MAX; i++)
    sort(V[i].begin(), V[i].end(), greater<int>());

  for (int i=MAX-5; i>=0; i--) {
    sum[i] = sum[i+1];
    for (int j=0; j<(int) V[i].size(); j++)
      sum[i] += V[i][j];
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", Rek(0, 1));

  return 0;
}