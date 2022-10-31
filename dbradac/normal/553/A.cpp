#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1005, MOD = 1e9 + 7;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int n;
int p[MAX];
int sump[MAX];
int dp[MAX][MAX];
int fak[MAX];

int Inverz(int x)
{
  int ret=1;
  for (int eksp=MOD-2; eksp; eksp>>=1, x = Mul(x, x))
    if (eksp & 1)
      ret = Mul(ret, x);

  return ret;
}

int Povrh(int a, int b)
{
  if (a < b)
    return 0;
  return Mul(fak[a], Mul(Inverz(fak[b]), Inverz(fak[a-b])));
}

int Rek(int jos, int indc, int vel)
{
  if (dp[jos][indc] != -1)
    return dp[jos][indc];

  if (!jos)
    return 1;

  int ret = 0;
  if (vel)
    ret = Add(ret, Rek(jos - 1, indc, vel - 1));

  if (indc <= n)
    ret = Add(ret, Mul(Rek(jos - 1, indc + 1, vel + p[indc] - 1), Povrh(vel + p[indc] - 1, p[indc] - 1)));

  return dp[jos][indc] = ret;
}

int main()
{
  scanf("%d", &n);
  
  fak[0] = 1;
  for (int i=1; i<MAX; i++)
    fak[i] = Mul(i, fak[i-1]);

  int sum=0;
  for (int i=n; i; i--) {
    scanf("%d", &p[i]);
    sum += p[i];
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", Rek(sum - 1, 2, p[1] - 1));
 
  return 0;
}