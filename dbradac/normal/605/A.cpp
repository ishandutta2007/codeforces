#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int dp[MAX], rje=0;
int p[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    dp[p[i]] = dp[p[i]-1] + 1;
    rje = max(rje, dp[p[i]]);
  }

  printf("%d\n", n - rje);

  return 0;
}