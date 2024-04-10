#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MOD = 1e9 + 7;

int add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int pot(int x, int e)
{
  int r = 1;
  for (; e; x = mul(x, x), e /= 2)
    if (e & 1)
      r = mul(r, x);
  return r;
}

int inv(int x)
{
  return pot(x, MOD - 2);
}

int divv(int a, int b) {
  return mul(a, inv(b));
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", mul(pot(2*n+2, m), divv(n+1-m, n+1)));

  return 0;
}