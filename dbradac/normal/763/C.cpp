#include <cstdio>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20;

int MOD;
int p[MAX];
map <int, int> M;

int st = 0;

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

int n;
void check(int poc, int raz)
{
  int des = 0;
  for (int i=0, tmp=poc; ; tmp = add(tmp, raz), i++) {
    if (!M[tmp]) break;
    des++;
  }

  int lev = 0;
  for (int tmp=poc; ;tmp=sub(tmp, raz)) {
    if (!M[tmp]) break;
    lev++;

  }

  if (lev + des == n + 1) {
    if (st == 0) printf("%d %d\n", sub(poc, mul(raz, lev-1)), raz);
    else {
      int tmp = add(poc, mul(raz, des));
      printf("%d %d\n", tmp, raz);
    }
    exit(0);
  }

}

int main()
{
  scanf("%d%d", &MOD, &n);
  REP(i, n) { scanf("%d", &p[i]); M[p[i]] = 1; }

  if (n == 1 || n == MOD) {
    printf("%d %d\n", p[0], 1);
    return 0;
  }

  if (n > MOD - n) {
    st = 1;
    n = 0;
    REP(i, MOD) if (!M[i]) p[n++] = i;
    M.clear();
    REP(i, n) M[p[i]] = 1;
  }

  random_shuffle(p, p + n);

  REP(i, n) M[p[i]] = 1;
  if (n == 1) { printf("%d %d\n", add(p[0], 1), 1); return 0; }

  REP(i, 2) {
    REP(j, n) {
      if (i != j) {
        int raz = sub(p[j], p[i]);
        check(p[i], raz);
      }
    }
  }

  printf("-1\n");

  return 0;
}