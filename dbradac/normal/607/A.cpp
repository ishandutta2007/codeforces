#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

P p[MAX];
int dp[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d%d", &p[i].X, &p[i].Y);

  sort(p + 1, p + n + 1);

  int rje = n;
  for (int i=1; i<=n; i++) {
    int poz = lower_bound(p + 1, p + n + 1, P(p[i].X - p[i].Y, -1)) - p;
    dp[i] = dp[poz - 1] + i - poz;
    rje = min(rje, dp[i] + n - i);
  }

  printf("%d\n", rje);

  return 0;
}