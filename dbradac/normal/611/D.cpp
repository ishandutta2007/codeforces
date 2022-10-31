#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 5005, MOD = 1e9 + 7, HMOD = 1e9 + 9, H = 3137;

int Add(int a, int b, int mod)
{
  a += b;
  if (a >= mod)
    a -= mod;
  return a;
}

int Sub(int a, int b, int mod)
{
  a -= b;
  if (a < 0)
    a += mod;
  return a;
}

int Mul(int a, int b, int mod)
{
  return (int) (((long long) a * b) % mod);
}

int h[MAX], pot[MAX];
int dp[MAX][MAX];
char s[MAX];

int GetH(int l, int r)
{
  return Sub(h[r], Mul(h[l-1], pot[r-l+1], HMOD), HMOD);
}

int Lcp(int l, int r)
{
  int lo = 0, hi = (r - l);
  for (; lo<hi;) {
    int mid = (lo + hi + 1) / 2;
    if (GetH(l, l + mid - 1) == GetH(r, r + mid - 1))
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

int main()
{
  int n;
  
  scanf("%d%s", &n, s + 1);
  s[0] = '0';
  
  pot[0] = 1;
  for (int i=1; i<MAX; i++)
    pot[i] = Mul(pot[i-1], H, HMOD);

  for (int i=1; i<=n; i++)
    h[i] = Add(Mul(h[i-1], H, HMOD), s[i] - '0' + 1, HMOD);

  dp[0][0] = 1;

  for (int poc=1; poc<=n; poc++) {
    if (s[poc] == '0')
      continue;

    int sum = 0;
    for (int kraj=poc; kraj<=n; kraj++) {
      int da = 0;
      int l = poc - (kraj - poc) - 1;


      if (l >= 0) {
        int lc = Lcp(l, poc);
        if (lc < poc - l && s[poc+lc] > s[l+lc]) {
          da = 1;
          sum = Add(sum, dp[l][poc-1], MOD);
        }
      }
      
      dp[poc][kraj] = Add(dp[poc][kraj], sum, MOD);

      if (l >= 0 && !da)
        sum = Add(sum, dp[l][poc-1], MOD);
    }
  }

  int ret=0;
  for (int i=1; i<=n; i++)
    ret = Add(ret, dp[i][n], MOD);

  printf("%d\n", ret);

  return 0;
}