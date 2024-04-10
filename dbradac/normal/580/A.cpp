#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f, MAX = 1<<17;

int p[MAX], dp[MAX];

int main()
{
  int n, rje=0;

  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    if (p[i] >= p[i-1])
      dp[i] = dp[i-1] + 1;
    else
      dp[i] = 1;
    rje = max(rje, dp[i]);
  }

  printf("%d\n", rje);

  return 0;
}