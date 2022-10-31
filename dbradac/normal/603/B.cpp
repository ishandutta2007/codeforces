#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<20, MOD = 1e9 + 7;

int p, k;
int bio[MAX];

int Add(int a, int b, int mod)
{
  a += b;
  if (a >= mod)
    a -= mod;
  return a;
}


int Mul(int a, int b, int mod)
{
  return (int) (((long long) a * b) % mod);
}

int main()
{
  scanf("%d%d", &p, &k);

  if (k == 0) {
    int ret=1;
    for (int i=1; i<p; i++)
      ret = Mul(ret, p, MOD);

    printf("%d\n", ret);
    return 0;
  }

  int ret=1;
  if (k == 1)
    ret = p;

  for (int i=1; i<p; i++) {
    if (bio[i])
      continue;

    for (int j=i; !bio[j]; j = Mul(j, k, p))
      bio[j] = 1;

    ret = Mul(ret, p, MOD);
  }

  printf("%d\n", ret);

  return 0;
}