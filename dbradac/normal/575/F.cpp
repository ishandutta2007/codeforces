#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 10010;
const ll INF = 1e18;

ll dp[2][MAX];
int poz[MAX];
int l[MAX], r[MAX];

int Dist(int ind, int x)
{
  if (r[ind] < x)
    return x - r[ind];
  if (l[ind] > x)
    return l[ind] - x;
  return 0;
}

int main()
{
  int n, poc;

  for (int i=0; i<2; i++)
    for (int j=0; j<MAX; j++)
      dp[i][j] = INF;

  scanf("%d%d", &n, &poc);
  poz[2*n] = poc;

  for (int i=0; i<n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    poz[2*i] = l[i];
    poz[2*i+1] = r[i];
  }

  int brp = 2 * n + 1;
  sort(poz, poz + brp);

  dp[0][lower_bound(poz, poz + brp, poc) - poz] = 0;

  int ind=0;
  for (int i=0; i<n; i++, ind^=1) {
    for (int j=0; j<MAX; j++)
      dp[ind^1][j] = INF;

    ll minn = INF;
    for (int j=0; j<brp; j++) {
      minn = min(minn, dp[ind][j] - poz[j]);
      dp[1^ind][j] = min(dp[1^ind][j], poz[j] + minn + Dist(i, poz[j]));
    }

    minn = INF;
    for (int j=brp-1; j>=0; j--) {
      minn = min(minn, dp[ind][j] + poz[j]);
      dp[1^ind][j] = min(dp[1^ind][j], -poz[j] + minn + Dist(i, poz[j]));
    }
  }

  ll rje=INF;
  for (int i=0; i<brp; i++)
    rje = min(rje, dp[ind][i]);

  printf("%lld\n", rje);

  return 0;
}