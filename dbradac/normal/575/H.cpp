#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<21, MOD = (1e9) + 7;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Inv(int b)
{
  int ret = 1;
  for (int e = MOD - 2; e; e /= 2, b = Mul(b, b))
    if (e & 1)
      ret = Mul(ret, b);

  return ret;
}

int fak[MAX], invfak[MAX];

void GenFak()
{
  fak[0] = 1;
  for (int i=1; i<MAX; i++)
    fak[i] = Mul(fak[i-1], i);
}

int Povrh(int n, int k)
{
  return Mul(fak[n], Mul(Inv(fak[k]), Inv(fak[n-k])));
}

int main()
{
  int n;
  
  scanf("%d", &n);

  GenFak();

  printf("%d\n", Add(MOD - 1, Povrh(2 * (n + 1), n + 1)));

  return 0;
}