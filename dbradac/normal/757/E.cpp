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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20;

const int MOD = 1e9 + 7;

int fak[MAX], invfak[MAX];
int dp[MAX][21];

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
  if (a < b || b < 0)
    return 0;
  return mul(fak[a], mul(invfak[b], invfak[a-b]));
}

int sito[MAX];

void gen_sito()
{
  FOR(i, 2, MAX)
    if (!sito[i])
      for (int j=i; j<MAX; j+=i)
        sito[j] = i;
}

vector <int> potencije(int x)
{
  vector <int> R;
  for (; x > 1; ) {
    int tmp = sito[x], kol = 0;
    for (; !(x % tmp); x /= tmp, kol++);
    R.push_back(kol);
  }

  return R;
}

int main()
{
  genfak();
  gen_sito();

  dp[0][0] = 1;
  FOR(j, 1, 21)
    dp[0][j] = 2;

  FOR(i, 1, MAX)
    REP(j, 21)
      REP(k, j+1)
        dp[i][j] = add(dp[i][j], dp[i-1][k]);

  int brq;
  scanf("%d", &brq);

  for (; brq--; ) {
    int x, r;
    scanf("%d%d", &r, &x);

    auto R = potencije(x);
    int rje = 1;
    REP(i, (int) R.size())
      rje = mul(rje, dp[r][R[i]]);

    printf("%d\n", rje);
  }

  return 0;
}