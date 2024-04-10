#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 601000, MAXK = 5005;
const ll INF = 1e18;

int p[MAX];
int n, k;
int br1, br2, vel1, vel2;
ll dp[MAXK][MAXK];

ll Rek(int uz1, int uz2)
{
  int poz = vel1 * uz1 + vel2 * uz2;

  if (poz == n)
    return 0;

  if (poz > n)
    return INF;

  if (dp[uz1][uz2] != -1)
    return dp[uz1][uz2];

  ll ret = INF;

  if (uz1 < br1)
    ret = min(ret, Rek(uz1 + 1, uz2) + p[poz + vel1 - 1] - p[poz]);

  if (uz2 < br2)
    ret = min(ret, Rek(uz1, uz2 + 1) + p[poz + vel2 - 1] - p[poz]);

  return dp[uz1][uz2] = ret;
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n);

  vel1 = n / k;
  vel2 = n / k + 1;
  br2 = n % k;
  br1 = k - br2;

  memset(dp, -1, sizeof dp);
  printf("%lld\n", Rek(0, 0));

  return 0;
}