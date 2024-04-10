#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20, MOD = 1e9 + 7;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Inverz(int x)
{
  int e = MOD - 2, ret = 1;
  for (; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);

  return ret;
}

int n, k;
ll l;
int p[MAX];
vector <int> Dp[MAX];
P sorted[MAX];
ll manje, vise;
int povrh[2][MAX];
int inv[MAX];

void CalcInv()
{
  for (int i=0; i<MAX; i++)
    inv[i] = Inverz(i);
}

void CalcPovrh(ll poc, int polje[MAX])
{
  int tmp = 1;
  polje[0] = 1;
  for (int i=1; i<MAX; i++) {
    tmp = Mul(tmp, Mul(Sub((int) (poc % MOD), i - 1), inv[i]));
    polje[i] = tmp;
  }
}

int Povrh(int st, int b)
{
  ll kol = manje;
  if (st)
    kol = vise;

  if (kol < b)
    return 0;
  return Sub((int) (kol % MOD), b - 1);
}

void GenDp()
{
  for (int i=0; i<n; i++) {
    Dp[i].push_back(1);
    Dp[i].push_back(1);
    for (int j=1; j<=k; j++)
      Dp[i].push_back(0);
  }

  sort(sorted, sorted + n);

  for (int i=2; i<=k; i++) {
    int dosad = 0;
    for (int j=0; j<n;) {
      int poc = j;
      int val = sorted[j].X;
      for (; j < n && sorted[j].X == val; j++)
        dosad = Add(dosad, Dp[sorted[j].Y][i-1]);

      int kraj = j;
      for (j=poc; j < n && sorted[j].X == val; j++)
        Dp[sorted[j].Y][i] = Add(Dp[sorted[j].Y][i], dosad);

      j = kraj;
    }
  }

/*  for (int i=0; i<n; i++) {
    for (int j=1; j<=k; j++)
      printf("%d ", Dp[i][j]);
    printf("\n");
  }*/
}

int Rijesi()
{
  int ret = 0;

  for (int i=0; i<n; i++) {
    for (int j=1; j<=k; j++) {
      int st = 0;
      if (l % n > i)
        st = 1;

     // printf("IJ %d %d   %d   %d %d\n", i, j, st, Dp[i][j], Povrh(st, j));
      ret = Add(ret, Mul(Dp[i][j], Povrh(st, j)));
    }
  }

  return ret;
}

int main()
{
  cin >> n >> l >> k;

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    sorted[i] = P(p[i], i);
  }

  GenDp();
  vise = l / n + 1;
  manje = l / n;

  //CalcInv();
  //CalcPovrh(manje, povrh[0]);
  //CalcPovrh(vise, povrh[1]);

  printf("%d\n", Rijesi());

  return 0;
}