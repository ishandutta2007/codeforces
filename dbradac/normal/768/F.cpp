#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18;
const int MOD = 1e9 + 7;

int fak[MAX], invfak[MAX];

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

int divv(int a, int b)
{
  return mul(a, inv(b));
}

void genfak()
{
  fak[0] = invfak[0] = 1;
  for (int i=1; i<MAX; i++) {
    fak[i] = mul(fak[i-1], i);
    invfak[i] = inv(fak[i]);
  }
}

int povrh(int a, int b)
{
  if (a == -1 && b == -1) return 1;
  if (a < b || b < 0)
    return 0;
  return mul(fak[a], mul(invfak[b], invfak[a-b]));
}

int main()
{
  genfak();

  int f, w, h;
  scanf("%d%d%d", &f, &w, &h);

  int dobar = 0, uk = 0;
  FOR(kol, 1, f+w+5) {
    REP(st, 2) {
      int vina = (kol + st) / 2;
      int hrane = (kol + 1 - st) / 2;
      
      uk = add(uk, mul(povrh(w-1, vina-1), povrh(f-1, hrane-1)));
      if ((ll) vina * h <= w)
	dobar = add(dobar, mul(povrh(w - vina * h - 1, vina-1), povrh(f-1, hrane-1)));
    }
  }

  //  TRACE(dobar _ uk);

  printf("%d\n", divv(dobar, uk));

  return 0;
}