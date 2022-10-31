#include <cstdio>

typedef long long ll;

const int MOD = 1e9 + 7;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

int Eksp(int b, int e)
{
  int ret=1;

  for (; e; e/=2, b=Mul(b, b))
    if (e & 1)
      ret = Mul(ret, b);

  return ret;
}

int main()
{
  int n;

  scanf("%d", &n);

  printf("%d\n", Sub(Eksp(3, 3 * n), Eksp(7, n)));

  return 0;
}