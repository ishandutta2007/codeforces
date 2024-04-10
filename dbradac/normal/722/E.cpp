#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXV = 1<<18, MAXN = 2005, MAXK = 23;
const int MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Inverz(int x)
{
  int ret = 1;
  for (int e = MOD - 2; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);

  return ret;
}

int fak[MAXV], invfak[MAXV];

void GenF()
{
  fak[0] = invfak[0] = 1;
  for (int i=1; i<MAXV; i++) {
    fak[i] = Mul(i, fak[i-1]);
    invfak[i] = Inverz(fak[i]);
  }
}

int Povrh(int a, int b)
{
  if (b < 0 || b > a)
    return 0;
  return Mul(fak[a], Mul(invfak[b], invfak[a-b]));
}

int dp[MAXK][MAXN];
int brred, brstup;
P poz[MAXN];

int Nac(int a, int b)
{
  return Povrh(poz[b].X - poz[a].X + poz[b].Y - poz[a].Y, poz[b].X - poz[a].X);
}

int main()
{
  GenF();

  int n, poc;
  scanf("%d%d%d%d", &brred, &brstup, &n, &poc);

  int imapoc = 0;
  int imakraj = 0;

  for (int i=0; i<n; i++) {
    scanf("%d%d", &poz[i].X, &poz[i].Y);
    if (poz[i] == P(1, 1))
      imapoc = 1;
    if (poz[i] == P(brred, brstup))
      imakraj = 1;
  }

  if (!imapoc)
    poz[n++] = P(1, 1);
  if (!imakraj)
    poz[n++] = P(brred, brstup);

  sort(poz, poz + n);

  dp[0][0] = 1;

  for (int i=1; i<n; i++) {
    for (int k=1; k<MAXK; k++) {
      for (int j=0; j<i; j++) {
        if (poz[j].Y > poz[i].Y)
          continue;

        int koef = Nac(j, i);
        dp[k][i] = Sub(dp[k][i], Mul(koef, dp[k][j]));
        dp[k][i] = Add(dp[k][i], Mul(koef, dp[k-1][j]));
      }
    }

    dp[MAXK-2][i] = Add(dp[MAXK-2][i], dp[MAXK-1][i]);
    dp[MAXK-1][i] = 0;
  }

  int tmp = poc;
  int dod = imapoc + imakraj - 1;
  int rje = 0;

  for (int i=0; i<30; i++, tmp = (tmp + 1) / 2)
    if (i - dod >= 0 && i - dod < MAXK)
      rje = Add(rje, Mul(tmp, dp[i-dod][n-1]));

  printf("%d\n", Mul(rje, Inverz(Nac(0, n-1))));

  return 0;
}