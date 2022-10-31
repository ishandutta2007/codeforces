#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1005, MAXM = 105;

int mod;

int Add(int a, int b, int m)
{
  return (a + b) % m;
}

int Mul(int a, int b, int m)
{
  return (int) (((ll) a * b) % m);
}

int dp[2][MAXN][MAXM];
int zav[MAXN];

int main()
{
  int n, k;

  scanf("%d%d%d", &n, &k, &mod);

  zav[0] = 1;
  for (int i=1, tmp=1; i<MAXN; i++) {
    zav[i] = Mul(tmp, 9, mod);
    tmp = Mul(tmp, 10, mod);
  }

  dp[0][0][0] = 1;
  int pot = 1, rje=0;

  for (int i=0; i<=n; i++, pot = Mul(pot, 10, k)) {
    for (int z=0; z<2; z++) {
      int j=1;
      if (!i || !z) j = 0;
      for (; j<k; j++) {
        for (int l=0; l<10; l++) {
          int nost = Add(j, Mul(l, pot, k), k), nz=0;
          if (l) nz = 1;
          dp[nz][i+1][nost] = Add(dp[nz][i+1][nost], dp[z][i][j], mod);
        }
      }
    }

    if (i) {
      rje = Add(rje, Mul(dp[1][i][0], zav[n-i], mod), mod);
    }
  }

  printf("%d\n", rje);

  return 0;
}