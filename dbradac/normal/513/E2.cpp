#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30005, MAXK = 205, INF = 1000000000;

int p[MAXN], sum[MAXN];
int dp[2][4][MAXK][MAXN]; //left/right, 1/-1
int n, k;
int sn[2] = {1, -1};
int sn2[4] = {2, 0, 0, -2};

int Rek(int lr, int st, int kol, int poz)
{
  if (dp[lr][st][kol][poz] != -INF)
    return dp[lr][st][kol][poz];

  if (poz > n) {
    if (kol == k)
      return 0;
    return -INF;
  }

  int ret = Rek(lr, st, kol, poz + 1);

  if (kol < k) {
    int um = 0, zad = st & 1;
    
    if (!kol) um = sn[st&1];
    else if (kol == k - 1) um = sn[(st>>1)&1];
    else um = sn2[st];

    if (lr) {
      ret = max(ret, sum[poz] * um + Rek(0, (zad ^ 1) << 1, kol + 1, poz));
      ret = max(ret, sum[poz] * um + Rek(0, ((zad ^ 1) << 1) + 1, kol + 1, poz));
    }
    else
      ret = max(ret, sum[poz] * (-um) + Rek(1, st, kol, poz + 1));
  }

  return dp[lr][st][kol][poz] = ret;
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    sum[i] = sum[i-1] + p[i];
  }

  for (int i=0; i<2; i++)
    for (int j=0; j<4; j++)
      for (int ii=0; ii<MAXK; ii++)
        for (int jj=0; jj<MAXN; jj++)
          dp[i][j][ii][jj] = -INF;

  printf("%d\n", max(Rek(0, 0, 0, 0), Rek(0, 3, 0, 0)));

  return 0;
}