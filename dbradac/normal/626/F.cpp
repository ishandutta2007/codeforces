#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 205, MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int dp[MAX][MAX][1005];
int p[MAX];
int granica, n;

int Rek(int poz, int br, int sum)
{
  if (poz == -1) {
    if (!br && sum <= granica)
      return 1;
    return 0;
  }

  int ind = sum - br * p[poz];
  if (ind > granica)
    return 0;

  if (dp[poz][br][ind] != -1)
    return dp[poz][br][ind];

  int ret = 0;
  ret = Add(ret, Mul(br + 1, Rek(poz - 1, br, sum))); //sam svoj, i s drugima
  ret = Add(ret, Rek(poz - 1, br + 1, sum + p[poz]));
  if (br)
    ret = Add(ret, Mul(br, Rek(poz - 1, br - 1, sum - p[poz])));

  return dp[poz][br][ind] = ret;
}

int main()
{
  memset(dp, -1, sizeof dp);

  scanf("%d%d", &n, &granica);
  
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n);

  printf("%d\n", Rek(n - 1, 0, 0));

  return 0;
}