#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int mlen = (int)2e6 + 10;

typedef long double dbl;

char s0[mlen], s[mlen];
int len0, len;

int Solve( ll Ans )
{
  ll f0 = 0, f1 = -(ll)1e18, t0, t1, BONUS = (ll)1e8;
  forn(i, len)
  {
//    printf("Ans=%I64d => (%I64d,%I64d), len=%d (i=%d, ch=%d)\n", Ans, f0, f1, len, i, s[i]);
    if (s[i] == 'X')
      t0 = f1, t1 = f0;
    else if (s[i] == 'L')
    {
//      printf("i=%d, case 2\n", i);
      t0 = max(f1, f0 + BONUS - Ans);
      t1 = max(f0 + BONUS, f1 + BONUS - Ans);
    }
    else if (s[i] == 'R')
    {
//      printf("i=%d, case 3\n", i);
      t0 = max(f1 + BONUS, f0 + BONUS - Ans);
      t1 = max(f0, f1 + BONUS - Ans);
    }
    else
      assert(0);
    f0 = t0, f1 = t1;
  }
//  printf("Ans=%I64d => (%I64d,%I64d), len=%d\n", Ans, f0, f1, len);
  return max(f0, f1 - Ans) >= Ans * len;
}

ll Do()
{
  ll L = 0, R = (ll)1e8, M;
  while (L < R)
    if (Solve(M = (L + R + 1) / 2))
      L = M;
    else
      R = M - 1;
//  printf("%s, %d : %I64d\n", s, len, L);
  return L;
}

int main()
{
  gets(s0), len0 = strlen(s0);
  len = 0;
  forn(i, len0)
  {
    if (i && s0[i] != 'X' && s0[i] == s0[i - 1])
      s[len++] = 'X';
    s[len++] = s0[i];
  }

  ll Ans;
  if (s[0] == 'X' || s[0] != s[len - 1])
    Ans = Do();
  else
  {
    s[len++] = 'X';
    Ans = Do();
    for (int i = len - 1; i > 0; i--)
      s[i] = s[i - 1];
    s[0] = 'X';
    Ans = max(Ans, Do());
  }

  printf("%.6lf\n", (double)(Ans * 1e-6));
  return 0;
}