#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7, FI = MOD - 1, FIFI = 500000002;

const int MAX = 1<<18;

int p[MAX];
int pref[MAX], suf[MAX];

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

int Mul(int a, int b, int mod)
{
  return (int) (((llint) a * b) % mod);
}

int Pot(int x, int eksp, int mod)
{
  int ret=1;
  for (; eksp; eksp /= 2, x = Mul(x, x, mod))
    if (eksp & 1)
      ret = Mul(ret, x, mod);
  return ret;
}

int Inv(int x, int mod, int fi)
{
  return Pot(x, fi - 1, mod);
}

int main()
{
  int n;

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    p[tmp]++;
  }

  pref[0] = 1;
  for (int i=1; i<MAX; i++)
    pref[i] = Mul(pref[i-1], p[i] + 1, FI);

  suf[MAX-1] = 1;
  for (int i=MAX-2; i>=0; i--)
    suf[i] = Mul(suf[i+1], p[i] + 1, FI);

  int rje = 1;
  for (int i=0; i<MAX; i++) {
    if (!p[i])
      continue;

    int brput = Mul(pref[i-1], suf[i+1], FI);
    for (int j=1, tmp=i; j<=p[i]; j++, tmp = Mul(tmp, i, MOD))
      rje = Mul(rje, Pot(tmp, brput, MOD), MOD);
  }

  printf("%d\n", rje);

  return 0;
}