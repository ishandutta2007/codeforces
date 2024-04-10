#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 5010, INF = 0x3f3f3f3f;

int dp[MAX][2*MAX], brlist[MAX];
vector <int> V[MAX];

void Dfs(int node, int prosli)
{
  if (V[node].size() == 1) {
    dp[node][MAX + 1] = 0;    
    brlist[node] = 1;
    return;
  }

  int tmp[2][2*MAX];
  memset(tmp, INF, sizeof tmp);
  tmp[0][MAX] = 0;

  int ind=0;
  for (int i=0; i<(int) V[node].size(); i++, ind ^= 1) {
    int nn = V[node][i];
    if (nn == prosli) {
      ind ^= 1;
      continue;
    }

    Dfs(nn, node);

    for (int j=0; j<2*MAX; j++)
      tmp[1^ind][j] = INF;
  
    for (int j=-brlist[node]; j<=brlist[node]; j++)
      for (int k=-brlist[nn]; k<=brlist[nn]; k++) {
        tmp[1^ind][MAX + j + k] = min(tmp[1^ind][MAX + j + k], tmp[ind][MAX + j] + dp[nn][MAX + k]); //isti su
        tmp[1^ind][MAX + j - k] = min(tmp[1^ind][MAX + j - k], tmp[ind][MAX + j] + dp[nn][MAX + k] + 1); //razliciti su
      }

    brlist[node] += brlist[nn];
  }

  for (int i=0; i<2*MAX; i++)
    dp[node][i] = tmp[ind][i];
}

int main()
{
  int n;

  memset(dp, INF, sizeof dp);

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  if (n == 2) {
    printf("1\n");
    return 0;
  }

  for (int i=0; i<n; i++)
    if (V[i].size() > 1) {
      Dfs(i, -1);
      printf("%d\n", dp[i][MAX]);
      break;
    }

  return 0;
}